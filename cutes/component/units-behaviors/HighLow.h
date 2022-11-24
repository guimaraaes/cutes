#pragma once
#include "../ComponentBehavior.h"
#include "../Component.h"

class HighLow : public ComponentBehavior
{

    bool findElementInValue(int value)
    {
        Interation element = history->list->shift();

        bool elementInValueAndInPin = this->isElementInValueAndInPin(element, value, this->pin);
        bool historyHasElements = history->list->size() > 0;

        while (!elementInValueAndInPin && historyHasElements)
        {
            elementInValueAndInPin = this->isElementInValueAndInPin(element, value, this->pin);
            historyHasElements = history->list->size() > 0;
            element = history->list->shift();
        }

        return elementInValueAndInPin;
    }

    bool isElementInValueAndInPin(Interation element, int value, int pin)
    {
        bool elementInValue = element.value == value;
        bool elementInPin = element.pin == this->pin;
        return elementInValue && elementInPin;
    };

public:
    HighLow(int pin) : ComponentBehavior(pin){};

    bool isSensorHigh()
    {
        return this->findElementInValue(HIGH);
    };

    bool isSensorLow()
    {
        return this->findElementInValue(LOW);
    };

    bool isActuatorHigh()
    {
        Interation element = history->list->shift();
        return this->isElementInValueAndInPin(element, HIGH, this->pin);
    };

    bool isActuatorLow()
    {
        Interation element = history->list->shift();
        return this->isElementInValueAndInPin(element, LOW, this->pin);
    };

    bool isSensorOutLimit()
    {
        return !isSensorHigh() && !isSensorLow();
    };

    bool isActuatorOutLimit()
    {
        return !isActuatorHigh() && !isActuatorLow();
    };
};
