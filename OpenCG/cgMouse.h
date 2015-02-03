#ifndef CGMOUSE_H
#define CGMOUSE_H

#include "cgMouseNames.h"
#include "cgVector.h"
#include <bitset>

class cgMouse
{
private:
    std::bitset<3> _lastState;
    std::bitset<3> _isPressed;
    std::bitset<3> _isUp;
    std::bitset<3> _isDown;
    cgVectorInt _position;
    signed char _scroll;

public:
    cgMouse();
    const std::bitset<3> &isPressed;
    const std::bitset<3> &isUp;
    const std::bitset<3> &isDown;
    const cgVectorInt &position;
    const signed char &scroll;
    void updateMouse();
};

#endif // CGMOUSE_H
