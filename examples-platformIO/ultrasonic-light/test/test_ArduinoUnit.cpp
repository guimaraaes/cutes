#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

#include "../../../cutes/history/History.h"
// #include "../../../cutes/test/Test.h"

// class CasesTest : public Test
// {

// public:
//     void setup()
//     {
//         ultrasonic_light.setup();
//     }
//     void loop()
//     {
//         Serial.println("loop test");
//         Test::run();
//     }
// };
// CasesTest *casesTest;

void configuration(String name)
{
    ultrasonic_light.setup();

    history->list->clear();
    Serial.println(name);
    delay(3000);
    ultrasonic_light.loop();
};

test(test_0to20)
{
    configuration("test_0to20");

    if (!ultrasonic_light.ultrasonic->behavior->raisedViVf(0, 20))
        fail();

    assertTrue(ultrasonic_light.light->behavior->isRaisedLow());

    // runner->proceed_time(4 * 1000);
}

test(test_20to30)
{
    configuration("test_20to30");

    if (!ultrasonic_light.ultrasonic->behavior->raisedViVf(20, 30))
        fail();

    assertTrue(ultrasonic_light.light->behavior->isRaisedHigh());
    assertTrue(ultrasonic_light.light->behavior->isRaisedLow());

    // runner->proceed_time(4 * 1000);
}

test(test_30toLarger)
{
    configuration("test_30toLarger");

    if (!ultrasonic_light.ultrasonic->behavior->raisedViVf(30, 400))
        fail();

    assertTrue(ultrasonic_light.light->behavior->isRaisedHigh());
}
