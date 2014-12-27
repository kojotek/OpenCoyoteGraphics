#include <iostream>
#include "OpenCG.h"

int main()
{

    cgWindow::init( cgSize(80,80), "Little Coyote enjoys console", cgSize(CG_FONT_SIZE_8X8) );
    cgWindow::showCursor(false);

    cgTimer timer;
    cgKeyboard kb;



    cgBitmap screen( cgSize(cgWindow::size.width, cgWindow::size.height) );
    cgBitmap bigbmp( cgSize( 30, 30 ) );
    cgBitmap smallbmp( cgSize(10, 10) );


    smallbmp.fill( cgPixelEdit::createPixel(7) );
    smallbmp.addFilledRect( cgVectorInt(1,1), cgSize(8,8), cgPixelEdit::createPixel(3) );
    cgPixel mychar;
    cgPixelEdit::setAsciiChar(mychar, CG_TRANSPARENT_CHAR);
    for( int a(1); a<8; a+=2 )
    {
        for( int b(1); b<9; b++ )
            smallbmp.addPixel( cgVectorInt(a+(b%2),b), mychar );
    }

    smallbmp.saveToFile("mojPlik.xml");



    cgPixelEdit::setAsciiChar(mychar,' ');
    cgPixelEdit::setBackgroundColor(mychar, CG_COLOR_LIGHT_YELLOW);
    bigbmp.fill(mychar);


    int bigx=20; int bigy = 10;
    int bigMove = 1;
    int smallx=40; int smally = 20;
    int smallMove = 0;

    cgPixelEdit::setBackgroundColor(mychar, CG_COLOR_BLACK);


    while(true)
    {

        timer.reset( CG_MILISECONDS );

        kb.updateKeyboard();

        screen.fill(mychar);

        bigbmp.copyToBitmap(screen, cgVectorInt(bigx,bigy));
        smallbmp.copyToBitmap(screen, cgVectorInt(smallx,smally));

        if( bigx+bigbmp.size.width >= cgWindow::size.width )
            bigMove = -1;
        if( bigx <= 0 )
            bigMove = 1;

        if( kb.isPressed[CG_KEY_LEFT] )
            smallx -= 1;
       if( kb.isPressed[VK_RIGHT] )
            smallx += 1;
        if( kb.isPressed[VK_UP] )
            smally -= 1;
        if( kb.isPressed[VK_DOWN] )
            smally += 1;

        bigx += bigMove;

        while( timer.getTime( CG_MILISECONDS ) < 16 )
            screen.print( cgVectorInt(0,0) );
    }

    return 0;
}
