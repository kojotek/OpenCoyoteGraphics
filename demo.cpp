#include <iostream>
#include "OpenCG.h"


int main()
{

    cgWindow::init( cgSize(100,50), "Little Coyote enjoys console", cgSize(CG_FONT_SIZE_8X8) );

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


    mychar.Attributes = 111;
    bigbmp.fill(mychar);


    COORD charBufSize = {cgWindow::size.width, cgWindow::size.height};
    COORD characterPos = {0,0};
    SMALL_RECT writeArea = {0,0,cgWindow::size.width,cgWindow::size.height};

    int bigx=0; int bigy = 10;
    int bigMove = 1;
    int smallx=70; int smally = 20;
    int smallMove = -1;


    mychar.Attributes = 1;

    while(true)
    {

        screen.fill(mychar);

        bigbmp.copyToBitmap(screen, cgCoordi(bigx,bigy));
        smallbmp.copyToBitmap(screen, cgCoordi(smallx,smally));

        WriteConsoleOutputA(cgWindow::outputHandle, screen.bufor, charBufSize, characterPos, &writeArea);

        if( bigx+bigbmp.size.width >= cgWindow::size.width )
            bigMove = -1;
        if( bigx <= 0 )
            bigMove = 1;

        if( smallx+smallbmp.size.width >= cgWindow::size.width )
            smallMove = -1;
        if( smallx <= 0 )
            smallMove = 1;

        bigx += bigMove;
        smallx += smallMove;

        Sleep(40);

    }

    return 0;
}
