#include <VirtualWire.h>

#define button_pin      1 //this is the pin that the button is pluged into
#define transmit_pin    2 //this is the pin the transmitter is pluged into
#define indicator       13//this is the onboard led to tell when a message has been sent

void setup()
{
  pinMode(indicator, OUTPUT);  //Sets up the onboard led to be an indicator
  pinMode(button_pin, INPUT);   //Sets up the button for input
  vw_set_tx_pin(transmit_pin); //Sets up the output pin for VW
  vw_setup(2000);              //starts vitualwire
}

void loop()
{
  int buttonState = digitalRead(button_pin);
  
  if (buttonState == HIGH)
  {
    vw_send((uint8_t *)1,1);
    vw_wait_tx();
  }




}  
