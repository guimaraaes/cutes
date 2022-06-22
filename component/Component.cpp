#include "ComponentBehavior.h"
#include "Component.h"
#include "../store/Store.cpp"
#include <iostream>
#include <string>
using namespace std;
class AbstractComponent
{
protected:
    int pin;
    ComponentBehavior componentBehavior;
    Store store;

public:
    virtual void configuration() = 0;
    virtual void getStatus() = 0;
};

class Actuator : public AbstractComponent
{
public:
    virtual void write() = 0;
};

class Sensor : public AbstractComponent
{
public:
    virtual void read() = 0;
};

class Light : public Component
{
public:
    Light(){};

    void configuration(){

    };
    void getStatus(){

    };
    void write(){

    };
};