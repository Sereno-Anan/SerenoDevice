#include <M5StickC.h>
#include "Sensor.hpp"

void Sensor::setPin(int set)
{
    PIN = set;
    pinMode(PIN, ANALOG);
}

int Sensor::getValue()
{
    if (analogRead(PIN) > 100)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}