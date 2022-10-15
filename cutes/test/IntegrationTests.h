#pragma once
#include "../embedded_system/EmbeddedSystem.h"
#include "../component/ComponentBehavior.h"
#include "../history/History.h"

class IntegrationTests
{

public:
    EmbeddedSystem *embeddedsystem;
    History *history;
    virtual void enter(String name) = 0;
    virtual void exit() = 0;
};
