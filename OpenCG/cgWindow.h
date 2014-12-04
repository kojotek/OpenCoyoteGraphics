#ifndef __CGWINDOW__
#define __CGWINDOW__

//DEFINES/////////////////////////////////
#define CG_FONT_SIZE_4X6 cgSize(4,6)
#define CG_FONT_SIZE_6X8 cgSize(6,8)
#define CG_FONT_SIZE_8X8 cgSize(8,8)
#define CG_FONT_SIZE_16X8 cgSize(16,8)
#define CG_FONT_SIZE_5X12 cgSize(5,12)
#define CG_FONT_SIZE_7X12 cgSize(7,12)
#define CG_FONT_SIZE_8X12 cgSize(8,12)
#define CG_FONT_SIZE_16X12 cgSize(16,12)
#define CG_FONT_SIZE_12X16 cgSize(12,16)
#define CG_FONT_SIZE_10X18 cgSize(10,18)
//DEFINES/////////////////////////////////

#include <stdlib.h>
#include <Windows.h>
#include <Tchar.h>
#include "cgSize.h"


class cgWindow
{
private:
    static cgSize size;
    static char* name;
    static cgSize fontSize;

public:
    static HANDLE inputHandle;
    static HANDLE outputHandle;

    static void init( cgSize windowSize, char* name, cgSize fontSize );
    static void init();
    static void resize( cgSize windowSize );
    static void rename( char* name );
    static void resizeFont( cgSize fontSize );
};


#endif // __CGWINDOW__
