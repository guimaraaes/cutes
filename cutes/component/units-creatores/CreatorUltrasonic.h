#pragma once
#include "../lib/Ultrasonic/src/Ultrasonic.h"
#include "../Creator.h"
#include "../Component.h"
#include "../units-components/SensorUltrasonicCM.h"

class CreatorUltrasonic : public Creator
{
public:
    CreatorUltrasonic(){};
    Component *createComponent(int pinTrigger, int pinEcho)
    {
        return new SensorUltrasonicCM(4, 5);
    };
};