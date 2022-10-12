#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

#include "../../../cutes/history/History.h"
void enter(String name)
{
    Serial.println(name);
    delay(3000);
    ultrasonic_light.setup();
    ultrasonic_light.loop();
};

void exit()
{
    history->list->clear();
};

test(test_0to20)
{
    enter("test_0to20");

    if (!ultrasonic_light.ultrasonic->behavior->raisedViVf(0, 20))
        fail();

    assertTrue(ultrasonic_light.light->behavior->isRaisedLow());

    if (!ultrasonic_light.light->behavior->proceed_time(4 * 1000))
        fail();

    exit();
}

test(test_20to30)
{
    enter("test_20to30");

    if (!ultrasonic_light.ultrasonic->behavior->raisedViVf(20, 30))
        fail();

    assertTrue(ultrasonic_light.light->behavior->isRaisedHigh());
    assertTrue(ultrasonic_light.light->behavior->isRaisedLow());

    if (!ultrasonic_light.light->behavior->proceed_time(4 * 1000))
        fail();

    exit();
}

test(test_30toLarger)
{
    enter("test_30toLarger");

    if (!ultrasonic_light.ultrasonic->behavior->raisedViVf(30, 400))
        fail();

    assertTrue(ultrasonic_light.light->behavior->isRaisedHigh());

    if (!ultrasonic_light.light->behavior->proceed_time(4 * 1000))
        fail();

    exit();
}
