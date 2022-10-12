#pragma once
#include "../Component.h"

#ifdef TEST_ENVIROMENT
#include "../units-behaviors/HighLow.h"
#endif

class SensorDigital : public Component
{
public:
#ifdef TEST_ENVIROMENT
    HighLow *behavior;
#endif
    SensorDigital(int pin)
    {
        this->pin = pin;
#ifdef TEST_ENVIROMENT
        this->behavior = new HighLow(pin);
#endif
        pinMode(pin, INPUT);
    };

    int read()
    {
        int value = digitalRead(this->pin);
        this->addHistory(this->pin, value);
        Serial.println(value);
        return value;
    };

    void unitTest(int value)
    {
        Serial.println("Begining unit test to component in pin " + this->pin);
        Serial.println("--- Verify if within 2 seconds component is with the " + value);
        delay(2000);
        Serial.println("--- Unit test result: " + this->read() == value);
        delay(2000);
    }
};
