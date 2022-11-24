#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

class LaunchPadMotorValveSystemTests : public SystemTests
{
public:
    LaunchPadMotorValveSystemTests(){};
    void enter(String name)
    {
        Serial.println(name);
        delay(3000);
        launchPadMotorValve.loop();
    };

    void exit()
    {
        history->list->clear();
    };

    void run()
    {
        Test::run();
    }
};

LaunchPadMotorValveSystemTests systemTests = LaunchPadMotorValveSystemTests();

test(testActivateMotor)
{
    systemTests.enter("testActivateMotor");

    assertTrue(launchPadMotorValve.buttonMotor->behavior->isRaisedHigh());

    assertTrue(history->proceedTime(1 * 1000));

    assertTrue(launchPadMotorValve.buttonCancel->behavior->isRaisedLow());

    assertTrue(history->proceedTime(3 * 1000));

    assertTrue(launchPadMotorValve.motor->behavior->isRaisedHigh());

    assertTrue(history->proceedTime(0.2 * 1000));

    assertTrue(launchPadMotorValve.motor->behavior->isRaisedLow());

    systemTests.exit();
}