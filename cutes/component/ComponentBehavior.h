#pragma once
#include "../history/History.h"
#include "../history/Interation.h"

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
