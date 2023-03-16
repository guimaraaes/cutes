#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

class LaunchPadMotorValveSystemTests : public SystemTests
{
public:
    LaunchPadMotorValveSystemTests(){};
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

LaunchPadMotorValveSystemTests systemTests = LaunchPadMotorValveSystemTests();

test(testCancelDecisionActivateValve)
{
    systemTests.enter("testCancelDecisionActivateValve");
    assertTrue(embeddedSystem.buttonValve->behavior->raiseSensorHigh());
    assertTrue(embeddedSystem.buttonCancel->behavior->raiseSensorHigh());
    assertTrue(embeddedSystem.valve->behavior->isActuatorLow());
    assertTrue(embeddedSystem.motor->behavior->isActuatorLow());
    systemTests.exit();
}

test(testDecisionActivateValve1)
{
    systemTests.enter("testDecisionActivateValve1");
    assertTrue(embeddedSystem.buttonValve->behavior->raiseSensorHigh());
    assertTrue(embeddedSystem.buttonCancel->behavior->raiseSensorLow());
    history->proceedTime(3.001 * 1000);
    assertTrue(embeddedSystem.valve->behavior->isActuatorHigh());
    history->proceedTime(20 * 1000);
    assertTrue(embeddedSystem.valve->behavior->isActuatorLow());
    assertTrue(embeddedSystem.motor->behavior->isActuatorLow());
    systemTests.exit();
}

test(testDecisionActivateValve2)
{
    systemTests.enter("testDecisionActivateValve2");
    assertTrue(embeddedSystem.buttonValve->behavior->raiseSensorHigh());
    assertTrue(embeddedSystem.buttonCancel->behavior->raiseSensorLow());
    history->proceedTime(3.001 * 1000);
    history->proceedTime(20 * 1000);
    assertTrue(embeddedSystem.buttonValve->behavior->raiseSensorHigh());
    assertTrue(embeddedSystem.buttonCancel->behavior->raiseSensorLow());
    history->proceedTime(3.001 * 1000);
    assertTrue(embeddedSystem.valve->behavior->isActuatorHigh());
    history->proceedTime(32 * 1000);
    assertTrue(embeddedSystem.valve->behavior->isActuatorLow());
    assertTrue(embeddedSystem.motor->behavior->isActuatorLow());
    systemTests.exit();
}

test(testDecisionActivateValve3)
{
    systemTests.enter("testDecisionActivateValve3");
    assertTrue(embeddedSystem.buttonValve->behavior->raiseSensorHigh());
    assertTrue(embeddedSystem.buttonCancel->behavior->raiseSensorLow());
    history->proceedTime(3.001 * 1000);
    history->proceedTime(20 * 1000);
    assertTrue(embeddedSystem.buttonValve->behavior->raiseSensorHigh());
    assertTrue(embeddedSystem.buttonCancel->behavior->raiseSensorLow());
    history->proceedTime(3.001 * 1000);
    history->proceedTime(32 * 1000);
    assertTrue(embeddedSystem.buttonValve->behavior->raiseSensorHigh());
    assertTrue(embeddedSystem.buttonCancel->behavior->raiseSensorLow());
    history->proceedTime(3.001 * 1000);
    assertTrue(embeddedSystem.valve->behavior->isActuatorHigh());
    history->proceedTime(40 * 1000);
    assertTrue(embeddedSystem.valve->behavior->isActuatorLow());
    assertTrue(embeddedSystem.motor->behavior->isActuatorLow());
    systemTests.exit();
}

test(testDecisionActivateValveOutlier)
{
    systemTests.enter("testDecisionActivateValveOutlier");
    assertTrue(embeddedSystem.buttonValve->behavior->raiseSensorHigh());
    assertTrue(embeddedSystem.buttonCancel->behavior->raiseSensorLow());
    history->proceedTime(3.001 * 1000);
    history->proceedTime(20 * 1000);
    assertTrue(embeddedSystem.buttonValve->behavior->raiseSensorHigh());
    assertTrue(embeddedSystem.buttonCancel->behavior->raiseSensorLow());
    history->proceedTime(3.001 * 1000);
    history->proceedTime(32 * 1000);
    assertTrue(embeddedSystem.buttonValve->behavior->raiseSensorHigh());
    assertTrue(embeddedSystem.buttonCancel->behavior->raiseSensorLow());
    history->proceedTime(3.001 * 1000);
    assertTrue(embeddedSystem.valve->behavior->isActuatorHigh());
    history->proceedTime(40 * 1000);
    assertTrue(embeddedSystem.buttonValve->behavior->raiseSensorHigh());
    assertTrue(embeddedSystem.buttonCancel->behavior->raiseSensorLow());
    history->proceedTime(3.001 * 1000);
    assertTrue(embeddedSystem.valve->behavior->isActuatorLow());
    assertTrue(embeddedSystem.motor->behavior->isActuatorLow());
    systemTests.exit();
}

test(testCancelDecisionActivateMotor)
{
    systemTests.enter("testCancelDecisionActivateMotor");
    assertTrue(embeddedSystem.buttonMotor->behavior->raiseSensorHigh());
    assertTrue(embeddedSystem.buttonCancel->behavior->raiseSensorHigh());
    assertTrue(embeddedSystem.motor->behavior->isActuatorLow());
    assertTrue(embeddedSystem.valve->behavior->isActuatorLow());
    systemTests.exit();
}

test(testActivateMotor)
{
    systemTests.enter("testActivateMotor");
    assertTrue(embeddedSystem.buttonMotor->behavior->raiseSensorHigh());
    assertTrue(embeddedSystem.buttonCancel->behavior->raiseSensorLow());
    history->proceedTime(3.001 * 1000);
    assertTrue(embeddedSystem.motor->behavior->isActuatorHigh());
    systemTests.exit();
}

test(testDecisionActivateMotorTime)
{
    systemTests.enter("testDecisionActivateMotorTime");
    assertTrue(embeddedSystem.buttonMotor->behavior->raiseSensorHigh());
    assertTrue(embeddedSystem.buttonCancel->behavior->raiseSensorLow());
    history->proceedTime(3.001 * 1000);
    assertTrue(embeddedSystem.motor->behavior->isActuatorHigh());
    history->proceedTime(0.2 * 1000);
    assertTrue(embeddedSystem.motor->behavior->isActuatorLow());
    assertTrue(embeddedSystem.valve->behavior->isActuatorLow());
    systemTests.exit();
}