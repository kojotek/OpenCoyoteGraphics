#ifndef CGKEYBOARD_H
#define CGKEYBOARD_H

#include <bitset>

class cgKeyboard
{
private:
    std::bitset<256> lastState;

public:
    std::bitset<256> isPressed;
    std::bitset<256> isDown;
    std::bitset<256> isUp;
    void updateKeyboard();
};

#endif // CGKEYBOARD_H
