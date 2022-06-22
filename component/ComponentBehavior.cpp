#include "../store/Store.cpp"
#include "../store/Interation.cpp"
#include <iostream>
#include <string>
using namespace std;
#include "ComponentBehavior.h"
// #ifndef ABSTRACTCOMPONENTBEHAVIOR_H
// #define ABSTRACTCOMPONENTBEHAVIOR_H

// class AbstractComponentBehavior
// {
// public:
//     Store store;
// };
// #endif
#ifndef HIGHLOW_H
#define HIGHLOW_H

class HighLow : public ComponentBehavior
{
public:
    bool isRaisedHigh(int pin)
    {
        Interation element = store.list->shift();

        return 1 == element.value && pin == element.pin;
    };
    bool isRaisedLow(int pin)
    {
        Interation element = store.list->shift();

        return 0 == element.value && pin == element.pin;
    };
    bool outLimit(int pin)
    {
        Interation element = store.list->shift();

        return 0 != element.value && 1 != element.value && pin == element.pin;
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
    virtual bool isRaisedViVf(int Vi, int Vf) = 0;
    virtual bool upperLimit() = 0;
    virtual bool lowerLimit() = 0;
};
#endif
