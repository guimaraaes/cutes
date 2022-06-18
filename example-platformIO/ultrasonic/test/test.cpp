#include "../src/AUnit/src/AUnit.h"
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

test(StatechartTest, test_0to20)
{
    statechart->list->clear();
    Serial.println("test_0to20");
    delay(3000);

    arduino->loopArduino();

    if (!statechart->ultrasonic->raise_0to20())
        failTestNow();

    assertTrue(statechart->light->isRaisedOFF());

    // runner->proceed_time(4 * 1000);
}
test(StatechartTest, test_20to30)
{
    statechart->list->clear();
    Serial.println("test_20to30");
    delay(3000);

    arduino->loopArduino();

    statechart->enter();
    if (!statechart->ultrasonic->raise_20to30())
        failTestNow();

    assertTrue(statechart->light->isRaisedONOFF());

    // runner->proceed_time(4 * 1000);
}
test(StatechartTest, test_30toLarger)
{
    statechart->list->clear();
    Serial.println("test_30toLarger");

    delay(3000);
    arduino->loopArduino();

    statechart->enter();
    if (!statechart->ultrasonic->raise_30toLarger())
        failTestNow();

    assertTrue(statechart->light->isRaisedON());

    // runner->proceed_time(4 * 1000);
}

// test(StatechartTest, test_30toLargerTO_0to20)
// {
//     statechart->list->clear();
//     Serial.println("_30toLarger to _0to20");

//     delay(2000);
//     arduino->loopArduino();

//     statechart->enter();
//     if (!statechart->ultrasonic->raise_30toLarger())
//         failTestNow();

//     assertTrue(statechart->light->isRaisedON());

//     arduino->loopArduino();

//     // if (!runner->proceed_time(1 * 1000))
//     //     failTestNow();

//     if (!statechart->ultrasonic->raise_0to20())
//         failTestNow();

//     assertTrue(statechart->light->isRaisedOFF());
// }