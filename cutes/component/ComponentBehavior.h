#pragma once
#include "../history/History.h"

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
