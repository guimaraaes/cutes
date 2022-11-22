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
        Serial.println((String) "--- Value readed: " + (int)value);
        this->addHistory(this->pin, value);
        return value;
    };

    void unitTest()
    {
        Serial.println((String) "Begining unit test to component in pin " + this->pin);
        this->assertValue(1);
        this->assertValue(0);
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
