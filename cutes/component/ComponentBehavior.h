#pragma once
#include "../history/History.h"
#include "../history/Interation.h"

class ComponentBehavior
{
public:
    int pin;
    ComponentBehavior(int pin)
    {
        this->pin = pin;
    };
    void addHistory(int pin, int value)
    {
        Interation element = Interation(millis(), value, pin);
        history->list->add(element);
    };
};
