#include "cgKeyboard.h"
#include "cgWindow.h"
#include <windows.h>

void cgKeyboard::updateKeyboard()
{
    lastState = isPressed;
    isPressed.reset();

    for (int i(0); i<256; i++)
        isPressed[i] = ( GetKeyState(i) & 0x80 );

    isUp = ( (~isPressed) & lastState );
    isDown = ( isPressed & (~lastState) );
}
