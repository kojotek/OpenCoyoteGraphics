#include "cgMouse.h"
#include "cgWindow.h"
#include <windows.h>
#include <iostream>


cgMouse::cgMouse():
    position(_position),
    scroll(_scroll),
    isPressed(_isPressed),
    isDown(_isDown),
    isUp(_isUp)
    {}


void cgMouse::updateMouse()
{
    _isDown.reset();
    _isUp.reset();
    _scroll = CG_MOUSE_SCROLL_NONE;

    DWORD numEvents;
    DWORD numEventsRead;
    GetNumberOfConsoleInputEvents( cgWindow::inputHandle, &numEvents);

    if( numEvents != 0 )
    {
        INPUT_RECORD *eventBuffer = new INPUT_RECORD[numEvents];
        ReadConsoleInput(cgWindow::inputHandle, eventBuffer, numEvents, &numEventsRead);


        if(eventBuffer[0].EventType == MOUSE_EVENT)
        {
            if( eventBuffer[0].Event.MouseEvent.dwEventFlags & MOUSE_MOVED )
            {
                _position.x = eventBuffer[0].Event.MouseEvent.dwMousePosition.X;
                _position.y = eventBuffer[0].Event.MouseEvent.dwMousePosition.Y;
            }

            if( eventBuffer[0].Event.MouseEvent.dwEventFlags & MOUSE_WHEELED )
            {
                int state = eventBuffer[0].Event.MouseEvent.dwButtonState;
                _scroll = (0<state) - (state<0);
            }

            _lastState = _isPressed;
            for( int a(0); a<3; a++ )
            {
                _isPressed[a] = eventBuffer[0].Event.MouseEvent.dwButtonState & (1<<a);
            }

            _isDown = ( _isPressed & (~_lastState) );
            _isUp = ( (~_isPressed) & _lastState );
        }

        delete[] eventBuffer;
    }
}
