#pragma once

class Interation
{

public:
    unsigned long time;
    int value;
    int pin;
    Interation(){};
    Interation(unsigned long time, int value, int pin)
    {
        this->time = time;
        this->value = value;
        this->pin = pin;
    };
};
Interation *interation;
