#include "cgWindow.h"
#include "cgSize.h"


HANDLE cgWindow::inputHandle;
HANDLE cgWindow::outputHandle;
cgSize cgWindow::size;
char* cgWindow::name;
cgSize cgWindow::fontSize;


void cgWindow::init( cgSize s, char* n, cgSize f )
{
    inputHandle = GetStdHandle(STD_INPUT_HANDLE);
    outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    resizeFont(f);
    resize(s);
    rename(n);
}


void cgWindow::init()
{
    inputHandle = GetStdHandle(STD_INPUT_HANDLE);
    outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    resizeFont(CG_FONT_SIZE_8X12);
    resize(cgSize(20,20));
    rename("Coyote Console");
}


void cgWindow::resize( cgSize s )
{
    size = s;

    SMALL_RECT windowSize = {0, 0, size.width-1, size.height-1};
    COORD bufferSize = { size.width, size.height };

    SetConsoleWindowInfo( outputHandle, TRUE, &windowSize );
    SetConsoleScreenBufferSize( outputHandle, bufferSize );
    SetConsoleWindowInfo( outputHandle, TRUE, &windowSize );
    SetConsoleScreenBufferSize( outputHandle, bufferSize );
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


void cgWindow::showCursor( bool state )
{
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo( outputHandle, &cci );
    cci.bVisible = state;
    SetConsoleCursorInfo( outputHandle, &cci );
}
