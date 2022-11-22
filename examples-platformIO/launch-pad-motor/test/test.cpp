#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

class LaunchPadMotorIntegrationTests : public IntegrationTests
{
public:
    LaunchPadMotorIntegrationTests(){};
    void enter(String name)
    {
        Serial.println(name);
        delay(3000);
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

    assertTrue(launchPadMotor.buttonActuation->behavior->isSensorHigh());

    assertTrue(launchPadMotor.ledRed->behavior->isActuatorHigh());

    integrationTests.exit();
}

test(testState2Actuation)
{
    integrationTests.enter("testState2Actuation");

    assertTrue(launchPadMotor.buttonActuation->behavior->isSensorHigh());

    assertTrue(history->proceedTime(5 * 1000));

    assertTrue(launchPadMotor.ledGreen->behavior->isActuatorHigh());

    integrationTests.exit();
}

test(testStateCancelActuation)
{
    integrationTests.enter("testStateCancelActuation");

    assertTrue(launchPadMotor.buttonActuation->behavior->isSensorHigh());

    assertTrue(history->proceedTime(7 * 1000));

    assertTrue(launchPadMotor.buttonActuation->behavior->isSensorHigh());

    assertTrue(launchPadMotor.motor->behavior->isActuatorLow());

    integrationTests.exit();
}

test(testActuation)
{
    integrationTests.enter("testActuation");

    assertTrue(launchPadMotor.buttonActuation->behavior->isSensorHigh());

    assertTrue(history->proceedTime(7 * 1000));

    assertTrue(launchPadMotor.buttonActuation->behavior->isSensorLow());

    assertTrue(launchPadMotor.motor->behavior->isActuatorHigh());

    integrationTests.exit();
}

test(testActuationTime)
{
    integrationTests.enter("testActuation");

    assertTrue(launchPadMotor.buttonActuation->behavior->isSensorHigh());

    assertTrue(history->proceedTime(7 * 1000));

    assertTrue(launchPadMotor.buttonActuation->behavior->isSensorLow());

    assertTrue(launchPadMotor.motor->behavior->isActuatorHigh());

    assertTrue(history->proceedTime(200));

    assertTrue(launchPadMotor.motor->behavior->isActuatorLow());

    integrationTests.exit();
}
