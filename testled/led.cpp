/*****************
LED.cpp
******************/

#include"LED.h"
#include"Arduino.h"

LED::LED(byte p,bool state):m_pin(p)
{   
   pinMode(p,OUTPUT);
   digitalWrite(p,state);
}

LED::~LED()
{
    disattach();
} 

byte LED::getPin()
{
  return m_pin;
}
         
void LED::on()
{
    digitalWrite(m_pin,HIGH);
}

void LED::off()
{
   digitalWrite(m_pin,LOW);
}

bool LED::getState()
{
    return digitalRead(m_pin);
}

void LED::disattach()        //引脚回收，恢复到上电状态
{
    digitalWrite(m_pin,LOW);
    pinMode(m_pin,INPUT);
}
