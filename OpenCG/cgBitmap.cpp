#include "cgBitmap.h"
#include <iostream>
#include <algorithm>
#include "cgWindow.h"

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

}


void cgBitmap::addFilledRect( cgCoordi rPosition, cgSize rSize, CHAR_INFO char_i )
{
    rPosition.x = std::max(0,rPosition.x);
    rPosition.y = std::max(0,rPosition.y);
    int ix = std::min(rPosition.x+rSize.width, size.width);
    int iy = std::min(rPosition.y+rSize.height, size.height);
    int tempj;

    for ( int j(rPosition.y); j<iy; j++ )
    {
        tempj = j*size.width;
        for ( int i(rPosition.x); i<ix; i++ )
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
