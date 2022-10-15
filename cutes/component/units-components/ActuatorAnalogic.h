#pragma once
#include "../Component.h"

#ifdef TEST_ENVIROMENT
#include "../units-behaviors/Numeric.h"
#endif

class ActuatorAnalogic : public Component
{
public:
#ifdef TEST_ENVIROMENT
    Numeric *behavior;
#endif

    ActuatorAnalogic(uint8_t pin)
    {
        this->pin = pin;
#ifdef TEST_ENVIROMENT
        this->behavior = new Numeric(pin, 0, 1023);
#endif
        pinMode(pin, OUTPUT);
    };

    void write(int value)
    {
        analogWrite(this->pin, value);
        this->addHistory(this->pin, value);
    };

    void unitTest()
    {
        Serial.println((String) "Begining unit test to component in pin " + this->pin);
        this->assertValue(0);
        this->assertValue(500);
        this->assertValue(1023);
        Serial.println();
        Serial.println();
    }

    void assertValue(int value)
    {
        Serial.println((String) "--- Verify if within 2 seconds component is during 1 second with the value " + value);
        delay(2000);
        this->write(value);
        Serial.println("--- Unit test result: you must assert");
        delay(5000);
    }
};