#include <Arduino.h>
#include "../lib/Ultrasonic/src/Ultrasonic.cpp"
// #include <Ultrasonic.h>
const int pinLight = 13;

const int pinTrigger = 4;
const int pinEcho = 5;
Ultrasonic ultrasonic(pinTrigger, pinEcho);

#include "../statechart/statechart.cpp"
#include "../statechart/store.cpp"

class Arduino
{
public:
    void setupArduino()
    {
        // put your setup code here, to run once:
        pinMode(pinLight, OUTPUT);
    }

    void loopArduino()
    {
        // put your main code here, to run repeatedly:

        float distance = ultrasonic.read();
        Serial.println(distance);
        statechart->list->add(Store(millis(), false, distance, pinTrigger));
        delay(1000);

        if (distance < 20)
        {
            digitalWrite(pinLight, LOW);
            statechart->list->add(Store(millis(), false, distance, pinLight));

            distance = ultrasonic.read();
            Serial.println(distance);
            statechart->list->add(Store(millis(), false, distance, pinTrigger));
            delay(1000);
        }
        if (distance >= 20 && distance < 30)
        {
            digitalWrite(pinLight, HIGH);
            statechart->list->add(Store(millis(), true, distance, pinLight));

            delay(500);
            digitalWrite(pinLight, LOW);
            statechart->list->add(Store(millis(), false, distance, pinLight));

            delay(500);
            distance = ultrasonic.read();
            Serial.println(distance);
            statechart->list->add(Store(millis(), false, distance, pinTrigger));
            delay(1000);
        }
        if (distance >= 30)
        {
            digitalWrite(pinLight, HIGH);
            statechart->list->add(Store(millis(), true, distance, pinLight));

            distance = ultrasonic.read();
            Serial.println(distance);
            statechart->list->add(Store(millis(), false, distance, pinTrigger));
            delay(1000);
        }
        statechart->showList();
    }
};