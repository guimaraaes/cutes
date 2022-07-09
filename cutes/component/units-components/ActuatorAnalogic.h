#pragma once
#include "../Component.h"
#include "../units-behaviors/Numeric.h"

class ActuatorAnalogic : public Component
{
public:
    Numeric *behavior;
    ActuatorAnalogic(uint8_t pin)
    {
        this->pin = pin;
        this->behavior = new Numeric(pin, 0, 1023);
        pinMode(pin, OUTPUT);
    };

    void write(int value)
    {
        analogWrite(this->pin, value);
        this->behavior->addStore(this->pin, value);
    };
};