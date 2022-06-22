
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

#endif
