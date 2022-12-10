#pragma once

#ifdef SYSTEM_TESTS_ENVIROMENT
#include "ComponentBehavior.h"
#include "../History/History.h"
#include "../History/Interation.h"
#endif

class Component
{
public:
    int pin;
#ifdef SYSTEM_TESTS_ENVIROMENT
    ComponentBehavior *behavior;
    History *history;
#endif
    void addHistory(int pin, int value)
    {
#ifdef SYSTEM_TESTS_ENVIROMENT
        Interation element = Interation(millis(), value, pin);
        history->list->add(element);
#endif
    };

    void unitTest();

    void assertValue(int value);
};
