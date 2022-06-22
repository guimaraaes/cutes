#include "Component.cpp"
#include "Store.cpp"
#include <iostream>
#include <string>
using namespace std;

class CreatorSensor
{
public:
    virtual void configuration() = 0;
    virtual AbstractComponent createComponent() = 0;
};

class CreatorActuator
{
public:
    virtual void configuration() = 0;
    virtual AbstractComponent createComponent() = 0;
};