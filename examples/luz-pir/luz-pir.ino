//#include <AUnitVerbose.h>
#include <AUnit.h>
using namespace aunit;

#include "arduino/arduino.cpp"
#include "teste/teste.cpp"

void setup() {
  // put your setup code here, to run once:
  setupArduino();
  setupTeste();

}

void loop() {
  // put your main code here, to run repeatedly:
  loopArduino();
  loopTeste();
}
