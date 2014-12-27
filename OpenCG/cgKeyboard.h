#ifndef CGKEYBOARD_H
#define CGKEYBOARD_H

#include <bitset>

class cgKeyboard
{
private:
    std::bitset<256> _lastState;
    std::bitset<256> _isPressed;
    std::bitset<256> _isDown;
    std::bitset<256> _isUp;
    static int* _keyTable;

public:
    cgKeyboard();
    const std::bitset<256>& isPressed;
    const std::bitset<256>& isDown;
    const std::bitset<256>& isUp;
    void updateKeyboard();
};

#endif // CGKEYBOARD_H
