#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

class LaunchPadMotorValveIntegrationTests : public IntegrationTests
{
public:
    LaunchPadMotorValveIntegrationTests(){};
    void enter(String name)
    {
        Serial.println(name);
        delay(3000);
        launchPadMotorValve.setup();
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

LaunchPadMotorValveIntegrationTests integrationTests = LaunchPadMotorValveIntegrationTests();

test(testActivateMotor)
{
    integrationTests.enter("testActivateMotor");

    if (!launchPadMotorValve.buttonMotor->behavior->isRaisedHigh())
        fail();
    history->proceedTime(1 * 1000);

    assertTrue(launchPadMotorValve.buttonCancel->behavior->isRaisedLow());
    history->proceedTime(3 * 1000);

    assertTrue(launchPadMotorValve.motor->behavior->isRaisedHigh());

    history->proceedTime(0.2 * 1000);

    assertTrue(launchPadMotorValve.motor->behavior->isRaisedLow());

    integrationTests.exit();
}