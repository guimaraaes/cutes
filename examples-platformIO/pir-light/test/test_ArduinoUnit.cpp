#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

#include "../../../cutes/history/History.h"

void configuration(String name)
{
    pir_light.setup();

    history->list->clear();
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

    if (!pir_light.light->behavior->proceed_time(4 * 1000))
        fail();
}

test(testLightOff)
{
    configuration("testLightOff");

    if (!pir_light.pir->behavior->raiseLow())
        fail();

    assertTrue(pir_light.light->behavior->isRaisedLow());

    if (!pir_light.light->behavior->proceed_time(4 * 1000))
        fail();
}