#include <iostream>
#include "OpenCG.h"
#include <math.h>

#define WORK 1

int main()
{

    cgWindow::init( cgSizeInt(80,80), "Little Coyote enjoys console", cgSizeInt(CG_FONT_SIZE_8X8) );
    cgWindow::showCursor(false);

    cgTimer timer;
    cgKeyboard kb;

    cgBitmap screen( cgSizeInt(cgWindow::getSize().width, cgWindow::getSize().height) );

    cgBitmap lol( cgSizeInt(20,20) );

    cgPixel mychar = cgPixelEdit::createPixel( 'a', CG_COLOR_WHITE, CG_COLOR_BLACK );

    long ms = 0;

    while( WORK )
    {

        int poz = -1;

        screen.fill(cgPixelEdit::createPixel(CG_COLOR_BLACK));

        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixelEdit::createPixel(176, CG_COLOR_BLACK, CG_COLOR_GREEN), CG_FILLED );
        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixelEdit::createPixel(177, CG_COLOR_BLACK, CG_COLOR_GREEN), CG_FILLED );
        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixelEdit::createPixel(178, CG_COLOR_BLACK, CG_COLOR_GREEN), CG_FILLED );
        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixelEdit::createPixel(219, CG_COLOR_BLACK, CG_COLOR_GREEN), CG_FILLED );


        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixelEdit::createPixel(176, CG_COLOR_GREEN, CG_COLOR_LIGHT_GREEN), CG_FILLED );
        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixelEdit::createPixel(177, CG_COLOR_GREEN, CG_COLOR_LIGHT_GREEN), CG_FILLED );
        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixelEdit::createPixel(178, CG_COLOR_GREEN, CG_COLOR_LIGHT_GREEN), CG_FILLED );
        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixelEdit::createPixel(219, CG_COLOR_GREEN, CG_COLOR_LIGHT_GREEN), CG_FILLED );

        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixelEdit::createPixel(178, CG_COLOR_LIGHT_GREY, CG_COLOR_LIGHT_GREEN), CG_FILLED );
        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixelEdit::createPixel(177, CG_COLOR_WHITE, CG_COLOR_LIGHT_GREEN), CG_FILLED );
        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixelEdit::createPixel(176, CG_COLOR_WHITE, CG_COLOR_LIGHT_GREEN), CG_FILLED );

        while( ms < 16 )
        {
            screen.print( cgVectorInt(0,0) );
            ms = timer.getTime();
        }

        ms = 0;
        timer.reset();

    }

    return 0;
}
