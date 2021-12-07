#ifndef SENSOR_HPP
#define SENSOR_HPP

class Sensor
{
private:
    int pin;

public:
    void setPin(int set);//引数は入力PIN
    int getValue();//AD変換したセンサの値を返す(1なら雨,0なら晴れ)
};
#endif