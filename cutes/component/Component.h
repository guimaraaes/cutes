#pragma once

#ifdef TEST_ENVIROMENT
#include "ComponentBehavior.h"
#include "../history/History.h"
#endif

class Component
{
public:
    int pin;
#ifdef TEST_ENVIROMENT
    ComponentBehavior *behavior;
    History history;
#endif
};
