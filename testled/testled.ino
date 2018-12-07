#include "led.h"

LED led(LED_BUILTIN);
byte count =0;

void setup() {
  
}

void loop() {
  if(count<10)
   {
     led.on();
     delay(300);
     
     led.off();
     delay(300);
     
     ++count;
     if(count==10)
        led.disattach();
   }
}
