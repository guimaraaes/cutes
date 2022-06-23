#include "../component/Creator.h"
#include "../component/Component.h"
#include "../component/ComponentBehavior.cpp"
#include "Embedded_System.h"
#include <Arduino.h>

class Arduino : public AbstractEmbedded_System
{

    class Light : public Actuator
    {
    public:
        Light(){};

        void configuration(int pin, ComponentBehavior behavior)
        {
            this->pin = pin;
            this->componentBehavior = behavior;
            pinMode(pin, OUTPUT);
        };
        void getStatus(){

        };
        void write()
        {
            digitalWrite(this->pin, LOW);
            delay(1000);
            digitalWrite(this->pin, HIGH);
            delay(1000);
        };
    };
    class CreatorLight : public AbstractCreatorActuator
    {
    public:
        CreatorLight(){};
        Component *createComponent(int pin, ComponentBehavior behavior)
        {
            Serial.print("create");
            Light *light_arduino = new Light();
            light_arduino->configuration(pin, behavior);
            return light_arduino;
        };
    };

public:
    Light *light;
    void configuration(){};

    void setup()
    {
        CreatorLight *creator_light = new CreatorLight();
        this->light = creator_light->createComponent(13, HighLow());
    }
    void loop()
    {
        this->light->write();
    }
};