/*
  twirl.ino
  Example of LEGOPowerFunctions library,
    created by Mateusz Jaros / The JarOS.
    
  CONNECTIONS:
    *Arduino 
      IR LED connected by 220 Ohm resistor to 10 pin.
    *LEGO
      Motor connected to battery box by IR receiver(red connector and set on 1st channel).

  This sketch turns on motor for 1 second and then truns it off and
    waits 1 second.
*/

// Including library.
#include <legopowerfunctions.h>

// IR LED's pin. 
const int IRpin = 10;

// Time of working motor (in seconds).
int timeout = 1; 

LEGOPowerFunctions PF(IRpin); // Creating object called PF.

void setup() {

}

void loop() { 
  
  /* 
    We need give to IR signal to LEGO PF every 100 milliseconds, 
    so I used for loop to do this.  
  */
  
  for(int i = 0; i <= timeout*10; i++) { // timeout * 10 * 100 = time of working motor in milliseconds
    PF.ComboMode(RED_FWD, BLUE_BRK, CH1); // red direction, blue direction, channel
    delay(100);
  }
  // Stoping motor for 1 second.
  PF.ComboMode(RED_BRK, BLUE_BRK, CH1);
  delay(1000); 
 
  // Do the same in other direction.
  
  for(int i = 0; i < timeout*10; i++) {
    PF.ComboMode(RED_REV, BLUE_BRK, CH1);
    delay(100);
  }

  PF.ComboMode(RED_BRK, BLUE_BRK, CH1);
  delay(1000);
}
