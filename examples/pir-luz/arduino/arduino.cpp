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
  // void StateLightOFF(bool pir = false)
  // {
  //   if (pir == false)
  //   {
  //     statechart->pir->set(false);
  //     statechart->light->set(false);
  //     digitalWrite(pinLight, LOW);
  //   }
  //   else
  //     StateLightON(pir);
  // }
  // void StateLightON(bool pir = true)
  // {
  //   statechart->pir->set(true);
  //   statechart->light->set(true);
  //   digitalWrite(pinLight, HIGH);

  //   StateDelay(pir);
  // }
  // void StateDelay(bool pir)
  // {
  //   delay(5000);
  //   if (pir)
  //     StateLightON(pir);
  //   else
  //     StateLightOFF(pir);
  // }

  // void loopArduinoStates()
  // {
  //   StateLightOFF(digitalRead(pinPir));
  // }
  void showListStore()
  {
    Store element = Store();
    for (int i = 0; i < statechart->list->size(); i++)
    {
      element = statechart->list->get(i);
      Serial.print(element.time);
      Serial.print(", ");
      Serial.print(element.pin);
      Serial.print(", ");
      Serial.print(element.status);
      Serial.println(" ");
    }
  }
  void loopArduino()
  {
    // put your main code here, to run repeatedly:
    Serial.println("no loop");
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
    showListStore();
  }
};
