#include "../embedded_system/EmbeddedSystem.h"
#include "../component/ComponentBehavior.h"
#include "../store/Store.h"

#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
class Test
{
protected:
    EmbeddedSystem embeddedSystem;
    Store store;

public:
    void configuration();
    void setup();
    void loop();
};

class AbstractTest : public Test
{
public:
    EmbeddedSystem embeddedSystem;
    Store store;

public:
    // virtual void configuration() = 0;
    virtual void setup() = 0;
    virtual void loop() = 0;
};
#endif