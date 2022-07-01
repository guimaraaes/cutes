#include "../src/AUnit/src/AUnit.h"
using namespace aunit;

#include "../../../unit-embedded-system-framework/store/Store.h"
// #include "../../../unit-embedded-system-framework/test/Test.h"

// #ifndef TEST_H_INCLUDED
// #define TEST_H_INCLUDED
class TestUltrasonic : public TestOnce
{
    // EmbeddedSystem *embeddedSystem = &ultrasonic_light;
    // Store store;

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
    store->list->clear();
    Serial.println(name);
    delay(3000);
    ultrasonic_light.loop();
};

testF(TestUltrasonic, test_0to20)
{
    configuration("test_0to20");

    if (!ultrasonic_light.ultrasonic->behavior->raisedViVf(4, 0, 20))
        failTestNow();

    assertTrue(ultrasonic_light.light->behavior->isRaisedLow(13));

    // runner->proceed_time(4 * 1000);
}
test(TestUltrasonic, test_20to30)
{
    configuration("test_20to30");

    if (!ultrasonic_light.ultrasonic->behavior->raisedViVf(4, 20, 30))
        failTestNow();

    assertTrue(ultrasonic_light.light->behavior->isRaisedHigh(13));
    assertTrue(ultrasonic_light.light->behavior->isRaisedLow(13));

    // runner->proceed_time(4 * 1000);
}
test(TestUltrasonic, test_30toLarger)
{
    configuration("test_30toLarger");

    if (!ultrasonic_light.ultrasonic->behavior->raisedViVf(4, 30, 400))
        failTestNow();

    assertTrue(ultrasonic_light.light->behavior->isRaisedHigh(13));

    // runner->proceed_time(4 * 1000);
}

// #endif