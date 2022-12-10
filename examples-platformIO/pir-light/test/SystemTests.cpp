#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

class PirLightSystemTests : public SystemTests
{
public:
    PirLightSystemTests(){};
    void enter(String name)
    {
        Serial.println(name);
        delay(3000);
        embeddedSystem.loop();
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

PirLightSystemTests systemTests = PirLightSystemTests();

test(testLightOn)
{
    systemTests.enter("testLightOn");

    assertTrue(embeddedSystem.pir->behavior->isSensorHigh());

    assertTrue(embeddedSystem.light->behavior->isActuatorHigh());

    assertTrue(history->proceedTime(4 * 1000));

    systemTests.exit();
}

test(testLightOff)
{
    systemTests.enter("testLightOff");

    assertTrue(embeddedSystem.pir->behavior->isSensorLow());

    assertTrue(embeddedSystem.light->behavior->isActuatorLow());

    assertTrue(history->proceedTime(4 * 1000));

    systemTests.exit();
}