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
    string description;
    string author;

public:
    void configuration();
    void setup();
    void loop();
};

class AbstractEmbedded_System : public Embedded_System
{
protected:
    list<Component> components;
    string description;
    string author;

public:
    virtual void configuration() = 0;
    virtual void setup() = 0;
    virtual void loop() = 0;
};
