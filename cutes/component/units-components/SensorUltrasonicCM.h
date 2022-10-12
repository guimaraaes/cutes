#pragma once
#include "../Component.h"
#include "../lib/Ultrasonic/src/Ultrasonic.h"

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
        Serial.println((int)distance);
        this->addHistory(this->pin, (int)distance);
        return distance;
    };

    void unitTest(int value)
    {
        Serial.println("Begining unit test to component in pin " + this->pin);
        Serial.println("--- Verify if within 2 seconds component is in " + value);
        delay(2000);
        Serial.println("--- Unit test result: you must assert");
        delay(2000);
    }
};
