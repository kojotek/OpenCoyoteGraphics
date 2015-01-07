#include "cgBitmap.h"
#include <iostream>
#include <algorithm>
#include "cgWindow.h"
#include <vector>
#include <string>
#include <tinyxml.h>
#include <math.h>


cgBitmap::cgBitmap()
{
    size = cgSizeInt(0,0);
    bufor = NULL;
}



cgBitmap::cgBitmap( const cgBitmap& bmp )
{
    size = bmp.size;
    bufor = NULL;
    if ( size.width * size.height > 0 )
    {
        bufor = new cgPixel[ size.width * size.height ];
        for (int i(0); i<(size.width * size.height); i++)
        {
            bufor[i] = bmp.bufor[i];
        }
    }
}



cgBitmap::cgBitmap( cgSizeInt s )
{
    size = s;
    bufor = NULL;
    if ( size.width * size.height > 0 )
    {
        bufor = new cgPixel[ size.width * size.height ];
    }
}



cgBitmap::cgBitmap( char* path )
{
    bufor = NULL;
    loadFromFile( path );
}



cgBitmap::~cgBitmap()
{
    delete[] bufor;
    bufor = NULL;
}



bool cgBitmap::saveToFile( char* path )
{

    TiXmlDocument* doc = new TiXmlDocument();
    TiXmlDeclaration* declaration = new TiXmlDeclaration( "1.0", "UTF-8", "yes" );

    TiXmlElement * root = new TiXmlElement( "bitmap" );
    root->SetAttribute( "width", size.width );
    root->SetAttribute( "height", size.height );


    for ( int h(0); h < size.height; h++ )
    {
        TiXmlElement * line = new TiXmlElement( "line" );

        for (int w(0); w < size.width; w++ )
        {
            TiXmlElement * chr = new TiXmlElement( "char" );
            chr->SetAttribute( "ascii", bufor[ w + h * size.width ].Char.AsciiChar );
            chr->SetAttribute( "attribute", bufor[ w + h * size.width ].Attributes );
            line->LinkEndChild( chr );
        }
        root->LinkEndChild( line );
    }

    doc->LinkEndChild( declaration );
    doc->LinkEndChild( root );

    bool result = false;
    if( doc->SaveFile( path ) )
    {
        result = true;
    }

    doc->Clear();

    return result;

}



bool cgBitmap::loadFromFile( char* path )
{

    if( bufor != NULL )
    {
        delete[] bufor;
        bufor = NULL;
    }

    TiXmlDocument doc;
    if( !doc.LoadFile(path) )
    {
        return false;
    }
    else
    {

        TiXmlElement* root = doc.FirstChildElement();
        if(root == NULL)
        {
            doc.Clear();
            return false;
        }

        root->Attribute( "width", &size.width );
        root->Attribute( "height", &size.height );
        bufor = new cgPixel[ size.width * size.height ];


        int position = 0;

        std::string elementName;
        for ( TiXmlElement *iter = root->FirstChildElement(); iter != NULL; iter = iter->NextSiblingElement() )
        {
            elementName = iter->Value();
            if( elementName == "line" )
            {
                for ( TiXmlElement *iter2 = iter->FirstChildElement(); iter2 != NULL; iter2 = iter2->NextSiblingElement() )
                {
                    elementName = iter2->Value();
                    if( elementName == "char" )
                    {
                        int ascii;
                        int attrib;

                        iter2->Attribute("ascii", &ascii);
                        iter2->Attribute("attribute", &attrib);

                        bufor[position].Char.AsciiChar = ascii;
                        bufor[position].Attributes = attrib ;

                        position++;
                    }
                }
            }
        }

        doc.Clear();

    }

    return true;
}



void cgBitmap::fill( cgPixel char_i )
{
    int a( size.width * size.height );
    for( int i(0); i<a; i++ )
    {
        bufor[i] = char_i;
    }
}



void cgBitmap::addRectByPoints( cgVectorInt a, cgVectorInt b, cgPixel char_i, bool filled )
{

    if ( b.x < a.x )
    {
        cgVectorInt temp(a);
        a.x = b.x;
        b.x = temp.x ;
    }

    if ( b.y < a.y )
    {
        cgVectorInt temp(a);
        a.y = b.y;
        b.y = temp.y;
    }

    int signx = copysign( 1.0f, b.x - a.x );
    int signy = copysign( 1.0f, b.y - a.y );

    b.x += signx;
    b.y += signy;

    int ax( std::max(a.x, 0) );
    int ay( std::max(a.y, 0) );
    int bx( std::min(b.x, size.width) );
    int by( std::min(b.y, size.height) );
    int tempj;

    if(filled)
    {

        for ( int j(ay); j<by; j++ )
        {
            tempj = j*size.width;
            for ( int i(ax); i<bx; i++ )
                bufor[i+tempj] = char_i;
        }

    }
    else
    {

        if ( ay == a.y )
            for ( int i(ax); i<bx; i++ )
                bufor[ ay*size.width + i ] = char_i;

        if (by == b.y )
            for ( int i(ax); i<bx; i++ )
                bufor[ (by-1)*size.width + i ] = char_i;

        if ( ax == a.x )
            for ( int i(ay); i<by; i++ )
                bufor[ i*size.width + ax ] = char_i;

        if ( bx == b.x )
            for ( int i(ay); i<by; i++ )
                bufor[ i*size.width + (bx-1) ] = char_i;

    }

}


void cgBitmap::addRectByOrigin( cgVectorInt rOrigin, cgSizeInt rSize, cgPixel char_i, bool filled )
{
    if ( rSize.width != 0 && rSize.height != 0 )
    {
        int signx = -copysign( 1.0f, rSize.width );
        int signy = -copysign( 1.0f, rSize.height );
        addRectByPoints( rOrigin, cgVectorInt( rOrigin.x + rSize.width + signx, rOrigin.y + rSize.height + signy ), char_i, filled );
    }
}


void cgBitmap::addPixel( cgVectorInt position, cgPixel char_i )
{
    if ( contain(position) )
    {
        bufor[position.x + position.y*size.width ] = char_i;
    }
}



void cgBitmap::copyToBitmap( cgBitmap &destination, cgVectorInt cpPoint )
{
    if ( cpPoint.x+size.width <= 0 ||
            cpPoint.x >= destination.size.width ||
            cpPoint.y+size.height < 0 ||
            cpPoint.y >= destination.size.height )
        return;


    int startx = std::max(0,cpPoint.x);
    int starty = std::max(0,cpPoint.y);
    int finx = std::min(cpPoint.x+size.width, destination.size.width);
    int finy = std::min(cpPoint.y+size.height, destination.size.height);
    int copytoY;
    int copyfromY;
    int copyto;
    int copyfrom;

    for ( int j(starty); j<finy; j++ )
    {
        copytoY = j*destination.size.width;
        copyfromY = (j-cpPoint.y)*size.width;

        for ( int i(startx); i<finx; i++ )
        {
            copyto = i+copytoY;
            copyfrom = i-cpPoint.x + copyfromY;

            if( bufor[copyfrom].Char.AsciiChar != CG_TRANSPARENT_CHAR )
            {
                destination.bufor[ copyto ] = bufor[ copyfrom ];
            }
        }
    }
}



void cgBitmap::print( cgVectorInt cpPoint )
{
    COORD charBufSize = {cgWindow::size.width, cgWindow::size.height};
    COORD characterPos = {0,0};
    SMALL_RECT writeArea = {cpPoint.x, cpPoint.y, cpPoint.x+cgWindow::size.width-1, cpPoint.y+cgWindow::size.height-1};
    WriteConsoleOutputA(cgWindow::outputHandle, bufor, charBufSize, characterPos, &writeArea);
}



template <typename T> bool cgBitmap::contain( cgVector<T> point )
{
    return ( point.x >= 0 && point.x <= size.width-1 && point.y >= 0 && point.y <= size.height-1 );
}



void cgBitmap::addLineByPoints( cgVectorInt pointa, cgVectorInt pointb, cgPixel char_i )
{

    float deltax = pointb.x - pointa.x;
    float deltay = pointb.y - pointa.y;

    float xShift;
    float yShift;
    cgVectorFloat newPosition;


    if (deltax == 0)
    {
        pointa.y = std::min( std::max( pointa.y, 0 ), size.height-1 );
        pointb.y = std::min( std::max( pointb.y, 0 ), size.height-1 );
    }

    if (deltay == 0)
    {
        pointa.x = std::min( std::max( pointa.x, 0 ), size.height-1 );
        pointb.x = std::min( std::max( pointb.x, 0 ), size.height-1 );
    }


    cgVectorFloat a(pointa.x, pointa.y);
    cgVectorFloat b(pointb.x, pointb.y);
    cgVectorFloat* tab[] = {&a,&b};

    for (int i(0); i<2; i++ )                           //przycinam a i b, zeby nie rysowaly poza polem rysowania
    {
        cgVectorFloat& point(*tab[i]);

        if ( !contain(point) && point.x < 0 )
        {
            // x = 0
            xShift = -point.x;
            yShift = xShift * (deltay / deltax);
            newPosition = cgVectorFloat(point.x, point.y) + cgVectorFloat(xShift, yShift);
            if ( contain(newPosition) )
            {
                point.x = newPosition.x;
                point.y = newPosition.y;
            }
        }
        if ( !contain(point) && point.x >= size.width )
        {
            // x = max
            xShift = size.width - 1 - point.x;
            yShift = xShift * (deltay / deltax);
            newPosition = cgVectorFloat(point.x, point.y) + cgVectorFloat(xShift, yShift);
            if ( contain(newPosition) )
            {
                point.x = newPosition.x;
                point.y = newPosition.y;
            }
        }
        if ( !contain(point) && point.y < 0 )
        {
            // y = 0
            yShift = -point.y;
            xShift = yShift * (deltax / deltay);
            newPosition = cgVectorFloat(point.x, point.y) + cgVectorFloat(xShift, yShift);
            if ( contain(newPosition) )
            {
                point.x = newPosition.x;
                point.y = newPosition.y;
            }
        }
        if ( !contain(point) && point.y >= size.height )
        {
            // y = max
            yShift = size.height - 1 - point.y;
            xShift = yShift * (deltax / deltay);
            newPosition = cgVectorFloat(point.x, point.y) + cgVectorFloat(xShift, yShift);
            if ( contain(newPosition) )
            {
                point.x = newPosition.x;
                point.y = newPosition.y;
            }
        }
    }



    int sgnx = copysign(1.0f, pointb.x-pointa.x );      //dodaje tutaj koncowy, ucinany znak
    int sgny = copysign(1.0f, pointb.y-pointa.y );
    pointa.x = a.x;
    pointa.y = a.y;
    pointb.x = b.x + sgnx;
    pointb.y = b.y + sgny;

    deltax = pointb.x - pointa.x;
    deltay = pointb.y - pointa.y;


    if ( deltax != 0.0f )
    {
        float error = 0;
        float deltaerr = fabs(deltay / deltax);
        int y = pointa.y;

        int sign = copysign(1.0f, pointb.x-pointa.x );
        for ( int x(pointa.x); sign*(pointb.x-x)>0; x += sign )
        {
            bufor[ x + y*size.width ] = char_i;
            error = error + deltaerr;
            while ( error >= 0.5f )
            {
                bufor[ x + y*size.width ] = char_i;
                y += copysign( 1, pointb.y - pointa.y );
                error = error - 1.0f;
            }
        }
    }
    else
    {
        int sign = copysign(1.0f, pointb.y-pointa.y );
        for ( int y(pointa.y); abs(pointb.y-y)>0; y += sign )
        {
            bufor[ pointa.x + y*size.width ] = char_i;
        }
    }

}



void cgBitmap::addLineByOrigin( cgVectorInt origin, cgVectorInt vector, cgPixel char_i )
{
    addLineByPoints( origin, origin+vector, char_i );
}



cgBitmap cgBitmap::getPartByPoints(cgVectorInt a, cgVectorInt b )
{

    if ( b.x < a.x )
    {
        cgVectorInt temp(a);
        a.x = b.x;
        b.x = temp.x ;
    }

    if ( b.y < a.y )
    {
        cgVectorInt temp(a);
        a.y = b.y;
        b.y = temp.y;
    }

    b += cgVectorInt(1,1);


    cgBitmap result( cgSizeInt( b.x-a.x, b.y-a.y ) );

    result.fill( cgPixelEdit::createPixel( CG_TRANSPARENT_CHAR, 0, 0 ) );
    copyToBitmap( result, cgVectorInt(-a.x, -a.y) );
    return result;
}



cgBitmap cgBitmap::getPartByOrigin( cgVectorInt rOrigin, cgSizeInt rSize )
{
    if ( rSize.width != 0 && rSize.height != 0 )
    {
        int signx = -copysign( 1.0f, rSize.width );
        int signy = -copysign( 1.0f, rSize.height );
        return getPartByPoints( rOrigin, cgVectorInt( rOrigin.x + rSize.width + signx , rOrigin.y + rSize.height + signy ) );
    }

    cgBitmap result;
    return result;
}



void cgBitmap::flip(bool axis)
{
    cgPixel* temp = new cgPixel[ size.width * size.height ];

    if( axis == CG_HORIZONTAL )
    {
        for (int y(0); y < size.height; y++ )
        {
            for (int x(0); x < size.width; x++ )
            {
                temp[ x + y*size.width ] = bufor[ (size.width-1-x) + y*size.width ];
            }
        }
    }

    else
    {
        for (int y(0); y < size.height; y++ )
        {
            for (int x(0); x < size.width; x++ )
            {
                temp[ x + y*size.width ] = bufor[ x + (size.height-1-y)*size.width ];
            }
        }
    }

    delete[] bufor;
    bufor = temp;

}



void cgBitmap::rotate( unsigned direction, int rotations )
{
    int position = (direction * rotations) % 4;

    switch (position)
    {
        case 0:
            break;

        case 1:
        {
            size = cgSizeInt( size.height, size.width );
            cgPixel* temp = new cgPixel[ size.width * size.height ];

            for (int y(0); y < size.height; y++ )
            {
                for (int x(0); x < size.width; x++ )
                {
                    temp[ x + y*size.width ] = bufor[ y + (size.width-1-x)*size.height ];
                }
            }

            delete[] bufor;
            bufor = temp;
            break;
        }

        case 2:
        {
            size = cgSizeInt( size.height, size.width );
            cgPixel* temp = new cgPixel[ size.width * size.height ];

            for (int y(0); y < size.height; y++ )
            {
                for (int x(0); x < size.width; x++ )
                {
                    temp[ x + y*size.width ] = bufor[ (size.height-1-y) + (size.width-1-x)*size.height ];
                }
            }

            delete[] bufor;
            bufor = temp;
            break;
        }

        case 3:
        {
            size = cgSizeInt( size.height, size.width );
            cgPixel* temp = new cgPixel[ size.width * size.height ];

            for (int y(0); y < size.height; y++ )
            {
                for (int x(0); x < size.width; x++ )
                {
                    temp[ x + y*size.width ] = bufor[ (size.height-1-y) + x*size.height ];
                }
            }

            delete[] bufor;
            bufor = temp;
            break;
        }



    }
}
