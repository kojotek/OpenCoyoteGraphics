#include "cgKeyboard.h"
#include "cgWindow.h"
#include <windows.h>


cgKeyboard::cgKeyboard() :
    isPressed(_isPressed),
    isDown(_isDown),
    isUp(_isUp)
    {}


void cgKeyboard::updateKeyboard()
{
    _lastState = _isPressed;
    _isPressed.reset();

    for (int i(0); i<256; i++)
        _isPressed[i] = ( GetKeyState(i) & 0x80 );

    _isUp = ( (~_isPressed) & _lastState );
    _isDown = ( _isPressed & (~_lastState) );
}
