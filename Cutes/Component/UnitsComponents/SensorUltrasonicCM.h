#pragma once
#include "../Component.h"
#include "../../lib/Ultrasonic/src/Ultrasonic.h"

#ifdef SYSTEM_TESTS_ENVIROMENT
#include "../UnitsBehaviors/Numeric.h"
#endif

class SensorUltrasonicCM : public Component
{
public:
#ifdef SYSTEM_TESTS_ENVIROMENT
    Numeric *behavior;
#endif

    int pinTrigger;
    int pinEcho;

    SensorUltrasonicCM(int pinTrigger, int pinEcho)
    {
#ifdef SYSTEM_TESTS_ENVIROMENT
        this->behavior = new Numeric(pinTrigger, 2, 400);
        pinMode(pin, INPUT);
#endif
        this->pin = pinTrigger;
        this->pinTrigger = pinTrigger;
        this->pinEcho = pinEcho;
    };

    int read()
    {
        Ultrasonic ultrasonic(this->pinTrigger, this->pinEcho);
        int distance = 0;
        distance = ultrasonic.read();
        Serial.println((String) "--- Value readed: " + distance);
        this->addHistory(this->pin, distance);
        return distance;
    };

    void componentTest()
    {
        Serial.println((String) "Begining component test to component in pin " + this->pin);
        this->assertValue(2);
        this->assertValue(20);
        this->assertValue(400);
        Serial.println();
        Serial.println();
    }

    void assertValue(int value)
    {

        Serial.println((String) "--- Put within 5 seconds component with the value " + value);
        delay(5000);
        int valueReaded = this->read();
        Serial.println("--- Component test result: you must assert. Wait to answer.");
        delay(2000);
        Serial.println((String) "---- Value expected" + value);
        Serial.println((String) "---- Value readed" + valueReaded);
        delay(2000);
    }
};
