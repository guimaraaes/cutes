#pragma once
#include "../Component.h"

#ifdef TEST_ENVIROMENT
#include "../units-behaviors/Numeric.h"
#endif
class SensorAnalogic : public Component
{
public:
#ifdef TEST_ENVIROMENT
    Numeric *behavior;
#endif
    SensorAnalogic(uint8_t pin)
    {
        this->pin = pin;
#ifdef TEST_ENVIROMENT
        this->behavior = new Numeric(pin, 0, 1023);
#endif
        pinMode(pin, INPUT);
    };

    int read()
    {
        int value = analogRead(this->pin);
        this->addHistory(this->pin, value);
        // Serial.println(value);
        return value;
    };
};