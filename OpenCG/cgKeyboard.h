#ifndef CGKEYBOARD_H
#define CGKEYBOARD_H

#include <bitset>

#define CG_KEYSET_SIZE 101

class cgKeyboard
{
private:
    std::bitset<CG_KEYSET_SIZE> _lastState;
    std::bitset<CG_KEYSET_SIZE> _isPressed;
    std::bitset<CG_KEYSET_SIZE> _isDown;
    std::bitset<CG_KEYSET_SIZE> _isUp;
    static int* _keyTable;

public:
    cgKeyboard();
    const std::bitset<CG_KEYSET_SIZE>& isPressed;
    const std::bitset<CG_KEYSET_SIZE>& isDown;
    const std::bitset<CG_KEYSET_SIZE>& isUp;
    void updateKeyboard();
};

#endif // CGKEYBOARD_H
