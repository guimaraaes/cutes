#include "../Creator.h"
#include "../Component.h"
#include "../units-components/ActuatorDigital.h"

class CreatorLight : public Creator
{
public:
    CreatorLight(){};
    Component *createComponent(int pin)
    {
        return new ActuatorDigital(pin);
    };
};