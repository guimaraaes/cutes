#include "../Component.h"
#include "../units-behaviors/HighLow.h"

class ActuatorDigital : public Component
{
public:
    HighLow *behavior;
    ActuatorDigital(int pin)
    {
        this->pin = pin;
        this->behavior = new HighLow();
        pinMode(pin, OUTPUT);
    };

    void write(int value)
    {
        if (value == 0)
        {
            digitalWrite(this->pin, LOW);
            this->behavior->addStore(pin, 0);
        }
        if (value == 1)
        {
            digitalWrite(this->pin, HIGH);
            this->behavior->addStore(this->pin, 1);
        }
    };
};