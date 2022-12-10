#pragma once
#include "../History/History.h"
#include "../History/Interation.h"

class ComponentBehavior
{

public:
    int pin;
    History *history;

    ComponentBehavior(int pin)
    {
        this->pin = pin;
    };
};
