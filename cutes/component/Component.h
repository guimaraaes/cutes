#pragma once

#include "ComponentBehavior.h"
#include "../store/Store.h"

class Component
{
public:
    int pin;
    ComponentBehavior *componentBehavior;
    Store store;
};
