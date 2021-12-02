#include <M5StickC.h>
#include "Sensor.hpp"

Sensor sen;

void setup(){
  M5.begin();
  sen.setPin(36);
}

void loop(){
  sen.getValue();
}