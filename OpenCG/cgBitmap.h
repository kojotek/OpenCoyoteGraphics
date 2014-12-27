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
    cgSize size;
    cgPixel* bufor;

    cgBitmap( cgSize s );
    ~cgBitmap();

    bool saveToFile( char* path );
    bool readFromFile( char* path );
    void fill( cgPixel );
    void addRect( cgVectorInt rPosition, cgSize rSize, cgPixel char_i );
    void addFilledRect( cgVectorInt rPosition, cgSize rSize, cgPixel char_i );
    void addPixel( cgVectorInt position, cgPixel char_i );
    void copyToBitmap( cgBitmap &destiny, cgVectorInt cpPoint );
    void print( cgVectorInt cpPoint );
};


#endif // _CGBITMAP_
