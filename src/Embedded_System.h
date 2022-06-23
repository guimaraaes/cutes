#include "../component/Creator.h"
#include "../component/Component.h"
#include <iostream>
#include <list>
#include <string>
using namespace std;
class Embedded_System
{
protected:
    list<Component> components;
    // Creator creatorSensor;
    // Creator creatorActuator;

    string description;
    string author;

public:
    void configuration();
    void setup();
    void loop();
    // Component createComponent(Creator creator);
    // Component createActuator(Creator creator);
};

class AbstractEmbedded_System : public Embedded_System
{
protected:
    list<Component> components;
    // Creator creatorSensor;
    // Creator creatorActuator;

    string description;
    string author;

public:
    virtual void configuration() = 0;
    // virtual Component createComponent(Creator *creator) = 0;
    // virtual Component createActuator(Creator creator) = 0;
    virtual void setup() = 0;
    virtual void loop() = 0;
};
