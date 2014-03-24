#include <VirtualWire.h>
//#include <DigiUSB.h>
#define redPin       0 // this is the pin the red pin is on
#define greenPin     1 // this is the pin the green pin is on 
#define bluePin      4 // this is the pin the blue pin is on 
#define receive_pin  5 // this is the pin the reciever is on

int val;
 
char Sensor1CharMsg[4]; 


void setup()
{
  vw_set_rx_pin(receive_pin);
  vw_setup(2000); // Bits per sec
  vw_rx_start();  // Start the receiver PLL running
 // DigiUSB.begin();
  


}

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

      if (vw_get_message(buf, &buflen)) 
    {
    int i;
        // Message with a good checksum received, dump it. 
        for (i = 0; i < buflen; i++)
    {            
          // Fill Sensor1CharMsg Char array with corresponding 
          // chars from buffer.   
          Sensor1CharMsg[i] = char(buf[i]);
    }
        
        // Null terminate the char array
        // This needs to be done otherwise problems will occur
        // when the incoming messages has less digits than the
        // one before. 
        Sensor1CharMsg[buflen] = '\0';
        
        // Convert Sensor1CharMsg Char array to integer
        val = atoi(Sensor1CharMsg);
        
    switch(val)    // 1st stage no color
    {
     case 0:
      analogWrite(redPin, 255);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 255);
                                 // 1 is added to the value to make it go to the next color the next time
                      // 2nd stage red color
     case 1:
      analogWrite(redPin, 0);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 255);
                                 // 1 is added to the value to make it go to the next color the next time     
      
    case 2:                    // 3rd stage blue color
      analogWrite(redPin, 255);
      analogWrite(bluePin, 0);
      analogWrite(greenPin, 255);
          // 1 is added to the value to make it go to the next color the next time
  
    case 3:                   // 4th stage green color
      analogWrite(redPin, 255);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 0);
                             // value resets so the loop starts over
      
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


