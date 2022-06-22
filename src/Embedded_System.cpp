#include "../component/Creator.h"
#include "../component/Component.h"
#include "../component/Component.cpp"
#include <iostream>
#include <list>
#include <string>
using namespace std;
class AbstractEmbedded_System
{
protected:
    list<Component> components;
    Creator creatorSensor;
    Creator creatorActuator;
    string description;
    string author;

public:
    virtual void configuration() = 0;
    virtual Component createSensor() = 0;
    virtual Component createActuator() = 0;
};
class Arduino : public AbstractEmbedded_System
{
public:
    void configuration()
    {
        std::cout << "Hello World!" << std::endl;
    };
    Component createSensor()
    {
        std::cout << "Hello World!" << std::endl;
        Light c;
        // Light c;
        return c;
    };
    Component createActuator()
    {
        std::cout << "Hello World!" << std::endl;
        return Light();
    };
};