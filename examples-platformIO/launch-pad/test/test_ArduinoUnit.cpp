#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

#include "../../../cutes/store/Store.h"
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

    if (!launch_pad.buttonMotor->behavior->isRaisedHigh())
        fail();
    // runner->proceed_time(1 * 1000);

    assertTrue(launch_pad.buttonCancel->behavior->isRaisedLow());
    // runner->proceed_time(3 * 1000);

    assertTrue(launch_pad.motor->behavior->isRaisedHigh());

    // runner->proceed_time(0,2 * 1000);

    assertTrue(launch_pad.motor->behavior->isRaisedLow());
}