#include "../ComponentBehavior.h"

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