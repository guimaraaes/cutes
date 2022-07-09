#include "../src/AUnit/src/AUnit.h"
using namespace aunit;

#include "../../../unit-embedded-system-framework/store/Store.h"
#include "../../../unit-embedded-system-framework/test/Test.h"

class TestPirLigh : public TestOnce, TestCutes
{
public:
    void setup() override
    {
        TestOnce::setup();
        pir_light.setup();
    };
    void teardown() override
    {
        TestOnce::teardown();
    };
};

void configuration(String name)
{
    store->list->clear();
    Serial.println(name);
    delay(3000);
    pir_light.loop();
};

testF(TestPirLigh, testLightOn)
{
    configuration("testLightOn");

    if (!pir_light.pir->behavior->raiseHigh(3))
        failTestNow();

    assertTrue(pir_light.light->behavior->isRaisedHigh(13));

    // runner->proceed_time(4 * 1000);
}

testF(TestPirLigh, testLightOff)
{
    configuration("testLightOff");

    if (!pir_light.pir->behavior->raiseLow(3))
        failTestNow();

    assertTrue(pir_light.light->behavior->isRaisedLow(13));

    // runner->proceed_time(4 * 1000);
}