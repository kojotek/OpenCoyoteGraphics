#ifndef _CGBITMAP_
#define _CGBITMAP_

#include "cgSize.h"
#include "cgVector.h"
#include "cgPixelEdit.h"
#include <windows.h>

#define CG_TRANSPARENT_CHAR     0

class cgBitmap
{
public:
    cgSizeInt size;
    cgPixel* bufor;

    cgBitmap( cgSizeInt s );
    ~cgBitmap();

    bool saveToFile( char* path );
    bool readFromFile( char* path );
    template <typename T> bool contain( cgVector<T> point );
    void fill( cgPixel );
    void addRect( cgVectorInt rPosition, cgSizeInt rSize, cgPixel char_i );
    void addFilledRect( cgVectorInt rPosition, cgSizeInt rSize, cgPixel char_i );
    void addLineByPoints( cgVectorInt a, cgVectorInt b, cgPixel char_i );
    void addLineByOrigin( cgVectorInt origin, cgVectorInt vector, cgPixel char_i );
    void addPixel( cgVectorInt position, cgPixel char_i );
    void copyToBitmap( cgBitmap &destination, cgVectorInt cpPoint );
    void print( cgVectorInt cpPoint );
};


#endif // _CGBITMAP_
