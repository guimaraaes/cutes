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

    assertTrue(launchPadMotorValve.buttonMotor->behavior->isSensorHigh());

    assertTrue(history->proceedTime(1 * 1000));

    assertTrue(launchPadMotorValve.buttonCancel->behavior->isSensorLow());

    assertTrue(history->proceedTime(3 * 1000));

    assertTrue(launchPadMotorValve.motor->behavior->isActuatorHigh());

    assertTrue(history->proceedTime(0.2 * 1000));

    assertTrue(launchPadMotorValve.motor->behavior->isActuatorLow());

    systemTests.exit();
}