#pragma once
#include "../ComponentBehavior.h"

class Numeric : public ComponentBehavior
{
    int upperValue;
    int lowerValue;

    bool findElementInViVf(int Vi, int Vf)
    {
        Interation element = history->list->shift();

        bool elementInViVfAndInPin = this->isElementViVfAndPin(element, Vi, Vf, this->pin);
        bool historyHasElements = history->list->size() > 0;

        while (!elementInViVfAndInPin && historyHasElements)
        {
            elementInViVfAndInPin = this->isElementViVfAndPin(element, Vi, Vf, this->pin);
            historyHasElements = history->list->size() > 0;
            element = history->list->shift();
        }

        return elementInViVfAndInPin;
    }

    bool isElementViVfAndPin(Interation element, int Vi, int Vf, int pin)
    {
        bool elementInViVf = element.value < Vi && element.value >= Vf;
        bool elementInPin = element.pin == this->pin;
        return elementInViVf && elementInPin;
    }

public:
    Numeric(int pin, int upper, int lower) : ComponentBehavior(pin)
    {
        this->upperValue = upper;
        this->lowerValue = lower;
    }

    bool isSensorViVf(int Vi, int Vf)
    {
        return this->findElementInViVf(Vi, Vf);
    };

    bool isActuatorViVf(int Vi, int Vf)
    {
        Interation element = history->list->shift();
        return this->isElementViVfAndPin(element, Vi, Vf, this->pin);
    };

    bool isSensorOutLimit()
    {
        return this->isSensorViVf(this->lowerValue, this->upperValue);
    };

    bool isActuatorOutLimit()
    {
        return this->isActuatorViVf(this->lowerValue, this->upperValue);
    };
};