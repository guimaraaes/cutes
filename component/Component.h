
#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED
#include "ComponentBehavior.h"
#include "../store/Store.cpp"
class Component
{
public:
    int pin;
    ComponentBehavior componentBehavior;
    Store store;

public:
    void configuration();
    void getStatus();
};
class Sensor : public Component
{
public:
    virtual void configuration(int pin, ComponentBehavior behavior) = 0;
    virtual void getStatus() = 0;
    virtual void read() = 0;
};

class Actuator : public Component
{
public:
    virtual void configuration(int pin, ComponentBehavior behavior) = 0;
    virtual void getStatus() = 0;
    virtual void write() = 0;
};

#endif
