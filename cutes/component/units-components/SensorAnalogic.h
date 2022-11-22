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

    bool assertValue(int value)
    {
        bool reload = true;
        bool result = false;
        while (reload)
        {
            Serial.println((String) "--- Put within 5 seconds component with the value " + value);
            delay(5000);
            int valueReaded = this->read_cm();
            Serial.println((String) "--- Unit test result: you must assert. Wait to answer." + (valueReaded == value));
            delay(2000);
            Serial.println((String) "---- Value expected" + value);
            Serial.println((String) "---- Value readed" + valueReaded);
            delay(2000);
            Serial.println("Unit test pass?");
            result = Serial.read();
            Serial.println("Reload unit test?");
            reload = Serial.read();
        }
        return result;
    }
};