#include "cgBitmap.h"
#include <iostream>
#include <algorithm>
#include "cgWindow.h"
#include <vector>
#include <tinyxml.h>

cgBitmap::cgBitmap( cgSize s )
{
    size = s;
    bufor = new CHAR_INFO[ size.width * size.height ];
}


cgBitmap::~cgBitmap()
{
    delete[] bufor;
}


void cgBitmap::saveToFile( char* path )
{
    std::vector<TiXmlNode*> nodes;

    TiXmlDocument* doc = new TiXmlDocument();
    nodes.push_back( doc );
    TiXmlDeclaration* declaration = new TiXmlDeclaration( "1.0", "UTF-8", "yes" );
    nodes.push_back( declaration );

    TiXmlElement * root = new TiXmlElement( "bitmap" );
    nodes.push_back( root );
        root->SetAttribute( "width", size.width );
        root->SetAttribute( "height", size.height );


    for ( int h(0); h < size.height; h++ )
    {
        TiXmlElement * line = new TiXmlElement( "line" );
        nodes.push_back(line);

        for (int w(0); w < size.width; w++ )
        {
            TiXmlElement * chr = new TiXmlElement( "char" );
            nodes.push_back(chr);
                chr->SetAttribute( "ascii", bufor[ w + h * size.width ].Char.AsciiChar );
                chr->SetAttribute( "attribute", bufor[ w + h * size.width ].Attributes );
            line->LinkEndChild( chr );
        }
        root->LinkEndChild( line );
    }

    doc->LinkEndChild( declaration );
    doc->LinkEndChild( root );
    doc->SaveFile( path );

    for( int a( nodes.size()-1 ); a >= 0; a-- )
    {
        nodes[a]->Clear();
    }
}


void cgBitmap::readFromFile( char* path )
{

}


void cgBitmap::fill( CHAR_INFO char_i )
{
    int a( size.width * size.height );
    for( int i(0); i<a; i++ )
    {
        bufor[i] = char_i;
    }
}


void cgBitmap::addRect( cgCoordi rPosition, cgSize rSize, CHAR_INFO char_i )
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


void cgBitmap::addFilledRect( cgCoordi rPosition, cgSize rSize, CHAR_INFO char_i )
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


void cgBitmap::addPixel( cgCoordi position, CHAR_INFO char_i )
{
    if ( position.x < size.width && position.x >= 0 && position.y < size.height && position.y >= 0 )
    {
        bufor[position.x + position.y*size.width ] = char_i;
    }
}


void cgBitmap::copyToBitmap( cgBitmap &destiny, cgCoordi cpPoint )
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

            if( bufor[copyfrom].Attributes != CG_TRANSPARENT )
            {
                destiny.bufor[ copyto ] = bufor[ copyfrom ];
            }
        }
    }
}


void cgBitmap::print( cgCoordi cpPoint )
{
    COORD charBufSize = {cgWindow::size.width, cgWindow::size.height};
    COORD characterPos = {0,0};
    SMALL_RECT writeArea = {cpPoint.x, cpPoint.y, cpPoint.x+cgWindow::size.width-1, cpPoint.y+cgWindow::size.height-1};
    WriteConsoleOutputA(cgWindow::outputHandle, bufor, charBufSize, characterPos, &writeArea);
}
