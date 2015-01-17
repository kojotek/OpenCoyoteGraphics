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

    cgPixel mychar( 'a', CG_COLOR_WHITE, CG_COLOR_BLACK );

    long ms = 0;

    while( WORK )
    {

        int poz = 0;

        screen.fill(cgPixel(CG_COLOR_BLACK));

        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixel(176, CG_COLOR_BLACK, CG_COLOR_GREEN), CG_FILLED );
        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixel(177, CG_COLOR_BLACK, CG_COLOR_GREEN), CG_FILLED );
        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixel(178, CG_COLOR_BLACK, CG_COLOR_GREEN), CG_FILLED );
        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixel(219, CG_COLOR_BLACK, CG_COLOR_GREEN), CG_FILLED );

        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixel(176, CG_COLOR_GREEN, CG_COLOR_LIGHT_GREEN), CG_FILLED );
        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixel(177, CG_COLOR_GREEN, CG_COLOR_LIGHT_GREEN), CG_FILLED );
        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixel(178, CG_COLOR_GREEN, CG_COLOR_LIGHT_GREEN), CG_FILLED );
        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixel(219, CG_COLOR_GREEN, CG_COLOR_LIGHT_GREEN), CG_FILLED );

        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixel(178, CG_COLOR_LIGHT_GREY, CG_COLOR_LIGHT_GREEN), CG_FILLED );
        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixel(177, CG_COLOR_WHITE, CG_COLOR_LIGHT_GREEN), CG_FILLED );
        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixel(176, CG_COLOR_WHITE, CG_COLOR_LIGHT_GREEN), CG_FILLED );
        poz+=5; screen.addRectByOrigin( cgVectorInt(0,poz), cgSizeInt(80,5), cgPixel(' ', CG_COLOR_WHITE, CG_COLOR_LIGHT_GREEN), CG_FILLED );


        cgPixel lol = screen.getPixel( cgVectorInt( 1,6 ) );
        screen.fill( lol );

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
