#include "../embedded_system/EmbeddedSystem.h"
#include "../component/ComponentBehavior.h"
#include "../history/History.h"

#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
class TestCutes
{

public:
    // void configuration(String name);
    virtual void setup() = 0;
    virtual void teardown() = 0;
};

#endif