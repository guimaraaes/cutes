#include "../component/Creator.h"
#include "../component/Component.h"
#include "../component/ComponentBehavior.cpp"
// #include "../component/Component.cpp"
#include <iostream>
#include <list>
#include <string>
#include <typeinfo>

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
    class Light : public Sensor
    {
    public:
        Light(){};

        void configuration(int pin, ComponentBehavior behavior)
        {
            this->pin = pin;
            this->componentBehavior = behavior;
            std::cout << typeid(behavior).name() << std::endl;
        };
        void getStatus(){

        };
        void read(){

        };
    };
    class CreatorLight : public CreatorActuator
    {
    public:
        void configuration(){};
        Component createComponent()
        {
            std::cout << "creator light" << std::endl;
            Light light_arduino;
            light_arduino.configuration(13, HighLow());
            return light_arduino;
        };
    };

public:
    void configuration()
    {
        std::cout << "Hello World!" << std::endl;
    };
    Component createSensor()
    {
        CreatorLight c;
        return c.createComponent();
        // Light c;
        // Light c;
        // return c;
    };
    Component createActuator()
    {
        CreatorLight c;
        return c.createComponent();
    };
};