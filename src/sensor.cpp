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
    time_t endTime;
    int i=0;
    int totalValue=0;
    int averageValue=0;
    endTime = time(NULL) + 30;
    while (time(NULL) < endTime)
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