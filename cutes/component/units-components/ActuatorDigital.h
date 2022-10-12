
#pragma once

#include "../Component.h"

#ifdef TEST_ENVIROMENT
#include "../units-behaviors/HighLow.h"
#endif

class ActuatorDigital : public Component
{
public:
#ifdef TEST_ENVIROMENT
    HighLow *behavior;
#endif
    ActuatorDigital(int pin)
    {
#ifdef TEST_ENVIROMENT
        this->behavior = new HighLow(pin);
#endif
        this->pin = pin;
        pinMode(pin, OUTPUT);
    };

    void write(int value)
    {
        if (value == 0)
        {
            digitalWrite(this->pin, LOW);
            this->addHistory(this->pin, 0);
        }
        if (value == 1)
        {
            digitalWrite(this->pin, HIGH);
            this->addHistory(this->pin, 1);
        }
    };

    void unitTest()
    {
        Serial.println("Begining unit test to component in pin " + this->pin);
        this->assertValue(HIGH);
        this->assertValue(LOW);
    }

    void assertValue(int value)
    {
        Serial.println("--- Verify if within 2 seconds component is during 1 second with the value " + value);
        delay(2000);
        this->write(value);
        delay(1000);
        Serial.println("--- Unit test result: you must assert");
        delay(2000);
    }
};
