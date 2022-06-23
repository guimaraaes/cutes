
#ifndef CREATOR_H_INCLUDED
#define CREATOR_H_INCLUDED
#include "Component.h"
class Creator
{
public:
    Component *createComponent(int pin);
};

// class AbstractCreator : public Creator
// {
// public:
//     virtual Component *createComponent(int pin) = 0;
// };

// class AbstractCreatorActuator : public Creator
// {
// public:
//     virtual Component *createComponent(int pin) = 0;
// };
#endif