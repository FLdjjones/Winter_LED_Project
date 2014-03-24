#include <VirtualWire.h>

#define button_pin      4 //this is the pin that the button is pluged into
#define transmit_pin    10 //this is the pin the transmitter is pluged into
#define indicator       11//this is the onboard led to tell when a message has been sent

void setup()
{
  int i;
  pinMode(indicator, OUTPUT);  //Sets up the onboard led to be an indicator
  pinMode(button_pin, INPUT);   //Sets up the button for input
  vw_set_tx_pin(transmit_pin); //Sets up the output pin for VW
  vw_setup(2000);    //starts vitualwire
}

void loop()
{
  int buttonState = digitalRead(button_pin);

  if (buttonState == HIGH)
  {
    int i;
    if (i < 3)
    {
      vw_send((uint8_t *)i,1);
      vw_wait_tx();
      analogWrite(indicator, HIGH);
      delay(500);
      analogWrite(indicator, LOW);
      i++;
    }
     i = 0;
  }
  



}  
