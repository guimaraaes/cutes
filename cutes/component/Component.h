#pragma once

#include "ComponentBehavior.h"
#include "../history/History.h"

class Component
{
public:
    int pin;
    ComponentBehavior *componentBehavior;
    History history;
};
