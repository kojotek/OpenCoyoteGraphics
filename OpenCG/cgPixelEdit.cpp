#include "cgPixelEdit.h"


cgPixel cgPixelEdit::createPixel( CHAR asciiChar, WORD foregroundColor, WORD backgroundColor )
{
    cgPixel pixel;
    pixel.Char.AsciiChar = asciiChar;
    pixel.Attributes = foregroundColor + (16*backgroundColor);
    return pixel;
}


cgPixel cgPixelEdit::createPixel( WORD color )
{
    cgPixel pixel;
    pixel.Char.AsciiChar = ' ';
    pixel.Attributes = 17*color;  // 16*color + color
    return pixel;
}


void cgPixelEdit::setForegroundColor( cgPixel& pixelInfo, WORD foregroundColor )
{
    pixelInfo.Attributes = 16 * (pixelInfo.Attributes/16) + foregroundColor;
}


void cgPixelEdit::setBackgroundColor( cgPixel& pixelInfo, WORD backgroundColor )
{
    pixelInfo.Attributes = (16*backgroundColor) + (pixelInfo.Attributes%16);
}


void cgPixelEdit::setAsciiChar( cgPixel& pixelInfo, CHAR asciiChar )
{
    pixelInfo.Char.AsciiChar = asciiChar;
}
