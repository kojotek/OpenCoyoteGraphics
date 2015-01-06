#ifndef __CGWINDOW__
#define __CGWINDOW__

//DEFINES/////////////////////////////////
#define CG_FONT_SIZE_4X6 cgSizeInt(4,6)
#define CG_FONT_SIZE_6X8 cgSizeInt(6,8)
#define CG_FONT_SIZE_8X8 cgSizeInt(8,8)
#define CG_FONT_SIZE_16X8 cgSizeInt(16,8)
#define CG_FONT_SIZE_5X12 cgSizeInt(5,12)
#define CG_FONT_SIZE_7X12 cgSizeInt(7,12)
#define CG_FONT_SIZE_8X12 cgSizeInt(8,12)
#define CG_FONT_SIZE_16X12 cgSizeInt(16,12)
#define CG_FONT_SIZE_12X16 cgSizeInt(12,16)
#define CG_FONT_SIZE_10X18 cgSizeInt(10,18)
//DEFINES/////////////////////////////////

#include <stdlib.h>
#include <Windows.h>
#include <Tchar.h>
#include "cgSize.h"


class cgWindow
{
public:
    static cgSizeInt size;
    static char* name;
    static cgSizeInt fontSize;

public:
    static HANDLE inputHandle;
    static HANDLE outputHandle;

    static void init( cgSizeInt windowSize, char* name, cgSizeInt fontSize );
    static void init();
    static void resize( cgSizeInt windowSize );
    static void rename( char* name );
    static void resizeFont( cgSizeInt fontSize );
    static void showCursor( bool state );
};


#endif // __CGWINDOW__
