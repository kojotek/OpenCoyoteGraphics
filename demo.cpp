#include <iostream>
#include "OpenCG.h"
#include <math.h>
#include <bitset>

#define WORK 1


SHORT mousex, mousey;
bool leftclick,rightclick, midclick;


void lol ()
{

    // How many events have happened?
    DWORD numEvents = 0;
    // How many events have we read from the console?
    DWORD numEventsRead = 0;
    // Boolean flag to state whether app is running or not.

    // Find out how many console events have happened:
    GetNumberOfConsoleInputEvents( cgWindow::inputHandle, &numEvents);
    // If it's not zero (something happened...)
    if (numEvents != 0)
    {
        // Create a buffer of that size to store the events
        INPUT_RECORD *eventBuffer = new INPUT_RECORD[numEvents];

        // Read the console events into that buffer, and save how
        // many events have been read into numEventsRead.
        ReadConsoleInput(cgWindow::inputHandle, eventBuffer, numEvents, &numEventsRead);

        // Now, cycle through all the events that have happened:
        for (DWORD i = 0; i < numEventsRead; i++) {

            // Check the event type: was it a key?
            if (eventBuffer[i].EventType == MOUSE_EVENT) {

                mousex = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
                mousey = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;


                if ( eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_WHEELED )
                {

                }
                std::cout << mousex  << std::endl;
                leftclick = eventBuffer[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED;
                rightclick = eventBuffer[i].Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED;
                midclick = eventBuffer[i].Event.MouseEvent.dwButtonState & FROM_LEFT_2ND_BUTTON_PRESSED;
                //std::cout << (eventBuffer[i].Event.MouseEvent.dwButtonState) << std::endl;
            }

        }

        // Clean up our event buffer:
        delete[] eventBuffer;
    }
}






int main()
{

    cgWindow::init( cgSizeInt(80,80), "Little Coyote enjoys console", cgSizeInt(CG_FONT_SIZE_8X8) );
    cgWindow::showCursor(false);

    cgTimer timer;
    cgKeyboard kb;

    cgBitmap screen( cgWindow::getSize() );
    cgPixel* mypix;
    cgPixel* a = new cgPixel( CG_COLORSET_BLUE_16 );
    cgPixel* b = new cgPixel( CG_COLORSET_FUCHSIA_5 );

    while( WORK )
    {

        screen.fill( cgPixel( cgPixel(CG_COLORSET_BLUE_20) ) );
        if (midclick)  mypix = a;
        else            mypix = b;
        screen.addRectByPoints( cgVectorInt( 0,0), cgVectorInt( mousex, mousey), *mypix, CG_FILLED );
        kb.updateKeyboard();
        //std::cout << kb.isPressed << std::endl;
        //screen.print( cgVectorInt(0,0) );
        lol();
    }


    return 0;
}
