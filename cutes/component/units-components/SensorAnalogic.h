#pragma once
#include "../Component.h"
#include "../units-behaviors/Numeric.h"

class SensorAnalogic : public Component
{
public:
    Numeric *behavior;
    SensorAnalogic(uint8_t pin)
    {
        this->pin = pin;
        this->behavior = new Numeric(pin, 0, 1023);
        pinMode(pin, INPUT);
    };

    int read()
    {
        int value = analogRead(this->pin);
        this->behavior->addHistory(this->pin, value);
        // Serial.println(value);
        return value;
    };
};