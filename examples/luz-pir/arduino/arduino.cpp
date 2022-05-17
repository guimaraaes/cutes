#include <Arduino.h>
const int pinoPIR = 3;
const int pinoLED = 13;
int ledStatus;

class Arduino
{
public:
  void setupArduino()
  {
    // put your setup code here, to run once:
    pinMode(pinoLED, OUTPUT);
    pinMode(pinoPIR, INPUT);
  }

  void loopArduino()
  {
    // put your main code here, to run repeatedly:
    // if (digitalRead(pinoPIR) == HIGH)
    // {
    //   digitalWrite(pinoLED, HIGH);
    //   ledStatus = 1;
    // }
    // else if (digitalRead(pinoPIR) == LOW)
    // {
    //   digitalWrite(pinoLED, LOW);
    // }
    digitalWrite(pinoLED, HIGH);
    delay(1000);
    digitalWrite(pinoLED, LOW);
    delay(1000);
  }
};
