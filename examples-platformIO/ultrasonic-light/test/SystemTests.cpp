#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

class UltrasonicLightSystemTests : public SystemTests
{
public:
    UltrasonicLightSystemTests(){};

    void enter(String name)
    {
        Serial.println(name);
        delay(5000);
        setup();
        embeddedSystem.loopES();
        history->getHistory();
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

UltrasonicLightSystemTests systemTests = UltrasonicLightSystemTests();

test(test_0to30)
{
    systemTests.enter("test_0to30");
    assertTrue(embeddedSystem.ultrasonic->behavior->raiseSensorViVf(0, 30));
    assertTrue(embeddedSystem.light->behavior->isActuatorLow());
    history->proceedTime(1000);
    systemTests.exit();
}

test(test_30toLarger)
{
    systemTests.enter("test_30toLarger");
    assertTrue(embeddedSystem.ultrasonic->behavior->raiseSensorViVf(30, 400));
    assertTrue(embeddedSystem.light->behavior->isActuatorHigh());
    // history->proceedTime(1000);
    systemTests.exit();
}
