#ifndef _CGBITMAP_
#define _CGBITMAP_

#define CG_TRANSPARENT 0

#include "cgSize.h"
#include "cgCoord.h"
#include <windows.h>

class cgBitmap
{
public:
    cgSize size;
    CHAR_INFO* bufor;

    cgBitmap( cgSize s );
    ~cgBitmap();

    void saveToFile( char* path );
    void readFromFile( char* path );
    void fill( CHAR_INFO );
    void addRect( cgCoordi rPosition, cgSize rSize, CHAR_INFO char_i );
    void addFilledRect( cgCoordi rPosition, cgSize rSize, CHAR_INFO char_i );
    void addPixel( cgCoordi position, CHAR_INFO char_i );
    cgBitmap getPart( cgCoordi bitmapSource, cgSize bitmapSize );
    void copyToBitmap( cgBitmap &destiny, cgCoordi cpPoint );
    void print( cgCoordi cpPoint );
};


#endif // _CGBITMAP_
