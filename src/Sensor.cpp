#include "sensor.hpp"

void Sensor::setPin(int set)
{
    pin = set;
    pinMode(pin, ANALOG);
}

int Sensor::getValue()
{
    if (analogRead(pin) > 1000)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}