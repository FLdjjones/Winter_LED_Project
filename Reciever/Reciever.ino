#include <VirtualWire.h>

#define redPin       0 // this is the pin the red pin is on
#define greenPin     1 // this is the pin the green pin is on 
#define bluePin      4 // this is the pin the blue pin is on 
#define receive_pin  5 // this is the pin the reciever is on


void setup()
{
  vw_set_rx_pin(receive_pin);
  vw_setup(2000); // Bits per sec
  vw_rx_start();  // Start the receiver PLL running
  

 
}

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  
  if (vw_get_message(buf, &buflen)) // Non-blocking
    {
     int val  ;                       //this is the stage of colors we are on 
     if(val == 0);                    // 1st stage no color
     {
     analogWrite(redPin, 255);
     analogWrite(bluePin, 255);
     analogWrite(greenPin, 255);
     val++;                           // 1 is added to the value to make it go to the next color the next time
     }
     
     
     if(val == 1);                    // 2nd stage red color
     {
     analogWrite(redPin, 0);
     analogWrite(bluePin, 255);
     analogWrite(greenPin, 255);
     val++;                           // 1 is added to the value to make it go to the next color the next time     
     }
     
     
     if(val == 2);                    // 3rd stage blue color
     {
     analogWrite(redPin, 255);
     analogWrite(bluePin, 0);
     analogWrite(greenPin, 255);
     val++;                           // 1 is added to the value to make it go to the next color the next time
     }
          
     
     if(val == 3);                    // 4th stage green color
     {
     analogWrite(redPin, 255);
     analogWrite(bluePin, 255);
     analogWrite(greenPin, 0);
     val = 0;                         // value resets so the loop starts over
     }
               
    }
}










//This code may be used if noise is an issue


/*  int mail = vw_have_message();        //mail = ture when there is a message waiting
  
  if (mail == true);               //you've got mail!
  {
   int failsafe = vw_wait_rx_max(50);  //waits for message for 50ms if nothing returns false
   
   if (failsafe == true);              //and the mail you got is real mail!
   {
     vw_get_message(buf, &buflen);
   }
  
 
  }

*/

