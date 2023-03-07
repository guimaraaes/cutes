#pragma once
#include "../History/History.h"
#include "../History/Interaction.h"

class ComponentBehavior
{

public:
    int pin;
    History *history = History::getInstance();

    ComponentBehavior(int pin)
    {
        this->pin = pin;
    };
};
