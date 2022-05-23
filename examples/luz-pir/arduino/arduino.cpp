#include <Arduino.h>
const int pinPir = 6;
const int pinLight = 13;

#include "../statechart/statechart.cpp"
// Statechart *statechart = Statechart::get();

class Arduino
{
public:
  void setupArduino()
  {
    // put your setup code here, to run once:
    pinMode(pinLight, OUTPUT);
    pinMode(pinPir, INPUT);
  }

  void loopArduino(Statechart *statechart)
  {
    // put your main code here, to run repeatedly:
    // Serial.println(digitalRead(pinPir));
    if (digitalRead(pinPir) == HIGH)
    {
      statechart->pir->set(true);

      digitalWrite(pinLight, HIGH);
      statechart->light->set(false);
    }
    else if (digitalRead(pinPir) == LOW)
    {
      statechart->pir->set(false);

      digitalWrite(pinLight, LOW);
      statechart->light->set(true);
    }
    delay(1000);
  }
};
