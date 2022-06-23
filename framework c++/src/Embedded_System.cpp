#include "../component/Creator.h"
#include "../component/Component.h"
#include "../component/ComponentBehavior.cpp"
#include "Embedded_System.h"
#include <iostream>
#include <list>
#include <string>
#include <typeinfo>

using namespace std;

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
    class CreatorLight : public AbstractCreator
    {
    public:
        CreatorLight(){};
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

    void setup()
    {

        CreatorLight c = CreatorLight();
        c.createComponent();
    }
    void loop()
    {
    }
};