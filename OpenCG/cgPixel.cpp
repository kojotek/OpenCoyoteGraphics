#include "cgPixel.h"


cgPixel::cgPixel( CHAR asciiChar, WORD backgroundColor, WORD foregroundColor )
{
    pixelInfo.Char.AsciiChar = asciiChar;
    pixelInfo.Attributes = foregroundColor + (16*backgroundColor);
}


cgPixel::cgPixel( WORD color )
{
    pixelInfo.Char.AsciiChar = ' ';
    pixelInfo.Attributes = 17*color;  // 16*color + color
}


cgPixel::cgPixel( CHAR_INFO char_info )
{
    pixelInfo = char_info;
}



void cgPixel::setFrontClr( WORD foregroundColor )
{
    pixelInfo.Attributes = 16 * (pixelInfo.Attributes/16) + foregroundColor;
}


void cgPixel::setBckClr( WORD backgroundColor )
{
    pixelInfo.Attributes = (16*backgroundColor) + (pixelInfo.Attributes%16);
}


void cgPixel::setAscii( CHAR asciiChar )
{
    pixelInfo.Char.AsciiChar = asciiChar;
}


WORD cgPixel::getFrontClr()
{
    return (pixelInfo.Attributes % 16 );
}


WORD cgPixel::getBckClr()
{
    return (pixelInfo.Attributes / 16 );
}


char cgPixel::getAscii()
{
    return pixelInfo.Char.AsciiChar;
}


CHAR_INFO cgPixel::getCharInfo()
{
    return pixelInfo;
}


void cgPixel::setCharInfo( CHAR_INFO char_info )
{
    pixelInfo = char_info;
}
