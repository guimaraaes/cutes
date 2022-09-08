#pragma once
#include "../embedded_system/EmbeddedSystem.h"
#include "../component/ComponentBehavior.h"
#include "../history/History.h"

class TestCutes
{

public:
    EmbeddedSystem *embeddedsystem;
    History *history;
    virtual void setup() = 0;
    virtual void teardown() = 0;
    virtual void beforeEach(String name) = 0;
    virtual void case_test(String name) = 0;

    virtual bool assertTrue(bool value) = 0;
    virtual void failTest() = 0;
    virtual void passTest() = 0;
    virtual void run() = 0;
};
