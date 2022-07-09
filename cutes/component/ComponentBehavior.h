#pragma once
#include "../store/Store.h"
#include "../store/Interation.h"

class ComponentBehavior
{
public:
    int pin;
    ComponentBehavior(int pin)
    {
        this->pin = pin;
    };
    void addStore(int pin, int value)
    {
        Interation element = Interation(millis(), value, pin);
        store->list->add(element);
    };
};
