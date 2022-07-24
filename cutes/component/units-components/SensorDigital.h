#pragma once
#include "../Component.h"
#include "../units-behaviors/HighLow.h"
class SensorDigital : public Component
{
public:
    HighLow *behavior;
    SensorDigital(int pin)
    {
        this->pin = pin;
        this->behavior = new HighLow(pin);
        pinMode(pin, INPUT);
    };

    int read()
    {
        int value = digitalRead(this->pin);
        this->behavior->addHistory(this->pin, value);
        Serial.println(value);
        return value;
    };
};
