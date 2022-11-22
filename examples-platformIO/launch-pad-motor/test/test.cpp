#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

class LaunchPadMotorSystemTests : public SystemTests
{
public:
    LaunchPadMotorSystemTests(){};
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

LaunchPadMotorSystemTests systemTests = LaunchPadMotorSystemTests();

test(testState1Actuation)
{
    systemTests.enter("testState1Actuation");

    assertTrue(launchPadMotor.buttonActuation->behavior->isSensorHigh());

    assertTrue(launchPadMotor.ledRed->behavior->isActuatorHigh());

    systemTests.exit();
}

test(testState2Actuation)
{
    systemTests.enter("testState2Actuation");

    assertTrue(launchPadMotor.buttonActuation->behavior->isSensorHigh());

    assertTrue(history->proceedTime(5 * 1000));

    assertTrue(launchPadMotor.ledGreen->behavior->isActuatorHigh());

    systemTests.exit();
}

test(testStateCancelActuation)
{
    systemTests.enter("testStateCancelActuation");

    assertTrue(launchPadMotor.buttonActuation->behavior->isSensorHigh());

    assertTrue(history->proceedTime(7 * 1000));

    assertTrue(launchPadMotor.buttonActuation->behavior->isSensorHigh());

    assertTrue(launchPadMotor.motor->behavior->isActuatorLow());

    systemTests.exit();
}

test(testActuation)
{
    systemTests.enter("testActuation");

    assertTrue(launchPadMotor.buttonActuation->behavior->isSensorHigh());

    assertTrue(history->proceedTime(7 * 1000));

    assertTrue(launchPadMotor.buttonActuation->behavior->isSensorLow());

    assertTrue(launchPadMotor.motor->behavior->isActuatorHigh());

    systemTests.exit();
}

test(testActuationTime)
{
    systemTests.enter("testActuation");

    assertTrue(launchPadMotor.buttonActuation->behavior->isSensorHigh());

    assertTrue(history->proceedTime(7 * 1000));

    assertTrue(launchPadMotor.buttonActuation->behavior->isSensorLow());

    assertTrue(launchPadMotor.motor->behavior->isActuatorHigh());

    assertTrue(history->proceedTime(200));

    assertTrue(launchPadMotor.motor->behavior->isActuatorLow());

    systemTests.exit();
}
