#include <iostream>
#include "OpenCG.h"
#include <bitset>

int main()
{

    cgWindow::init( cgSize(80,80), "Little Coyote enjoys console", cgSize(CG_FONT_SIZE_8X8) );

    cgKeyboard kb;

    while(true)
    {
        kb.updateKeyboard();
        if (kb.isUp[27])
            std::cout << "puscilem escape" << std::endl;
    }

/*
    std::bitset<8> b1;
    b1[0] = 1;
    b1[3] = 1;
    b1[7] = 1;

    for (int a(0); a<b1.size();a++)
        std::cout<<b1[a];

    std::bitset<8> b2;
    b2 = ~b1;

    std::cout<<std::endl;
    for (int a(0); a<b2.size();a++)
        std::cout<<b2[a];
*/
/*
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

        screen.print( cgCoordi(0,0) );

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

        Sleep(20);

    }
*/
    return 0;
}
