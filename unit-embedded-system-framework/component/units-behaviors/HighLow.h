#include "../ComponentBehavior.h"

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
