#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

class LaunchPadMotorSystemTests : public SystemTests
{
public:
    LaunchPadMotorSystemTests(){};
    void enter(String name)
    {
        Serial.println(name);
        delay(3000);
        embeddedSystem.loopES();
    };

    void exit()
    {
        history->list.clear();
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

    assertTrue(embeddedSystem.buttonActuation->behavior->raiseSensorHigh());

    assertTrue(embeddedSystem.ledRed->behavior->isActuatorHigh());

    systemTests.exit();
}

test(testState2Actuation)
{
    systemTests.enter("testState2Actuation");

    assertTrue(embeddedSystem.buttonActuation->behavior->raiseSensorHigh());

    assertTrue(history->proceedTime(5 * 1000));

    assertTrue(embeddedSystem.ledGreen->behavior->isActuatorHigh());

    systemTests.exit();
}

test(testStateCancelActuation)
{
    systemTests.enter("testStateCancelActuation");

    assertTrue(embeddedSystem.buttonActuation->behavior->raiseSensorHigh());

    assertTrue(history->proceedTime(7 * 1000));

    assertTrue(embeddedSystem.buttonActuation->behavior->raiseSensorHigh());

    assertTrue(embeddedSystem.motor->behavior->isActuatorLow());

    systemTests.exit();
}

test(testActuation)
{
    systemTests.enter("testActuation");

    assertTrue(embeddedSystem.buttonActuation->behavior->raiseSensorHigh());

    assertTrue(history->proceedTime(7 * 1000));

    assertTrue(embeddedSystem.buttonActuation->behavior->raiseSensorLow());

    assertTrue(embeddedSystem.motor->behavior->isActuatorHigh());

    systemTests.exit();
}

test(testActuationTime)
{
    systemTests.enter("testActuation");

    assertTrue(embeddedSystem.buttonActuation->behavior->raiseSensorHigh());

    assertTrue(history->proceedTime(7 * 1000));

    assertTrue(embeddedSystem.buttonActuation->behavior->raiseSensorLow());

    assertTrue(embeddedSystem.motor->behavior->isActuatorHigh());

    assertTrue(history->proceedTime(200));

    assertTrue(embeddedSystem.motor->behavior->isActuatorLow());

    systemTests.exit();
}
