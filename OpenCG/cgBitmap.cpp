#include "cgBitmap.h"
#include <iostream>
#include <algorithm>
#include "cgWindow.h"
#include <vector>
#include <string>
#include <tinyxml.h>
#include <math.h>

cgBitmap::cgBitmap( cgSizeInt s )
{
    size = s;
    bufor = new cgPixel[ size.width * size.height ];
}


cgBitmap::~cgBitmap()
{
    delete[] bufor;
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


bool cgBitmap::readFromFile( char* path )
{
    delete[] bufor;

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

}


void cgBitmap::fill( cgPixel char_i )
{
    int a( size.width * size.height );
    for( int i(0); i<a; i++ )
    {
        bufor[i] = char_i;
    }
}


void cgBitmap::addRect( cgVectorInt rPosition, cgSizeInt rSize, cgPixel char_i )
{
    int ax( std::max(0,rPosition.x) );
    int ay( std::max(0,rPosition.y) );
    int ix( std::min(rPosition.x+rSize.width, size.width) );
    int iy( std::min(rPosition.y+rSize.height, size.height) );
    int tempj;


    if ( ay == rPosition.y )
        for ( int i(ax); i<ix; i++ )
        {
            bufor[ ay*size.width + i ] = char_i;
        }


    if ( iy == rPosition.y+rSize.height )
        for ( int i(ax); i<ix; i++ )
        {
            bufor[ (iy-1)*size.width + i ] = char_i;
        }


    if ( ax == rPosition.x )
        for ( int i(ay); i<iy; i++ )
        {
            bufor[ i*size.width + ax ] = char_i;
        }


    if ( ix == rPosition.y+rSize.height )
        for ( int i(ay); i<iy; i++ )
        {
            bufor[ i*size.width + (ix-1) ] = char_i;
        }

}


void cgBitmap::addFilledRect( cgVectorInt rPosition, cgSizeInt rSize, cgPixel char_i )
{
    int ax = std::max(0,rPosition.x);
    int ay = std::max(0,rPosition.y);
    int ix = std::min(rPosition.x+rSize.width, size.width);
    int iy = std::min(rPosition.y+rSize.height, size.height);
    int tempj;

    for ( int j(ay); j<iy; j++ )
    {
        tempj = j*size.width;
        for ( int i(ax); i<ix; i++ )
        {
            bufor[i+tempj] = char_i;
        }
    }
}


void cgBitmap::addPixel( cgVectorInt position, cgPixel char_i )
{
    if ( position.x < size.width && position.x >= 0 && position.y < size.height && position.y >= 0 )
    {
        bufor[position.x + position.y*size.width ] = char_i;
    }
}


void cgBitmap::copyToBitmap( cgBitmap &destiny, cgVectorInt cpPoint )
{
    if ( cpPoint.x+size.width <= 0 ||
         cpPoint.x >= destiny.size.width ||
         cpPoint.y+size.height < 0 ||
         cpPoint.y >= destiny.size.height )
    return;


    int startx = std::max(0,cpPoint.x);
    int starty = std::max(0,cpPoint.y);
    int finx = std::min(cpPoint.x+size.width, destiny.size.width);
    int finy = std::min(cpPoint.y+size.height, destiny.size.height);
    int copytoY;
    int copyfromY;
    int copyto;
    int copyfrom;

    for ( int j(starty); j<finy; j++ )
    {
        copytoY = j*destiny.size.width;
        copyfromY = (j-cpPoint.y)*size.width;

        for ( int i(startx); i<finx; i++ )
        {
            copyto = i+copytoY;
            copyfrom = i-cpPoint.x + copyfromY;

            if( bufor[copyfrom].Char.AsciiChar != CG_TRANSPARENT_CHAR )
            {
                destiny.bufor[ copyto ] = bufor[ copyfrom ];
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
        {   // x = 0
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
        {   // x = max
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
        {   // y = 0
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
        {   // y = max
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
