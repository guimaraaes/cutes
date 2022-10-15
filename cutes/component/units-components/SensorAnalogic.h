#pragma once
#include "../Component.h"

#ifdef TEST_ENVIROMENT
#include "../units-behaviors/Numeric.h"
#endif
class SensorAnalogic : public Component
{
public:
#ifdef TEST_ENVIROMENT
    Numeric *behavior;
#endif
    SensorAnalogic(uint8_t pin)
    {
        this->pin = pin;
#ifdef TEST_ENVIROMENT
        this->behavior = new Numeric(pin, 0, 1023);
#endif
        pinMode(pin, INPUT);
    };

    int read()
    {
        int value = analogRead(this->pin);
        Serial.println((String) "--- Value readed: " + (int)value);
        this->addHistory(this->pin, value);
        return value;
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
        Serial.println((String) "--- Put within 2 seconds component with the value " + value);
        delay(5000);
        int valueReaded = this->read();
        Serial.println((String) "--- Unit test result: " + (valueReaded == value));
        delay(2000);
    }
};