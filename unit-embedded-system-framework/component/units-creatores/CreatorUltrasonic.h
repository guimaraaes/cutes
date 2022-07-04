#include "../Creator.h"
#include "../Component.h"
#include "../units-components/SensorUltrasonicNumericCM.h"

class CreatorUltrasonic : public Creator
{
public:
    CreatorUltrasonic(){};
    Component *createComponent(int pinTrigger, int pinEcho)
    {
        return new SensorUltrasonicNumericCM(4, 5);
    };
};