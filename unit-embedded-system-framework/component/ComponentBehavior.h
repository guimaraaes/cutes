#include "../store/Store.h"
#include "../store/Interation.h"
// #include <Arduino.h>
#ifndef COMPONENTBEHAVIOR_H_INCLUDED
#define COMPONENTBEHAVIOR_H_INCLUDED

class ComponentBehavior
{
public:
    // Store store;
    void addStore(int pin, int value)
    {
        Interation element = Interation(millis(), value, pin);
        store->list->add(element);
        // store->list->add(element);

        // this->store.showList();
    };
};

class HighLow : public ComponentBehavior
{
public:
    HighLow(){};

    bool isRaisedHigh(int pin)
    {
        Interation element = store->list->shift();
        return element.value == 1 && element.pin == pin;
    };
    bool isRaisedLow(int pin)
    {
        // Serial.println("is raised low");
        Interation element = store->list->shift();
        return element.value == 0 && element.pin == pin;
    };
    bool raiseHigh(int pin)
    {
        Interation element = store->list->shift();
        while ((element.value != 1 || element.pin != pin) && store->list->size() > 0)
            element = store->list->shift();
        return element.value == 1 && element.pin == pin;
    };

    bool raiseLow(int pin)
    {
        Interation element = store->list->shift();
        while ((element.value != 0 || element.pin != pin) && store->list->size() > 0)
            element = store->list->shift();
        return element.value == 0 && element.pin == pin;
    };

    bool outLimit(int pin)
    {
        Interation element = store->list->shift();
        return element.value != 0 && element.value != 1 && element.pin == pin;
    };
};

class Numeric : public ComponentBehavior
{
    int upperValue;
    int lowerValue;

public:
    Numeric(int upper, int lower)
    {
        this->upperValue = upper;
        this->lowerValue = lower;
    }
    bool raisedViVf(int pin, int Vi, int Vf)
    {
        Interation element = store->list->shift();
        while ((element.value < Vi || element.value >= Vf || element.pin != pin) && store->list->size() > 0)
            element = store->list->shift();
        return element.value >= Vi && element.value < Vf && element.pin == pin;
    };
    bool isRaisedViVf(int pin, int Vi, int Vf)
    {
        Interation element = store->list->shift();
        return element.value >= Vi && element.value < Vf && element.pin == pin;
    };
    bool outLimit(int pin)
    {
        Interation element = store->list->shift();
        return element.value > this->upperValue && element.value < this->lowerValue && element.pin == pin;
    };
};
#endif
