#include "../store/Store.h"
#include "../store/Interation.h"

#ifndef COMPONENTBEHAVIOR_H_INCLUDED
#define COMPONENTBEHAVIOR_H_INCLUDED

class ComponentBehavior
{
public:
    void addStore(int pin, int value)
    {
        Interation element = Interation(millis(), value, pin);
        store->list->add(element);
    };
};

#endif
