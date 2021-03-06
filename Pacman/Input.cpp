#include "Input.hpp"
#include <iostream>

void Input::Update()
{
    for(size_t i = 0; i < KEY_MAX; i++)
    {
        mKeyStates[i].lastPressed = mKeyStates[i].pressed;
    }
}

void Input::ResetNow()
{
    for(size_t i = 0; i < KEY_MAX; i++)
    {
        mKeyStates[i].pressed = false;
    }
}

bool Input::GetButtonDown(int key)
{
    return mKeyStates[key].lastPressed == false && mKeyStates[key].pressed == true;
}
