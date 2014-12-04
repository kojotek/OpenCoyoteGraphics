#include <iostream>
#include "OpenCG.h"

using namespace std;

int main()
{

    cgWindow::init( cgSize(15,15), "Little Coyote enjoys console", cgSize(CG_FONT_SIZE_12X16) );

    cgCoordi coordInt(3, 55);
    cgCoordf coordFloat(5.34f, 30.98f);

    coordFloat = coordInt.getFloat();
    coordFloat.x += 0.314;

    cgVector2i vectorInt( coordInt, coordFloat.getInt() );
    cgVector2f vectorFloat( 0, 14.23f, 77.77f, 10.3f );

    std::cout << "Hello Coyote!" << std::endl;

    return 0;
}
