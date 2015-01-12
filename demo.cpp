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
    cgBitmap screen2( cgSizeInt(cgWindow::getSize().width, cgWindow::getSize().height) );
    cgBitmap screen3( cgSizeInt(cgWindow::getSize().width, cgWindow::getSize().height) );
    cgBitmap screen4( cgSizeInt(cgWindow::getSize().width, cgWindow::getSize().height) );


    int ax,bx,ay,by;
    ax=2;
    ay=2;
    bx=2;
    by=2;

    cgBitmap lol( cgSizeInt(20,20) );
    lol.fill( cgPixelEdit::createPixel( 'e', CG_COLOR_BLACK, CG_COLOR_BLACK ) );
    lol.addRectByPoints( cgVectorInt(0,0), cgVectorInt(19,19), cgPixelEdit::createPixel( '+', CG_COLOR_BLACK, CG_COLOR_LIGHT_CYAN ), true  );
    lol.addRectByPoints( cgVectorInt(2,2), cgVectorInt(17,17), cgPixelEdit::createPixel( '@', CG_COLOR_BLACK, CG_COLOR_BLUE ), true  );
    lol.addRectByPoints( cgVectorInt(4,4), cgVectorInt(15,15), cgPixelEdit::createPixel( '#', CG_COLOR_BLACK, CG_COLOR_LIGHT_CYAN ), true  );
    lol.addRectByPoints( cgVectorInt(6,6), cgVectorInt(13,13), cgPixelEdit::createPixel( '=', CG_COLOR_BLACK, CG_COLOR_LIGHT_BLUE ), true  );
    lol.addRectByPoints( cgVectorInt(8,8), cgVectorInt(11,11), cgPixelEdit::createPixel( 'e', CG_COLOR_BLACK, CG_COLOR_LIGHT_CYAN ), true  );

    cgBitmap m1 = lol.getPartByPoints( cgVectorInt(0,0), cgVectorInt(9,9) );
    cgBitmap m2 = lol.getPartByPoints( cgVectorInt(10,0), cgVectorInt(19,9) );
    cgBitmap m3 = lol.getPartByPoints( cgVectorInt(0,10), cgVectorInt(9,19) );
    cgBitmap m4 = lol.getPartByPoints( cgVectorInt(10,10), cgVectorInt(19,19) );

    cgBitmap lol2( cgSizeInt(20,20) );
    lol2.fill( cgPixelEdit::createPixel( 'e', CG_COLOR_BLACK, CG_COLOR_BLACK ) );
    lol2.addRectByPoints( cgVectorInt(0,0), cgVectorInt(19,19), cgPixelEdit::createPixel( '+', CG_COLOR_BLACK, CG_COLOR_LIGHT_RED ), true  );
    lol2.addRectByPoints( cgVectorInt(2,2), cgVectorInt(17,17), cgPixelEdit::createPixel( '@', CG_COLOR_BLACK, CG_COLOR_YELLOW ), true  );
    lol2.addRectByPoints( cgVectorInt(4,4), cgVectorInt(15,15), cgPixelEdit::createPixel( '#', CG_COLOR_BLACK, CG_COLOR_LIGHT_YELLOW ), true  );
    lol2.addRectByPoints( cgVectorInt(6,6), cgVectorInt(13,13), cgPixelEdit::createPixel( '=', CG_COLOR_BLACK, CG_COLOR_LIGHT_RED ), true  );
    lol2.addRectByPoints( cgVectorInt(8,8), cgVectorInt(11,11), cgPixelEdit::createPixel( 'e', CG_COLOR_BLACK, CG_COLOR_LIGHT_YELLOW ), true  );

    cgBitmap n1 = lol2.getPartByPoints( cgVectorInt(0,0), cgVectorInt(9,9) );
    cgBitmap n2 = lol2.getPartByPoints( cgVectorInt(10,0), cgVectorInt(19,9) );
    cgBitmap n3 = lol2.getPartByPoints( cgVectorInt(0,10), cgVectorInt(9,19) );
    cgBitmap n4 = lol2.getPartByPoints( cgVectorInt(10,10), cgVectorInt(19,19) );

    cgBitmap lol3( cgSizeInt(20,20) );
    lol3.fill( cgPixelEdit::createPixel( 'e', CG_COLOR_BLACK, CG_COLOR_BLACK ) );
    lol3.addRectByPoints( cgVectorInt(0,0), cgVectorInt(19,19), cgPixelEdit::createPixel( '+', CG_COLOR_BLACK, CG_COLOR_GREY ), true  );
    lol3.addRectByPoints( cgVectorInt(2,2), cgVectorInt(17,17), cgPixelEdit::createPixel( '@', CG_COLOR_BLACK, CG_COLOR_BLACK ), true  );
    lol3.addRectByPoints( cgVectorInt(4,4), cgVectorInt(15,15), cgPixelEdit::createPixel( '#', CG_COLOR_BLACK, CG_COLOR_LIGHT_GREY ), true  );
    lol3.addRectByPoints( cgVectorInt(6,6), cgVectorInt(13,13), cgPixelEdit::createPixel( '=', CG_COLOR_BLACK, CG_COLOR_GREY ), true  );
    lol3.addRectByPoints( cgVectorInt(8,8), cgVectorInt(11,11), cgPixelEdit::createPixel( 'e', CG_COLOR_BLACK, CG_COLOR_LIGHT_GREY ), true  );

    cgBitmap o1 = lol3.getPartByPoints( cgVectorInt(0,0), cgVectorInt(9,9) );
    cgBitmap o2 = lol3.getPartByPoints( cgVectorInt(10,0), cgVectorInt(19,9) );
    cgBitmap o3 = lol3.getPartByPoints( cgVectorInt(0,10), cgVectorInt(9,19) );
    cgBitmap o4 = lol3.getPartByPoints( cgVectorInt(10,10), cgVectorInt(19,19) );

    cgBitmap lol4( cgSizeInt(20,20) );
    lol4.fill( cgPixelEdit::createPixel( 'e', CG_COLOR_BLACK, CG_COLOR_BLACK ) );
    lol4.addRectByPoints( cgVectorInt(0,0), cgVectorInt(19,19), cgPixelEdit::createPixel( '+', CG_COLOR_BLACK, CG_COLOR_GREEN ), true  );
    lol4.addRectByPoints( cgVectorInt(2,2), cgVectorInt(17,17), cgPixelEdit::createPixel( '@', CG_COLOR_BLACK, CG_COLOR_LIGHT_GREEN ), true  );
    lol4.addRectByPoints( cgVectorInt(4,4), cgVectorInt(15,15), cgPixelEdit::createPixel( '#', CG_COLOR_BLACK, CG_COLOR_LIGHT_MAGENTA ), true  );
    lol4.addRectByPoints( cgVectorInt(6,6), cgVectorInt(13,13), cgPixelEdit::createPixel( '=', CG_COLOR_BLACK, CG_COLOR_GREY ), true  );
    lol4.addRectByPoints( cgVectorInt(8,8), cgVectorInt(11,11), cgPixelEdit::createPixel( 'e', CG_COLOR_BLACK, CG_COLOR_LIGHT_MAGENTA ), true  );

    cgBitmap p1 = lol4.getPartByPoints( cgVectorInt(0,0), cgVectorInt(9,9) );
    cgBitmap p2 = lol4.getPartByPoints( cgVectorInt(10,0), cgVectorInt(19,9) );
    cgBitmap p3 = lol4.getPartByPoints( cgVectorInt(0,10), cgVectorInt(9,19) );
    cgBitmap p4 = lol4.getPartByPoints( cgVectorInt(10,10), cgVectorInt(19,19) );



    cgPixel mychar = cgPixelEdit::createPixel( ' ', CG_COLOR_BLACK, CG_COLOR_BLACK );


    float a1 = 0;
    float a2 = 0;
    float k = 0;
    int px = 0;
    int counter = 0;
    bool b1 = 1;
    int counter2 = 0;
    bool b2 = 0;
    int licznik = 0;

    int ms = 0;
    char msc[20];

    while( WORK )
    {
        //screen.setSize( cgWindow::getSize(), cgPixelEdit::createPixel(CG_COLOR_BLUE));


        if ( b1 )   counter++;
        else        counter--;

        if( counter > 110 || counter < -37) b1 = !b1;

        if ( b2 )   counter2++;
        else        counter2--;

        if( counter2 > 110 || counter2 < -37) b2 = !b2;



        kb.updateKeyboard();

        screen.fill(mychar);

        k += 0.05;
        a1 += 0.1;
        a2 == 0.1;

        if(k>3)
        {
            m1.rotate( CG_RIGHT, 1 );
            m2.rotate( CG_LEFT, 1 );
            m3.rotate( CG_RIGHT, 2 );
            m4.rotate( CG_LEFT, 2 );

            n1.rotate( CG_RIGHT, 1 );
            n2.rotate( CG_LEFT, 1 );
            n3.rotate( CG_RIGHT, 2 );
            n4.rotate( CG_LEFT, 2 );

            o1.rotate( CG_RIGHT, 1 );
            o2.rotate( CG_LEFT, 1 );
            o3.rotate( CG_RIGHT, 2 );
            o4.rotate( CG_LEFT, 2 );

            p1.rotate( CG_RIGHT, 1 );
            p2.rotate( CG_LEFT, 1 );
            p3.rotate( CG_RIGHT, 2 );
            p4.rotate( CG_LEFT, 2 );

            k = 0;
        }

        px++;
        if( px > 20 )
            px = 1;

        for (int x(-20); x<cgWindow::getSize().width; x+=20 )
            for (int y(-20); y<cgWindow::getSize().height; y+=20 )
            {
                m1.copyToBitmap( screen, cgVectorInt(x+px,y+px) );
                m2.copyToBitmap( screen, cgVectorInt(x+10+px,y+px) );
                m4.copyToBitmap( screen, cgVectorInt(x+px,y+px+10) );
                m3.copyToBitmap( screen, cgVectorInt(x+px+10,y+px+10) );

                n1.copyToBitmap( screen2, cgVectorInt(x+px,y+px) );
                n2.copyToBitmap( screen2, cgVectorInt(x+10+px,y+px) );
                n4.copyToBitmap( screen2, cgVectorInt(x+px,y+px+10) );
                n3.copyToBitmap( screen2, cgVectorInt(x+px+10,y+px+10) );

                o1.copyToBitmap( screen3, cgVectorInt(x+px,y+px) );
                o2.copyToBitmap( screen3, cgVectorInt(x+10+px,y+px) );
                o4.copyToBitmap( screen3, cgVectorInt(x+px,y+px+10) );
                o3.copyToBitmap( screen3, cgVectorInt(x+px+10,y+px+10) );

                p1.copyToBitmap( screen4, cgVectorInt(x+px,y+px) );
                p2.copyToBitmap( screen4, cgVectorInt(x+10+px,y+px) );
                p4.copyToBitmap( screen4, cgVectorInt(x+px,y+px+10) );
                p3.copyToBitmap( screen4, cgVectorInt(x+px+10,y+px+10) );
            }


        screen2.getPartByPoints( cgVectorInt(5,5), cgVectorInt(73, std::max(5, std::min(73, counter-2) ) ) ).copyToBitmap( screen, cgVectorInt(5, 5 ) );
        screen3.getPartByPoints( cgVectorInt(5,5), cgVectorInt( std::max(5, std::min(73, counter2-2)), 73 )).copyToBitmap( screen, cgVectorInt(5, 5 ) );
        screen4.getPartByPoints( cgVectorInt(5, std::max(5, std::min(73, counter))),
                                 cgVectorInt( std::max(5, std::min(73, counter2)), 73)
                                ).copyToBitmap(
                                                screen,
                                                cgVectorInt(5, std::max(5, std::min(73, counter)))
                                                );

        screen.addRectByPoints( cgVectorInt(5,5), cgVectorInt(73, std::max(5, std::min(73, counter) ) ), cgPixelEdit::createPixel( CG_COLOR_WHITE ), false );
        screen.addRectByPoints( cgVectorInt(5,5), cgVectorInt(73, std::max(5, std::min(73, counter-1) ) ), cgPixelEdit::createPixel( CG_COLOR_WHITE ), false );
        screen.addRectByPoints( cgVectorInt(5,5), cgVectorInt( std::max(5, std::min(73, counter2)), 73 ), cgPixelEdit::createPixel( CG_COLOR_WHITE ), false );
        screen.addRectByPoints( cgVectorInt(5,5), cgVectorInt( std::max(5, std::min(73, counter2-1)), 73 ), cgPixelEdit::createPixel( CG_COLOR_WHITE ), false );

        screen.addRectByPoints( cgVectorInt(5,5), cgVectorInt(73,73), cgPixelEdit::createPixel( CG_COLOR_GREEN ), false );

        screen.setSize(cgSizeInt(50,50), cgPixelEdit::createPixel(CG_COLOR_BLUE));


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
