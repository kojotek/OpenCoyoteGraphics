#ifndef CGKEYBOARD_H
#define CGKEYBOARD_H

#include <bitset>

#define HANDLED_KEYS 101
#define KEYSET_SIZE 256

class cgKeyboard
{
private:
    std::bitset<KEYSET_SIZE> _lastState;
    std::bitset<KEYSET_SIZE> _isPressed;
    std::bitset<KEYSET_SIZE> _isDown;
    std::bitset<KEYSET_SIZE> _isUp;
    static int* _keyTable;

public:
    cgKeyboard();
    const std::bitset<KEYSET_SIZE> &isPressed;
    const std::bitset<KEYSET_SIZE> &isDown;
    const std::bitset<KEYSET_SIZE> &isUp;
    void updateKeyboard();
};

#endif // CGKEYBOARD_H
