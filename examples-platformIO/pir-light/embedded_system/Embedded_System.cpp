#include "../component/Creator.h"
#include "../component/Component.h"
// #include "../component/ComponentBehavior.cpp"
#include "Embedded_System.h"
#include <Arduino.h>

class Arduino : public AbstractEmbedded_System
{

    class CreatorLight : public AbstractCreator
    {
    public:
        CreatorLight(){};
        Component *createComponent(int pin)
        {
            ActuatorHighLow *lig = new ActuatorHighLow();
            lig->configuration(pin);
            return lig;
        };
    };

public:
    ActuatorHighLow *light;

    void configuration(){};

    void setup()
    {
        CreatorLight *creator_light = new CreatorLight();
        this->light = creator_light->createComponent(13);
    }
    void loop()
    {
        this->light->write(1);
        delay(1000);
        this->light->write(0);
        delay(1000);
    }
};