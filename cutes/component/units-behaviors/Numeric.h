#pragma once
#include "../ComponentBehavior.h"

class Numeric : public ComponentBehavior
{
    int upperValue;
    int lowerValue;

public:
    Numeric(int pin, int upper, int lower) : ComponentBehavior(pin)
    {
        this->upperValue = upper;
        this->lowerValue = lower;
    }
    bool raisedViVf(int Vi, int Vf)
    {
        Interation element = store->list->shift();
        while ((element.value < Vi || element.value >= Vf || element.pin != this->pin) && store->list->size() > 0)
            element = store->list->shift();
        return element.value >= Vi && element.value < Vf && element.pin == this->pin;
    };
    bool isRaisedViVf(int Vi, int Vf)
    {
        Interation element = store->list->shift();
        return element.value >= Vi && element.value < Vf && element.pin == this->pin;
    };
    bool outLimit()
    {
        Interation element = store->list->shift();
        return element.value > this->upperValue && element.value < this->lowerValue && element.pin == this->pin;
    };
};