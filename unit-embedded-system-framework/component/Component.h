
#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#include "ComponentBehavior.h"
#include "../lib/Ultrasonic/src/Ultrasonic.h"
#include "../store/Store.h"
class Component
{
public:
    int pin;
    ComponentBehavior *componentBehavior;
    Store store;
};

class ActuatorDigital : public Component
{
public:
    HighLow *behavior;
    ActuatorDigital(int pin)
    {
        this->pin = pin;
        this->behavior = new HighLow();
        pinMode(pin, OUTPUT);
    };

    void write(int value)
    {
        if (value == 0)
        {
            digitalWrite(this->pin, LOW);
            this->behavior->addStore(pin, 0);
        }
        if (value == 1)
        {
            digitalWrite(this->pin, HIGH);
            this->behavior->addStore(this->pin, 1);
        }
    };
};

class SensorDigital : public Component
{
public:
    HighLow *behavior;
    SensorDigital(int pin)
    {
        this->pin = pin;
        this->behavior = new HighLow();
        pinMode(pin, INPUT);
    };

    int read()
    {
        int value = digitalRead(this->pin);
        this->behavior->addStore(this->pin, value);
        Serial.println(value);
        return value;
    };
};

class SensorUltrasonicNumeric : public Component
{
public:
    Numeric *behavior;
    int pinTrigger;
    int pinEcho;

    SensorUltrasonicNumeric(int pinTrigger, int pinEcho)
    {
        this->pin = pinTrigger;
        this->pinTrigger = pinTrigger;
        this->pinEcho = pinEcho;
        this->behavior = new Numeric();
        // pinMode(pin, INPUT);
    };

    float read_cm()
    {
        Ultrasonic ultrasonic(this->pinTrigger, this->pinEcho);
        float distance = 0;
        distance = ultrasonic.read();
        // Serial.println(distance);
        this->behavior->addStore(this->pin, distance);
        return distance;
    };
};

#endif
