#include <M5StickC.h>
#include "sensor.hpp"
#include <time.h>

void Sensor::setPin(int set)
{
    pin = set;
    pinMode(pin, ANALOG);
}

int Sensor::getStatus()
{
    time_t endTime;
    int i = 0;
    int totalValue = 0;
    int averageValue = 0;
    measureTime = 30;
    endTime = time(NULL) + measureTime;
    while (time(NULL) < endTime)
    {
        totalValue = totalValue + analogRead(pin);
        i++;
    }
    averageValue = totalValue / i;

    return averageValue;
}