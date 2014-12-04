#include "cgWindow.h"
#include "cgSize.h"


HANDLE cgWindow::inputHandle( GetStdHandle(STD_INPUT_HANDLE) );
HANDLE cgWindow::outputHandle( GetStdHandle(STD_OUTPUT_HANDLE) );
cgSize cgWindow::size;
char* cgWindow::name;
cgSize cgWindow::fontSize;


void cgWindow::init( cgSize s, char* n, cgSize f )
{
    resize(s);
    rename(n);
    resizeFont(f);
}


void cgWindow::init()
{
    resize(cgSize(25,80));
    rename("Coyote Console");
    resizeFont(CG_FONT_SIZE_8X12);
}


void cgWindow::resize( cgSize s )
{
    COORD bufferSize = { size.width, size.height };
    SetConsoleScreenBufferSize( outputHandle, bufferSize );

    SMALL_RECT windowSize = {0, 0, size.width-1, size.height-1};
    SetConsoleWindowInfo( outputHandle, TRUE, &windowSize );
}


void cgWindow::rename( char* newName )
{
    SetConsoleTitle( TEXT( name = newName ) );
}


void cgWindow::resizeFont( cgSize font )
{
    fontSize = font;
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    cfi.FontFamily = 48;
    cfi.dwFontSize.X = fontSize.width;
    cfi.dwFontSize.Y = fontSize.height;
    wcscpy(cfi.FaceName, L"Terminal");
    SetCurrentConsoleFontEx(cgWindow::outputHandle, FALSE, &cfi);
}
