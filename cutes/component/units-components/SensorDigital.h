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

    void unitTest()
    {
        Serial.println("Begining unit test to component in pin " + this->pin);
        this.assertValue(HIGH);
        this.assertValue(LOW);
    }

    void assertValue(int value)
    {
        Serial.println("--- Put within 2 seconds component with the value " + HIGH);
        delay(2000);
        Serial.println("--- Unit test result: " + (this->read() == HIGH));
        delay(2000);
    }
};
