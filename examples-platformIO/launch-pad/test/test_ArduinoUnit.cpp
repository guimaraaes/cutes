#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

#include "../../../unit-embedded-system-framework/store/Store.h"
void configuration(String name)
{
    launch_pad.setup();

    store->list->clear();
    Serial.println(name);
    delay(3000);
    launch_pad.loop();
};

test(testActivateMotor)
{
    configuration("testActivateMotor");

    if (!launch_pad.buttonMotor->behavior->isRaisedHigh(launch_pad.buttonMotor->pin))
        fail();
    // runner->proceed_time(1 * 1000);

    assertTrue(launch_pad.buttonCancel->behavior->isRaisedLow(launch_pad.buttonCancel->pin));
    // runner->proceed_time(3 * 1000);

    assertTrue(launch_pad.motor->behavior->isRaisedHigh(launch_pad.motor->pin));

    // runner->proceed_time(0,2 * 1000);

    assertTrue(launch_pad.motor->behavior->isRaisedLow(launch_pad.motor->pin));
}