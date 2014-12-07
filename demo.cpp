#include <iostream>
#include "OpenCG.h"

using namespace std;

int main()
{

    cgWindow::init( cgSize(80,80), "Little Coyote enjoys console", cgSize(CG_FONT_SIZE_8X8) );

    cgCoordi coordInt(3, 55);
    cgCoordf coordFloat(5.34f, 30.98f);

    coordFloat = coordInt.getFloat();
    coordFloat.x += 0.314;

    cgVector2i vectorInt( coordInt, coordFloat.getInt() );
    cgVector2f vectorFloat( 0, 14.23f, 77.77f, 10.3f );

    //std::cout << "Hello Coyote!" << std::endl;

    CHAR_INFO mychar;           //TO POWODUJE PROBLEMY
    mychar.Char.AsciiChar = 'A';
    mychar.Attributes = 150;

    cgBitmap bmp( cgSize(10, 20) );
    bmp.fill(mychar);


    COORD charBufSize = {bmp.size.width, bmp.size.height};
    COORD characterPos = {0,0};
    SMALL_RECT writeArea = {20,20,20+bmp.size.width-1,20+bmp.size.height-1};
    WriteConsoleOutputA(cgWindow::outputHandle, bmp.bufor, charBufSize, characterPos, &writeArea);

    return 0;
}
