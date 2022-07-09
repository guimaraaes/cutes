#pragma once
#include "../store/Store.h"
#include "../store/Interation.h"

class ComponentBehavior
{
public:
    void addStore(int pin, int value)
    {
        Interation element = Interation(millis(), value, pin);
        store->list->add(element);
    };
};
