#include "cgBitmap.h"
#include <iostream>

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

}


void cgBitmap::addPixel( cgCoordi position, CHAR_INFO char_i )
{

}


cgBitmap cgBitmap::getPart( cgCoordi bitmapSource, cgSize bitmapSize )
{

}


void cgBitmap::copyToBitmap( cgBitmap &destiny, cgCoordi cpPoint )
{

}


void cgBitmap::print( cgCoordi cpPoint )
{

}
