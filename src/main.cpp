#include <M5StickC.h>

int PIN =36;
int sen;
void setup(){
    M5.begin();

    pinMode(PIN,ANALOG);
}

void loop(){
  if(analogRead(PIN)>0){
    sen=1;
    Serial.printf("%d\n",sen);
    delay(300);
  }else{
    sen=0;
    Serial.printf("%d\n",sen);
    delay(3000);
  }
}
