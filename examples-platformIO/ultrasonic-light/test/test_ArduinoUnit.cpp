#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

class UltrasonicLightIntegrationTests : public IntegrationTests
{
public:
    UltrasonicLightIntegrationTests(){};
    void enter(String name)
    {
        Serial.println(name);
        delay(3000);
        ultrasonicLight.setup();
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

    if (!ultrasonicLight.ultrasonic->behavior->raisedViVf(0, 20))
        fail();

    assertTrue(ultrasonicLight.light->behavior->isRaisedLow());

    if (!history->proceedTime(4 * 1000))
        fail();

    integrationTests.exit();
}

test(test_20to30)
{
    integrationTests.enter("test_20to30");

    if (!ultrasonicLight.ultrasonic->behavior->raisedViVf(20, 30))
        fail();

    assertTrue(ultrasonicLight.light->behavior->isRaisedHigh());
    assertTrue(ultrasonicLight.light->behavior->isRaisedLow());

    if (!history->proceedTime(4 * 1000))
        fail();

    integrationTests.exit();
}

test(test_30toLarger)
{
    integrationTests.enter("test_30toLarger");

    if (!ultrasonicLight.ultrasonic->behavior->raisedViVf(30, 400))
        fail();

    assertTrue(ultrasonicLight.light->behavior->isRaisedHigh());

    if (!history->proceedTime(4 * 1000))
        fail();

    integrationTests.exit();
}
