#ifndef _CGBITMAP_
#define _CGBITMAP_

#include "cgSize.h"
#include "cgVector.h"
#include "cgPixelEdit.h"
#include <windows.h>
#include <iostream>

#define CG_TRANSPARENT_CHAR     0
#define CG_VERTICAL     0
#define CG_HORIZONTAL   1
#define CG_LEFT         -1
#define CG_RIGHT        1

class cgBitmap
{
private:
    //cgSizeInt& _size;

public:
    cgSizeInt size;
    cgPixel* bufor;

    cgBitmap();
    cgBitmap( const cgBitmap& bmp );
    cgBitmap( cgSizeInt s );
    cgBitmap( char* path );
    ~cgBitmap();

    bool saveToFile( char* path );
    bool loadFromFile( char* path );
    template <typename T> bool contain( cgVector<T> point );
    void fill( cgPixel );
    void addRectByPoints( cgVectorInt a, cgVectorInt b, cgPixel char_i, bool filled );
    void addRectByOrigin( cgVectorInt rOrigin, cgSizeInt rSize, cgPixel char_i, bool filled );
    void addLineByPoints( cgVectorInt a, cgVectorInt b, cgPixel char_i );
    void addLineByOrigin( cgVectorInt origin, cgVectorInt vector, cgPixel char_i );
    void addPixel( cgVectorInt position, cgPixel char_i );
    void copyToBitmap( cgBitmap &destination, cgVectorInt cpPoint );
    cgBitmap getPartByPoints(cgVectorInt a, cgVectorInt b );
    cgBitmap getPartByOrigin(cgVectorInt rOrigin, cgSizeInt rSize );
    void flip( bool VorH );
    void rotate( unsigned direction, int rotations );
    void print( cgVectorInt cpPoint );


    cgBitmap& operator = ( cgBitmap &bmp )
    {
        delete[] bufor;
        size = bmp.size;
        if ( size.width * size.height > 0 )
        {
            bufor = new cgPixel[ size.width * size.height ];
            for (int i(0); i<(size.width * size.height); i++)
            {
                bufor[i] = bmp.bufor[i];
            }
        }
        return *this;
    }
};


#endif // _CGBITMAP_
