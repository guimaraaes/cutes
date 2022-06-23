#include "../store/Store.cpp"
#include "../store/Interation.cpp"

#include "ComponentBehavior.h"

#ifndef HIGHLOW_H_INCLUDED
#define HIGHLOW_H_INCLUDED

class HighLow : public ComponentBehavior
{
public:
    HighLow(){};
    bool isRaisedHigh(int pin)
    {
        Interation element = store.list->shift();

        return element.value == 1 && element.pin == pin;
    };
    bool isRaisedLow(int pin)
    {
        Interation element = store.list->shift();

        return element.value == 0 && element.pin == pin;
    };
    bool raiseHigh(int pin)
    {
        Interation element = store.list->shift();
        while ((element.value != 1 || element.pin != pin) && store.list->size() > 0)
        {
            element = store.list->shift();
        }
        return element.value >= 1 && element.pin == pin;
    };

    bool raiseLow(int pin)
    {
        Interation element = store.list->shift();
        while ((element.value != 0 || element.pin != pin) && store.list->size() > 0)
        {
            element = store.list->shift();
        }
        return element.value >= 0 && element.pin == pin;
    };

    bool outLimit(int pin)
    {
        Interation element = store.list->shift();

        return element.value != 0 && element.value != 1 && element.pin == pin;
    };
};
#endif
#ifndef NUMERIC_H
#define NUMERIC_H

class Numeric : public ComponentBehavior
{
    int upperValue;
    int lowerValue;

public:
    bool raisedViVf(int pin, int Vi, int Vf)
    {
        Interation element = store.list->shift();
        while ((element.value < Vi || element.value >= Vf || element.pin != pin) && store.list->size() > 0)
        {
            element = store.list->shift();
        }
        return element.value >= Vi && element.value < Vf && element.pin == pin;
    };
    bool isRaisedViVf(int pin, int Vi, int Vf)
    {
        Interation element = store.list->shift();

        return element.value >= Vi && element.value < Vf && element.pin == pin;
    };
    bool outLimit(int pin)
    {
        Interation element = store.list->shift();

        return element.value > this->upperValue && element.value < this->lowerValue && element.pin == pin;
    };
};
#endif
