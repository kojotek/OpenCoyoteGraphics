#include <iostream>
#include "OpenCG.h"
#include <math.h>

int main()
{

    cgWindow::init( cgSizeInt(80,80), "Little Coyote enjoys console", cgSizeInt(CG_FONT_SIZE_8X8) );
    cgWindow::showCursor(false);

    cgTimer timer;
    cgKeyboard kb;


    cgBitmap screen( cgSizeInt(cgWindow::size.width, cgWindow::size.height) );
    cgBitmap bigbmp( cgSizeInt( 30, 30 ) );


    cgBitmap smallbmp( cgSizeInt(10, 10) );
    smallbmp.readFromFile("MojPlik.xml");



    cgPixel mychar;
    cgPixelEdit::setAsciiChar(mychar,' ');
    cgPixelEdit::setBackgroundColor(mychar, CG_COLOR_LIGHT_YELLOW);
    bigbmp.fill(mychar);


    bigbmp.addFilledRect( cgVectorInt(3,3), cgSizeInt(5,5), cgPixelEdit::createPixel( '+', CG_COLOR_BLACK, CG_COLOR_WHITE ) );
    bigbmp.addRect( cgVectorInt(10,10), cgSizeInt(10,10), cgPixelEdit::createPixel( '#', CG_COLOR_WHITE, CG_COLOR_BLACK ) );
    bigbmp.addPixel( cgVectorInt(8,25), cgPixelEdit::createPixel( '!', CG_COLOR_YELLOW, CG_COLOR_BLUE ) );


    int bigx=20; int bigy = 10;
    int bigMove = 1;
    int smallx=40; int smally = 20;
    int smallMove = 0;

    cgPixelEdit::setBackgroundColor(mychar, CG_COLOR_BLACK);
    bigbmp.addLineByPoints( cgVectorInt(10,10), cgVectorInt(50,10), cgPixelEdit::createPixel( 'D', CG_COLOR_CYAN, CG_COLOR_GREEN ) );
    cgBitmap clck( cgSizeInt( 30, 30 ) );

    float angle=0;

    int ax,bx,ay,by;
    ax=0;
    ay=0;
    bx=0;
    by=1;

    while(true)
    {

        angle += 0.01f;
        timer.reset( CG_MILISECONDS );

        kb.updateKeyboard();

        screen.fill(mychar);
        //clck.fill(cgPixelEdit::createPixel( ' ', CG_COLOR_WHITE, CG_COLOR_GREEN ));

        cgSizeInt half(15,15);// half = clck.size/2;
        float rx = (float)half.width + 24.0f*cos(angle);
        float ry = (float)half.height + 24.0f*sin(angle);

        //clck.addLineByPoints( cgVectorInt( half.width, half.height ), cgVectorInt( rx, ry ), cgPixelEdit::createPixel( 'D', CG_COLOR_CYAN, CG_COLOR_GREEN ) );
        screen.addLineByPoints( cgVectorInt(ax,ay), cgVectorInt(bx,by), cgPixelEdit::createPixel( 'o', CG_COLOR_BLACK, CG_COLOR_GREEN ) );

        //clck.copyToBitmap(screen, cgVectorInt(bigx,bigy));
        //smallbmp.copyToBitmap(screen, cgVectorInt(smallx,smally));


        if( kb.isPressed[CG_KEY_LEFT] )
            bx -= 1;
       if( kb.isPressed[VK_RIGHT] )
            bx += 1;
        if( kb.isPressed[VK_UP] )
            by -= 1;
        if( kb.isPressed[VK_DOWN] )
            by += 1;
        if( kb.isPressed[CG_KEY_A] )
            ax -= 1;
       if( kb.isPressed[CG_KEY_D] )
            ax += 1;
        if( kb.isPressed[CG_KEY_W] )
            ay -= 1;
        if( kb.isPressed[CG_KEY_S] )
            ay += 1;


        while( timer.getTime( CG_MILISECONDS ) < 16 )
            screen.print( cgVectorInt(0,0) );
    }

    return 0;
}
