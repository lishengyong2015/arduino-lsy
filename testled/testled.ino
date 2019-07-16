#include "led.h"
#include "pin.h"



LED led(LED_BUILTIN);
byte count =0;

void setup() {
  Serial.begin(9600);
}

void loop() {
 char idx = 0;
 for(idx =0; idx < 13; idx++)
 {
  GPIO pin(idx);
  if(0==pin.GetState())
  {
    Serial.write(idx+'0');
    Serial.print('\n');
    }
  }   
     delay(300);
}
