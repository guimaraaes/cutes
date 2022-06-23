
#ifndef CREATOR_H_INCLUDED
#define CREATOR_H_INCLUDED
#include "Component.h"
class Creator
{
public:
    Component *createComponent(int pin, ComponentBehavior behavior);
};

class AbstractCreatorSensor : public Creator
{
public:
    virtual Component *createComponent(int pin, ComponentBehavior behavior) = 0;
};

class AbstractCreatorActuator : public Creator
{
public:
    virtual Component *createComponent(int pin, ComponentBehavior behavior) = 0;
};
#endif