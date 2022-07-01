#include "../../../unit-embedded-system-framework/test/Test.h"
#include "../src/main.cpp"
#include "../src/AUnit/src/AUnit.h"
#include "../../../unit-embedded-system-framework/store/Store.h"

class Test : public AbstractTest, TestOnce
{
    EmbeddedSystem embeddedSystem = pir_light;
    Store store;
    void setup() override
    {
        TestOnce::setup();
        TestRunner::setTimeout(30);
        TestRunner::exclude("*");
        // TestRunner::include("looping*");
        TestRunner::include("StatechartTest", "*");
    }
    void teardown() override
    {
        TestOnce::teardown();
    }
    void loop()
    {
        // arduino->loopArduino(statechart);
        TestRunner::run();
    }
};
