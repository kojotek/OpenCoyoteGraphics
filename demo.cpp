#include "OpenCG.h"
#include <iostream>
#include <math.h>
#include <bitset>

#define WORK 1



int main()
{

    cgWindow::init( cgSizeInt(80,80), "Little Coyote enjoys console", cgSizeInt(CG_FONT_SIZE_8X8) );
    cgWindow::showCursor(false);

    cgTimer timer;
    cgKeyboard kb;
    cgMouse ms;

    cgBitmap screen( cgWindow::getSize() );
    cgPixel* mypix;
    cgPixel* a = new cgPixel( CG_COLORSET_BLUE_16 );
    cgPixel* b = new cgPixel( CG_COLORSET_FUCHSIA_5 );

    while( WORK )
    {
        ms.updateMouse();
        kb.updateKeyboard();
        if ( ms.isDown[CG_MOUSE_BUTTON_LEFT] )
            std::cout << "lewy przycisk w dol" << std::endl;
        if ( ms.isUp[CG_MOUSE_BUTTON_LEFT] )
           std::cout << "lewy przycisk w gore" << std::endl;
        if ( ms.isDown[CG_MOUSE_BUTTON_MIDDLE] )
            std::cout << "srodkowy przycisk w dol" << std::endl;
        if ( ms.isUp[CG_MOUSE_BUTTON_MIDDLE] )
           std::cout << "srodkowy przycisk w gore" << std::endl;
        if ( ms.isDown[CG_MOUSE_BUTTON_RIGHT] )
            std::cout << "prawy przycisk w dol" << std::endl;
        if ( ms.isUp[CG_MOUSE_BUTTON_RIGHT] )
           std::cout << "prawy przycisk w gore" << std::endl;
        if ( ms.scroll == CG_MOUSE_SCROLL_UP )
            std::cout << "Rolka myszy w gore" << std::endl;
        if ( ms.scroll == CG_MOUSE_SCROLL_DOWN )
            std::cout << "Rolka myszy w dol" << std::endl;
    }

    return 0;
}
