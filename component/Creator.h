
#ifndef CREATOR_H_INCLUDED
#define CREATOR_H_INCLUDED
#include "Component.h"
class Creator
{
public:
    void configuration();
    Component createComponent();
};
class CreatorSensor : public Creator
{
public:
    virtual void configuration() = 0;
    virtual Component createComponent() = 0;
};

class CreatorActuator : public Creator
{
public:
    virtual void configuration() = 0;
    virtual Component createComponent() = 0;
};
#endif