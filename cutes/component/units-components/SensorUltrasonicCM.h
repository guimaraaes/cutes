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

    void addHistory(int pin, int value)
    {
#ifdef TEST_ENVIROMENT
        this->behavior->addHistory(pin, value);
#endif
    }
    float read_cm()
    {
        Ultrasonic ultrasonic(this->pinTrigger, this->pinEcho);
        float distance = 0;
        distance = ultrasonic.read();
        Serial.println((int)distance);
        this->addHistory(this->pin, (int)distance);
        // this->behavior->addHistory(this->pin, (int)distance);
        return distance;
    };
};
