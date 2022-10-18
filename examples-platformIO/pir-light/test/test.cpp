#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

class PirLightIntegrationTests : public IntegrationTests
{
public:
    PirLightIntegrationTests(){};
    void enter(String name)
    {
        Serial.println(name);
        delay(3000);
        pirLight.setup();
        pirLight.loop();
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

PirLightIntegrationTests integrationTests = PirLightIntegrationTests();

test(testLightOn)
{
    integrationTests.enter("testLightOn");

    if (!pirLight.pir->behavior->raiseHigh())
        fail();

    assertTrue(pirLight.light->behavior->isRaisedHigh());

    history->proceedTime(4 * 1000);

    integrationTests.exit();
}

test(testLightOff)
{
    integrationTests.enter("testLightOff");

    if (!pirLight.pir->behavior->raiseLow())
        fail();

    assertTrue(pirLight.light->behavior->isRaisedLow());

    history->proceedTime(4 * 1000);

    integrationTests.exit();
}