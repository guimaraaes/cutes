#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

class UltrasonicLightSystemTests : public SystemTests
{
public:
    UltrasonicLightSystemTests(){};
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

UltrasonicLightSystemTests systemTests = UltrasonicLightSystemTests();

test(test_0to30)
{
    systemTests.enter("test_0to30");

    assertTrue(ultrasonicLight.ultrasonic->behavior->isSensorViVf(0, 30));

    assertTrue(ultrasonicLight.light->behavior->isActuatorLow());

    systemTests.exit();
}

test(test_0to20Decision)
{
    systemTests.enter("test_0to30AndDecision");

    assertTrue(ultrasonicLight.ultrasonic->behavior->isSensorViVf(0, 20));

    assertTrue(ultrasonicLight.light->behavior->isActuatorLow());

    assertTrue(history->proceedTime(1 * 1000));

    systemTests.exit();
}

test(test_30toLarger)
{
    systemTests.enter("test_30toLarger");

    assertTrue(ultrasonicLight.ultrasonic->behavior->isSensorViVf(30, 400));

    assertTrue(ultrasonicLight.light->behavior->isActuatorHigh());

    systemTests.exit();
}

test(test_30toLargerDecision)
{
    systemTests.enter("test_30toLargerDecision");

    assertTrue(ultrasonicLight.ultrasonic->behavior->isSensorViVf(30, 400));

    assertTrue(ultrasonicLight.light->behavior->isActuatorHigh());

    assertTrue(history->proceedTime(1 * 1000));

    systemTests.exit();
}
