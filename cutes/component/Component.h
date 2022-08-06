#pragma once

#ifdef TEST_ENVIROMENT
#include "ComponentBehavior.h"
#include "../history/History.h"
#include "../history/Interation.h"
#endif

class Component
{
public:
    int pin;
#ifdef TEST_ENVIROMENT
    ComponentBehavior *behavior;
    // History history;
#endif
    void addHistory(int pin, int value)
    {
#ifdef TEST_ENVIROMENT
        Interation element = Interation(millis(), value, pin);
        history->list->add(element);
#endif
    };
};
