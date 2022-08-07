#include "../src/AUnit/src/AUnit.h"
using namespace aunit;

#include "../../../cutes/history/History.h"
#include "../../../cutes/test/Test.h"

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
    history->list->clear();
    Serial.println(name);
    delay(3000);
    pir_light.loop();
};

testF(TestPirLigh, testLightOn)
{
    configuration("testLightOn");

    if (!pir_light.pir->behavior->raiseHigh())
        failTestNow();

    assertTrue(pir_light.light->behavior->isRaisedHigh());

    if (!pir_light.light->behavior->proceed_time(4 * 1000))
        failTestNow();
}

testF(TestPirLigh, testLightOff)
{
    configuration("testLightOff");

    if (!pir_light.pir->behavior->raiseLow())
        failTestNow();

    assertTrue(pir_light.light->behavior->isRaisedLow());

    if (!pir_light.light->behavior->proceed_time(4 * 1000))
        failTestNow();
}