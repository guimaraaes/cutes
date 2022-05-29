#include <AUnit.h>
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

test(StatechartTest, testLightBeginOFF)
{
    arduino->loopArduino();
    statechart->enter();

    assertTrue(statechart->light->isRaisedOFF());

    // assertTrue(statechart->isStateActive(Statechart::StateLightOff));
}
test(StatechartTest, testLightONOFF)
{
    arduino->loopArduino();

    statechart->enter();

    statechart->ultrasonic->raise_20a30();

    assertTrue(statechart->light->isRaisedONOFF());

    // assertTrue(statechart->isStateActive(Statechart::StateLightOnOff));
}
test(StatechartTest, testLightONOFFtoLightOFF)
{
    arduino->loopArduino();

    statechart->enter();

    statechart->ultrasonic->raise_20a30();

    statechart->ultrasonic->raise_10a20();

    assertTrue(statechart->light->isRaisedOFF());

    // assertTrue(statechart->isStateActive(Statechart::StateLightOff));
}
test(StatechartTest, testLightON)
{
    arduino->loopArduino();

    statechart->enter();

    statechart->ultrasonic->raise_20a30();

    statechart->ultrasonic->raise_30();

    assertTrue(statechart->light->isRaisedON());

    // assertTrue(statechart->isStateActive(Statechart::StateLightOn));
}
