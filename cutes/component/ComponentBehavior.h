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

    bool proceed_time(int time)
    {
        Interation element1 = history->list->shift();
        Interation element2 = history->list->get(0);

        return (element2.time - element1.time) >= time;
    }
};
