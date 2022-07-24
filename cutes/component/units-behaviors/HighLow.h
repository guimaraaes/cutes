#pragma once
#include "../ComponentBehavior.h"
#include "../Component.h"

class HighLow : public ComponentBehavior
{

public:
    HighLow(int pin) : ComponentBehavior(pin){};

    bool isRaisedHigh()
    {
        Interation element = history->list->shift();
        return element.value == 1 && element.pin == this->pin;
    };
    bool isRaisedLow()
    {
        // Serial.println("is raised low");
        Interation element = history->list->shift();
        return element.value == 0 && element.pin == this->pin;
    };
    bool raiseHigh()
    {
        Interation element = history->list->shift();
        while ((element.value != 1 || element.pin != this->pin) && history->list->size() > 0)
            element = history->list->shift();
        return element.value == 1 && element.pin == this->pin;
    };

    bool raiseLow()
    {
        Interation element = history->list->shift();
        while ((element.value != 0 || element.pin != this->pin) && history->list->size() > 0)
            element = history->list->shift();
        return element.value == 0 && element.pin == this->pin;
    };

    bool outLimit()
    {
        Interation element = history->list->shift();
        return element.value != 0 && element.value != 1 && element.pin == this->pin;
    };
};
