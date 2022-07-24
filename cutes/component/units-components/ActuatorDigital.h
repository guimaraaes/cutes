
#pragma once

#include "../Component.h"
#include "../units-behaviors/HighLow.h"
class ActuatorDigital : public Component
{
public:
    HighLow *behavior;
    ActuatorDigital(int pin)
    {
        this->pin = pin;
        this->behavior = new HighLow(pin);
        pinMode(pin, OUTPUT);
    };

    void write(int value)
    {
        if (value == 0)
        {
            digitalWrite(this->pin, LOW);
            this->behavior->addHistory(pin, 0);
        }
        if (value == 1)
        {
            digitalWrite(this->pin, HIGH);
            this->behavior->addHistory(this->pin, 1);
        }
    };
};
