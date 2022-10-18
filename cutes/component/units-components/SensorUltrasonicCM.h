#pragma once
#include "../Component.h"
#include "../../lib/Ultrasonic/src/Ultrasonic.h"

#ifdef TEST_ENVIROMENT
#include "../units-behaviors/Numeric.h"
#endif

class SensorUltrasonicCM : public Component
{
public:
#ifdef TEST_ENVIROMENT
    Numeric *behavior;
#endif

    int pinTrigger;
    int pinEcho;

    SensorUltrasonicCM(int pinTrigger, int pinEcho)
    {
#ifdef TEST_ENVIROMENT
        this->behavior = new Numeric(pinTrigger, 2, 400);
        pinMode(pin, INPUT);
#endif
        this->pin = pinTrigger;
        this->pinTrigger = pinTrigger;
        this->pinEcho = pinEcho;
    };

    float read_cm()
    {
        Ultrasonic ultrasonic(this->pinTrigger, this->pinEcho);
        float distance = 0;
        distance = ultrasonic.read();
        Serial.println((String) "--- Value readed: " + (int)distance);
        this->addHistory(this->pin, (int)distance);
        return distance;
    };

    void unitTest()
    {
        Serial.println((String) "Begining unit test to component in pin " + this->pin);
        this->assertValue(10);
        this->assertValue(20);
        Serial.println();
        Serial.println();
    }

    void assertValue(int value)
    {
        Serial.println((String) "--- Put within 2 seconds component with the value " + value);
        delay(5000);
        int valueReaded = this->read_cm();
        Serial.println((String) "--- Unit test result: " + (valueReaded == value));
        delay(2000);
    }
};
