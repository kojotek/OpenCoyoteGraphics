#include <iostream>
#include "OpenCG.h"

int main()
{

    cgWindow::init( cgSize(80,80), "Little Coyote enjoys console", cgSize(CG_FONT_SIZE_8X8) );
    cgWindow::showCursor(false);

    cgTimer timer;


    cgKeyboard kb;

    cgCoordi coordInt(3, 55);
    cgCoordf coordFloat(5.34f, 30.98f);

    coordFloat = coordInt.getFloat();
    coordFloat.x += 0.314;

    cgVector2i vectorInt( coordInt, coordFloat.getInt() );
    cgVector2f vectorFloat( 0, 14.23f, 77.77f, 10.3f );


    cgBitmap screen( cgSize(cgWindow::size.width, cgWindow::size.height) );
    cgBitmap bigbmp( cgSize( 30, 30 ) );
    cgBitmap smallbmp( cgSize(10, 10) );


    CHAR_INFO mychar;
    mychar.Char.AsciiChar = ' ';
    mychar.Attributes = 1;

    screen.fill(mychar);

    mychar.Attributes = 255;
    smallbmp.fill(mychar);

    mychar.Attributes = 55;
    smallbmp.addFilledRect( cgCoordi(1,1), cgSize(8,8), mychar );

    mychar.Attributes = CG_TRANSPARENT;
    for( int a(1); a<8; a+=2 )
    {
        for( int b(1); b<9; b++ )
            smallbmp.addPixel( cgCoordi(a+(b%2),b), mychar );
    }


    for (int x(0); x<bigbmp.size.width; x++)
        for (int y(0); y<bigbmp.size.height; y++)
        {
            bigbmp.bufor[x + y*bigbmp.size.width].Attributes = rand()%256;
            bigbmp.bufor[x + y*bigbmp.size.width].Char.AsciiChar = rand()%256;
        }

    mychar.Attributes = 255;

    bigbmp.addRect(cgCoordi(27,27),cgSize(4,4), mychar);


    int bigx=20; int bigy = 10;
    int bigMove = 1;
    int smallx=40; int smally = 20;
    int smallMove = 0;

    mychar.Attributes = 1;

//    cgTimer timer;

    bigbmp.saveToFile("mojPlik.xml");

    while(true)
    {

        timer.reset( CG_MILISECONDS );

        kb.updateKeyboard();

        screen.fill(mychar);

        bigbmp.copyToBitmap(screen, cgCoordi(bigx,bigy));
        smallbmp.copyToBitmap(screen, cgCoordi(smallx,smally));

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

        //bigx += bigMove;

        while( timer.getTime( CG_MILISECONDS ) < 50 )
            screen.print( cgCoordi(0,0) );
    }

    return 0;
}
