#pragma once
#include "../ComponentBehavior.h"
#include "../Component.h"

class HighLow : public ComponentBehavior
{

public:
    HighLow(int pin) : ComponentBehavior(pin){};

    bool isRaisedHigh()
    {
        Interation element = store->list->shift();
        return element.value == 1 && element.pin == this->pin;
    };
    bool isRaisedLow()
    {
        // Serial.println("is raised low");
        Interation element = store->list->shift();
        return element.value == 0 && element.pin == this->pin;
    };
    bool raiseHigh()
    {
        Interation element = store->list->shift();
        while ((element.value != 1 || element.pin != this->pin) && store->list->size() > 0)
            element = store->list->shift();
        return element.value == 1 && element.pin == this->pin;
    };

    bool raiseLow()
    {
        Interation element = store->list->shift();
        while ((element.value != 0 || element.pin != this->pin) && store->list->size() > 0)
            element = store->list->shift();
        return element.value == 0 && element.pin == this->pin;
    };

    bool outLimit()
    {
        Interation element = store->list->shift();
        return element.value != 0 && element.value != 1 && element.pin == this->pin;
    };
};
