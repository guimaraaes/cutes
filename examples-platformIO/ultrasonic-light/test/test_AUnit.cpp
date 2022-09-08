#include "../src/AUnit/src/AUnit.h"
using namespace aunit;

#include "../../../cutes/history/History.h"
// #include "../../../cutes/test/units-adapters/AdapterAUnit.h"

class TestUltrasonic : public TestOnce
{
public:
    void setup() override
    {
        TestOnce::setup();
        ultrasonic_light.setup();
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
    ultrasonic_light.loop();
};

testF(TestUltrasonic, test_0to20)
{
    configuration("test_0to20");
    if (!ultrasonic_light.ultrasonic->behavior->raisedViVf(0, 20))
        failTestNow();

    assertTrue(ultrasonic_light.light->behavior->isRaisedLow());

    if (!ultrasonic_light.light->behavior->proceed_time(4 * 1000))
        failTestNow();
}

test(test_0to20)
{
    configuration("test_0to20");

    if (!ultrasonic_light.ultrasonic->behavior->raisedViVf(0, 20))
        fail();

    assertTrue(ultrasonic_light.light->behavior->isRaisedLow());

    if (!ultrasonic_light.light->behavior->proceed_time(4 * 1000))
        fail();
}

test(TestUltrasonic, test_20to30)
{
    configuration("test_20to30");

    if (!ultrasonic_light.ultrasonic->behavior->raisedViVf(20, 30))
        failTestNow();

    assertTrue(ultrasonic_light.light->behavior->isRaisedHigh());
    assertTrue(ultrasonic_light.light->behavior->isRaisedLow());

    if (!ultrasonic_light.light->behavior->proceed_time(4 * 1000))
        failTestNow();
}
test(TestUltrasonic, test_30toLarger)
{
    configuration("test_30toLarger");

    if (!ultrasonic_light.ultrasonic->behavior->raisedViVf(30, 400))
        failTestNow();

    assertTrue(ultrasonic_light.light->behavior->isRaisedHigh());

    if (!ultrasonic_light.light->behavior->proceed_time(4 * 1000))
        failTestNow();
}
