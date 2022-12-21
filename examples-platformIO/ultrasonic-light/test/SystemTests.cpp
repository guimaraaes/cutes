#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

class UltrasonicLightSystemTests : public SystemTests
{
public:
    UltrasonicLightSystemTests(){};
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

UltrasonicLightSystemTests systemTests = UltrasonicLightSystemTests();

void enter(String name)
{
    Serial.begin(9600);
    embeddedSystem.setup();
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

test(test_0to30)
{
    enter("test_0to30");

    assertTrue(embeddedSystem.ultrasonic->behavior->isSensorViVf(0, 30));

    assertTrue(embeddedSystem.light->behavior->isActuatorLow());

    exit();
}

// test(test_30toLarger)
// {
//     systemTests.enter("test_30toLarger");

//     assertTrue(embeddedSystem.ultrasonic->behavior->isSensorViVf(30, 400));

//     assertTrue(embeddedSystem.light->behavior->isActuatorHigh());

//     systemTests.exit();
// }
