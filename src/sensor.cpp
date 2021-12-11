#include <M5StickC.h>
#include "sensor.hpp"
#include <time.h>

void Sensor::setPin(int set)
{
    pin = set;
    pinMode(pin, ANALOG);
}

int Sensor::getValue()
{
    startTime = time(NULL);
    endTime = startTime + 30;
    i = 0;
    averageValue = 0;
    totalValue = 0;
    while (startTime > endTime)
    {
        totalValue = totalValue + analogRead(pin);
        i++;
    }
    averageValue = totalValue / i;

    if (averageValue > 1000)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}