#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

#include "../../../cutes/store/Store.h"

void configuration(String name)
{
    pir_light.setup();

    store->list->clear();
    Serial.println(name);
    delay(3000);
    pir_light.loop();
};

test(testLightOn)
{
    configuration("testLightOn");

    if (!pir_light.pir->behavior->raiseHigh())
        fail();

    assertTrue(pir_light.light->behavior->isRaisedHigh());

    // runner->proceed_time(4 * 1000);
}

test(testLightOff)
{
    configuration("testLightOff");

    if (!pir_light.pir->behavior->raiseLow())
        fail();

    assertTrue(pir_light.light->behavior->isRaisedLow());

    // runner->proceed_time(4 * 1000);
}