#pragma once

#ifdef SYSTEM_TESTS_ENVIROMENT
#include "ComponentBehavior.h"
#include "../History/History.h"
#include "../History/Interaction.h"
#endif

class Component
{
public:
    int pin;
#ifdef SYSTEM_TESTS_ENVIROMENT
    ComponentBehavior *behavior;
    History *history = History::getInstance();

#endif
    void addHistory(int pin, int value)
    {
#ifdef SYSTEM_TESTS_ENVIROMENT
        Interaction *interaction = new Interaction(millis(), value, pin);
        history->list.add(interaction);

#endif
    };

    void unitTest();

    void assertValue(int value);
};
