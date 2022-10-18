#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

class LaunchPadMotorIntegrationTests : public IntegrationTests
{
public:
    LaunchPadMotorIntegrationTests(){};
    void enter(String name)
    {
        Serial.println(name);
        delay(3000);
        launchPadMotor.setup();
        launchPadMotor.loop();
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

LaunchPadMotorIntegrationTests integrationTests = LaunchPadMotorIntegrationTests();

test(testState1Actuation)
{
    integrationTests.enter("testState1Actuation");

    if (!launchPadMotor.buttonActuation->behavior->isRaisedHigh())
        fail();

    assertTrue(launchPadMotor.ledRed->behavior->isRaisedHigh());

    integrationTests.exit();
}

test(testState2Actuation)
{
    integrationTests.enter("testState2Actuation");

    if (!launchPadMotor.buttonActuation->behavior->isRaisedHigh())
        fail();

    history->proceedTime(5 * 1000);

    assertTrue(launchPadMotor.ledGreen->behavior->isRaisedHigh());

    integrationTests.exit();
}

test(testStateCancelActuation)
{
    integrationTests.enter("testStateCancelActuation");

    if (!launchPadMotor.buttonActuation->behavior->isRaisedHigh())
        fail();

    history->proceedTime(7 * 1000);

    if (!launchPadMotor.buttonActuation->behavior->isRaisedHigh())
        fail();

    assertTrue(launchPadMotor.motor->behavior->isRaisedLow());

    integrationTests.exit();
}

test(testActuation)
{
    integrationTests.enter("testActuation");

    if (!launchPadMotor.buttonActuation->behavior->isRaisedHigh())
        fail();

    history->proceedTime(7 * 1000);

    if (!launchPadMotor.buttonActuation->behavior->isRaisedLow())
        fail();

    assertTrue(launchPadMotor.motor->behavior->isRaisedHigh());

    integrationTests.exit();
}

test(testActuationTime)
{
    integrationTests.enter("testActuation");

    if (!launchPadMotor.buttonActuation->behavior->isRaisedHigh())
        fail();

    history->proceedTime(7 * 1000);

    if (!launchPadMotor.buttonActuation->behavior->isRaisedLow())
        fail();

    assertTrue(launchPadMotor.motor->behavior->isRaisedHigh());

    history->proceedTime(200);

    assertTrue(launchPadMotor.motor->behavior->isRaisedLow());

    integrationTests.exit();
}
