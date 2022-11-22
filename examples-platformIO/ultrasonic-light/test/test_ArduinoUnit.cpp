#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

class UltrasonicLightIntegrationTests : public IntegrationTests
{
public:
    UltrasonicLightIntegrationTests(){};
    void enter(String name)
    {
        Serial.println(name);
        delay(3000);
        ultrasonicLight.loop();
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

UltrasonicLightIntegrationTests integrationTests = UltrasonicLightIntegrationTests();

test(test_0to20)
{
    integrationTests.enter("test_0to20");

    assertTrue(ultrasonicLight.ultrasonic->behavior->isSensorViVf(0, 20));

    assertTrue(ultrasonicLight.light->behavior->isActuatorLow());

    integrationTests.exit();
}

test(test_0to20Decision)
{
    integrationTests.enter("test_0to20AndDecision");

    assertTrue(ultrasonicLight.ultrasonic->behavior->isSensorViVf(0, 20));

    assertTrue(ultrasonicLight.light->behavior->isActuatorLow());

    assertTrue(history->proceedTime(1 * 1000));

    integrationTests.exit();
}

test(test_20to30)
{
    integrationTests.enter("test_20to30");

    assertTrue(ultrasonicLight.ultrasonic->behavior->isSensorViVf(20, 30));

    assertTrue(ultrasonicLight.light->behavior->isActuatorHigh());
    assertTrue(ultrasonicLight.light->behavior->isActuatorLow());

    integrationTests.exit();
}

test(test_20to30Decision)
{
    integrationTests.enter("test_20to30Decision");

    assertTrue(ultrasonicLight.ultrasonic->behavior->isSensorViVf(20, 30));

    assertTrue(ultrasonicLight.light->behavior->isActuatorHigh());
    assertTrue(ultrasonicLight.light->behavior->isActuatorLow());

    assertTrue(history->proceedTime(1 * 1000));

    integrationTests.exit();
}

test(test_30toLarger)
{
    integrationTests.enter("test_30toLarger");

    assertTrue(ultrasonicLight.ultrasonic->behavior->isSensorViVf(30, 400));

    assertTrue(ultrasonicLight.light->behavior->isActuatorHigh());

    integrationTests.exit();
}

test(test_30toLargerDecision)
{
    integrationTests.enter("test_30toLargerDecision");

    assertTrue(ultrasonicLight.ultrasonic->behavior->isSensorViVf(30, 400));

    assertTrue(ultrasonicLight.light->behavior->isActuatorHigh());

    assertTrue(history->proceedTime(1 * 1000));

    integrationTests.exit();
}
