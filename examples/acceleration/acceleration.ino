/*
  acceleration.ino
  Example of LEGOPowerFunctions library,
    created by Mateusz Jaros / The JarOS
    
    04.05.2015 
    
  CONNECTIONS:
    *Arduino 
      IR LED connected by 220 Ohm resistor to 10 pin.
    *LEGO
     Two motors connected to battery box by IR receiver(set on 1st channel).
     
     This sketch changes speeds of motors. Like remote controller 64227.
     */

// including library
#include <legopowerfunctions.h>

// IR LED's pin 
const int IRpin = 10;

int timeout = 2; // In seconds.

int counter = 0;

LEGOPowerFunctions PF(IRpin); // Creating object called PF. 

void setup() {
  
}

void loop() {
  
  /* 
    We need give to IR signal to LEGO PF every 100 milliseconds, 
    so I used for loop to do this.  
  */
  for(int i = 0; i <= timeout*10; i++)  { // timeout * 10 * 100 = time in seconds.
    // I used this switch to chanege speed of motors.
    switch(counter) {
      case 0:
        PF.ComboPWM(PWM_FLT, PWM_FLT, CH1); // Motors are stopped. 
        break;
      case 1:
        PF.ComboPWM(PWM_FWD1, PWM_REV1, CH1); // Motor red is speed 1 and blue is 1 too.
        break;
      case 2:
        PF.ComboPWM(PWM_FWD2, PWM_REV2, CH1);
        break;
      case 3:
        PF.ComboPWM(PWM_FWD3, PWM_REV3, CH1);
        break;
      case 4:
        PF.ComboPWM(PWM_FWD4, PWM_REV4, CH1);
        break;
      case 5:
        PF.ComboPWM(PWM_FWD5, PWM_REV5, CH1);
        break;
      case 6:
        PF.ComboPWM(PWM_FWD6, PWM_REV6, CH1);
        break;
      case 7:
        PF.ComboPWM(PWM_FWD7, PWM_REV7, CH1);
        break;
    }
    delay(100);
  }
  // Controlls speed changing.
  if(counter < 7)
    counter++;
  else
    counter = 0;
  
}
