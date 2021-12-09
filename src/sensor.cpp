#include <M5StickC.h>
#include "sensor.hpp"

void Sensor::setPin(int set)
{
    pin = set;
    pinMode(pin, ANALOG);
}

int Sensor::getValue()
{
    i=0;
    averageValue=0;
    totalValue=0;
    while(i<60)
    {
        totalValue = totalValue + analogRead(pin);
        i++;
        delay(1000);
    }
    averageValue = totalValue / 60;

    if (averageValue > 1000)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}