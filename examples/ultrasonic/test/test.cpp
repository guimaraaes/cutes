#include "../src/AUnit/src/AUnit.h"
// #include "../.pio/libdeps/uno/AUnit/src/AUnit.h"
// #include <AUnit.h>
using namespace aunit;
#include "../arduino/arduino.cpp"
Arduino *arduino;

#include "../statechart/statechart.cpp"

class StatechartTest : public TestOnce
{

protected:
    void setup() override
    {
        TestOnce::setup();
        arduino->setupArduino();
    }
    void teardown() override
    {
        delete statechart;
        TestOnce::teardown();
    }

public:
    void setupTest()
    {
        TestRunner::setTimeout(30);
        TestRunner::exclude("*");
        // TestRunner::include("looping*");
        TestRunner::include("StatechartTest", "*");
    }

    void loopTest()
    {
        // arduino->loopArduino(statechart);
        TestRunner::run();
    }
};

// test(StatechartTest, testLightBeginOFF)
// {
//     arduino->loopArduino();
//     statechart->enter();

//     assertTrue(statechart->light->isRaisedOFF());

//     // assertTrue(statechart->isStateActive(Statechart::StateLightOff));
// }

test(StatechartTest, testInterval_0to20)
{
    Serial.println("testInterval_0to20");
    delay(2000);

    arduino->loopArduino();
    statechart->enter();

    statechart->ultrasonic->raise_0to20();

    assertTrue(statechart->light->isRaisedOFF());

    // runner->proceed_time(4 * 1000);
}
test(StatechartTest, _20to30)
{
    Serial.println("_20to30");

    delay(2000);
    arduino->loopArduino();

    statechart->enter();

    statechart->ultrasonic->raise_20to30();

    assertTrue(statechart->light->isRaisedONOFF());

    // runner->proceed_time(4 * 1000);
}
test(StatechartTest, _30toLarger)
{
    Serial.println("_30toLarger");

    delay(2000);
    arduino->loopArduino();

    statechart->enter();

    statechart->ultrasonic->raise_30toLarger();

    assertTrue(statechart->light->isRaisedON());

    // runner->proceed_time(4 * 1000);
}