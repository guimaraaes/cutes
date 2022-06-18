#include <Arduino.h>
const int pinPir = 6;
const int pinLight = 13;

#include "../statechart/statechart.cpp"
#include "../statechart/store.cpp"

class Arduino
{

public:
  void setupArduino()
  {
    // put your setup code here, to run once:
    pinMode(pinLight, OUTPUT);
    pinMode(pinPir, INPUT);
  }

  void loopArduino()
  {
    // put your main code here, to run repeatedly:
    digitalWrite(pinLight, LOW);
    statechart->list->add(Store(millis(), false, pinLight));

    if (digitalRead(pinPir) == HIGH)
    {
      statechart->list->add(Store(millis(), true, pinPir));

      digitalWrite(pinLight, HIGH);
      statechart->list->add(Store(millis(), true, pinLight));
      delay(5000);
    }
    else if (digitalRead(pinPir) == LOW)
    {
      statechart->list->add(Store(millis(), false, pinPir));
      digitalWrite(pinLight, LOW);

      statechart->list->add(Store(millis(), false, pinLight));
    }
    statechart->showList();
  }
};
