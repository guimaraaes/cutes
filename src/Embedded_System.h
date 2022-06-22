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
    Creator creatorSensor;
    Creator creatorActuator;
    string description;
    string author;

public:
    void configuration();
    void createSensor();
    void createActuator();
};
