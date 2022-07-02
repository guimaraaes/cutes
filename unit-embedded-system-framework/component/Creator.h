
#ifndef CREATOR_H_INCLUDED
#define CREATOR_H_INCLUDED
#include "Component.h"
class Creator
{
public:
    Component *createComponent(int pin);
};

#endif