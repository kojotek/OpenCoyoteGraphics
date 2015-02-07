#ifndef _CGPIXEL_
#define _CGPIXEL_

#include <windows.h>
#include "cgColors.h"

class cgPixel
{
private:
    CHAR_INFO pixelInfo;

public:
    cgPixel( CHAR asciiChar, WORD backgroundColor, WORD foregroundColor );
    cgPixel( WORD color );
    cgPixel( CHAR_INFO char_info );
    cgPixel();
    void setFrontClr( WORD foregroundColor );
    void setBckClr( WORD backgroundColor );
    void setAscii( CHAR asciiChar );
    WORD getFrontClr();
    WORD getBckClr();
    char getAscii();
    CHAR_INFO getCharInfo();
    void setCharInfo( CHAR_INFO char_i );
};

#endif // _CGPIXELEDIT_
