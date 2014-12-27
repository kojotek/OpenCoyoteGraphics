#ifndef _CGPIXELEDIT_
#define _CGPIXELEDIT_

#include <windows.h>

#define CG_COLOR_BLACK          0
#define CG_COLOR_BLUE           1
#define CG_COLOR_GREEN          2
#define CG_COLOR_CYAN           3
#define CG_COLOR_RED            4
#define CG_COLOR_MAGENTA        5
#define CG_COLOR_YELLOW         6
#define CG_COLOR_LIGHT_GREY     7

#define CG_COLOR_GREY           8
#define CG_COLOR_LIGHT_BLUE     9
#define CG_COLOR_LIGHT_GREEN    10
#define CG_COLOR_LIGHT_CYAN     11
#define CG_COLOR_LIGHT_RED      12
#define CG_COLOR_LIGHT_MAGENTA  13
#define CG_COLOR_LIGHT_YELLOW   14
#define CG_COLOR_WHITE          15



typedef CHAR_INFO cgPixel;


class cgPixelEdit
{
public:
    static cgPixel createPixel( CHAR asciiChar, WORD foregroundColor, WORD backgroundColor );
    static cgPixel createPixel( WORD color );
    static void setForegroundColor( cgPixel& charInfo, WORD foregroundColor );
    static void setBackgroundColor( cgPixel& charInfo, WORD backgroundColor );
    static void setAsciiChar( cgPixel& charInfo, CHAR asciiChar );
};

#endif // _CGPIXELEDIT_
