
#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED
#include "ComponentBehavior.h"
#include "ComponentBehavior.cpp"
#include "../store/Store.cpp"
class Component
{
public:
    int pin;
    ComponentBehavior *componentBehavior;
    Store store;
};

class ActuatorHighLow : public Component
{
public:
    HighLow *behavior;
    ActuatorHighLow(int pin)
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
            Serial.print(", ");
        }
        if (value == 1)
        {
            digitalWrite(this->pin, HIGH);
            this->behavior->addStore(this->pin, 1);
        }
    };
};

class SensorHighLow : public Component
{
public:
    HighLow *behavior;
    SensorHighLow(int pin)
    {
        this->pin = pin;
        this->behavior = new HighLow();
        pinMode(pin, INPUT);
    };

    int read()
    {
        int value = digitalRead(this->pin);
        this->behavior->addStore(this->pin, value);
        return value;
    };
};

class ActuatorNumeric : public Component
{
public:
    Numeric *behavior;
    ActuatorNumeric(int pin)
    {
        this->pin = pin;
        this->behavior = new Numeric();
        pinMode(pin, OUTPUT);
    };

    void write(int value)
    {
        digitalWrite(this->pin, LOW);
        this->behavior->addStore(this->pin, value);
    };
};

#endif
