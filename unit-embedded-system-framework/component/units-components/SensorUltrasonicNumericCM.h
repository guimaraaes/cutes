#include "../Component.h"
#include "../lib/Ultrasonic/src/Ultrasonic.h"
#include "../units-behaviors/Numeric.h"

class SensorUltrasonicNumericCM : public Component
{
public:
    Numeric *behavior;
    int pinTrigger;
    int pinEcho;

    SensorUltrasonicNumericCM(int pinTrigger, int pinEcho)
    {
        this->pin = pinTrigger;
        this->pinTrigger = pinTrigger;
        this->pinEcho = pinEcho;
        this->behavior = new Numeric(2, 400);
        // pinMode(pin, INPUT);
    };

    float read_cm()
    {
        Ultrasonic ultrasonic(this->pinTrigger, this->pinEcho);
        float distance = 0;
        distance = ultrasonic.read();
        Serial.println((int)distance);
        this->behavior->addStore(this->pin, (int)distance);
        return distance;
    };
};
