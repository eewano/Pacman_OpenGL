#ifndef Input_hpp
#define Input_hpp

#include "Vec2.hpp"

struct State
{
    bool pressed;
    bool lastPressed;
};

class Input
{
public:
    static constexpr int KEY_MAX = 512;
    
public:
    void Update();
    void ResetNow();
    bool GetButtonDown(int key);
    
public:
    State mKeyStates[KEY_MAX];
};

#endif /* Input_hpp */
