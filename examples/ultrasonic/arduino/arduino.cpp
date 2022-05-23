#include <Arduino.h>
#include <Ultrasonic.h>
#define pin_light 13

#define pin_trigger 4
#define pin_echo 5
Ultrasonic ultrasonic(pin_trigger, pin_echo);

// #include "../statechart/statechart.cpp"
// Statechart *statechart = Statechart::get();

class Arduino
{
public:
    void setupArduino()
    {
        // put your setup code here, to run once:
        // ultrasonic.setTimeout(40000UL);
        pinMode(pin_light, OUTPUT);
    }

    // void loopArduino(Statechart *statechart)
    void loopArduino()
    {
        // put your main code here, to run repeatedly:
        float distance = ultrasonic.read(CM);
        while (distance > 10 && distance <= 20)
        {
            digitalWrite(pin_light, LOW);
            distance = ultrasonic.read(CM);
            Serial.print("distance: ");
            Serial.println(distance);
        }
        while (distance > 20 && distance <= 30)
        {
            digitalWrite(pin_light, HIGH);
            delay(500);
            digitalWrite(pin_light, LOW);
            delay(500);
            distance = ultrasonic.read(CM);
            Serial.print("distance: ");
            Serial.println(distance);
        }
        while (distance > 30)
        {
            digitalWrite(pin_light, HIGH);
            distance = ultrasonic.read(CM);
            Serial.print("distance: ");
            Serial.println(distance);
        }
        Serial.print("distance: ");
        Serial.println(distance);

        delay(1000);
    }
};