#include <Arduino.h>
const int pinoPIR = 3;
const int pinoLED = 13;

#include "../statechart/statechart.cpp"
// Statechart *statechart = Statechart::get();

class Arduino
{

public:
  void setupArduino()
  {
    // put your setup code here, to run once:
    pinMode(pinoLED, OUTPUT);
    pinMode(pinoPIR, INPUT);
  }

  void loopArduino(Statechart *statechart)
  {

    // put your main code here, to run repeatedly:
    // Serial.println(digitalRead(pinoPIR));
    if (digitalRead(pinoPIR) == HIGH)
    {
      statechart->pir->set(true);

      digitalWrite(pinoLED, HIGH);
      statechart->luz->set(false);
    }
    else if (digitalRead(pinoPIR) == LOW)
    {
      statechart->pir->set(false);

      digitalWrite(pinoLED, LOW);
      statechart->luz->set(true);
    }
    delay(1000);
  }
};
