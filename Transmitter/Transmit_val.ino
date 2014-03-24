#include <VirtualWire.h>

#define button_pin      4 //this is the pin that the button is plugged into
#define transmit_pin    10 //this is the pin the transmitter is plugged into
#define indicator       11//this is the on board led to tell when a message has been sent

int val;

char Sensor1CharMsg[4]; 

void setup()
{
  pinMode(indicator, OUTPUT);  //Sets up the onboard led to be an indicator
  pinMode(button_pin, INPUT);   //Sets up the button for input
  vw_set_tx_pin(transmit_pin); //Sets up the output pin for VW
  vw_setup(2000);
  Serial.begin(9600);
}

void loop()
{
   if (Serial.available()>0)
   {
      val = Serial.parseInt();
      itoa(val,Sensor1CharMsg,10);
      Serial.println(x);
      analogWrite(indicator, HIGH);
      vw_send((uint8_t *)Sensor1CharMsg, strlen(Sensor1CharMsg));;
      vw_wait_tx();
      analogWrite(indicator, LOW);
   }
}
