/** @file servo.cpp
 *  @brief Code to drive Servo Motors with RPI 4 over using GPIO and generate 0 - 180 deg
 *   circular motion.
 * 
 *  @author Plabini Jibanjyoti Nayak 
 *  @bug    File not tested since there is error while binding.
 */

/**-------------------------------------------------------------------------------
                        ## Function Description ## 
*--------------------------------------------------------------------------------
* rotate_servo() - Function to generate 0-180 deg circular motion after every 30ms 
* delay.
* main() - Main function.
*-----------------------------------------------------------------------------------
*/

/* --- Standard Includes --- */
#include <stdio.h>
#include <shunyaInterfaces.h>

/**
 * @macro Defines the GPIO pin 12
 * 
 */

#define Output_Pin 12

/**
 *
 *  @brief: rotate_servo() - Function to generate 0-180 deg circular motion after every 30ms delay.
 * 
 */
public void rotate_servo(){
   float duty_cycle;
   softPwmBegin(Output_Pin, 2.5, 500);//Start the PWM at a initial duty cycle and a defined Pulse width

// For every 11.1 microsecond change in pulse width, there is a change of 1 degree. Changes made to calculation present in https://raspberrypi.stackexchange.com/questions/108111/what-is-the-relationship-between-angle-and-servo-motor-duty-cycle-how-do-i-impl .
   for(int i=(500+11.11); i<=2500; i=i+11.11){
         duty_cycle= i/20000;//Calculate duty_cycle for the pulse width.
         softPwmWrite(Input_Pin,duty_cycle); //Change the PWM duty cycle.
         delay(30);//delay of 30ms.
      }
   softPwmEnd(Output_Pin);//Stop the PWM on a pin.
}

/** 
 *  @brief Main function.
 */
void main(){

   initLib();
   pinmode(Output_Pin, OUTPUT);//Sets the direction of the GPIO pin to OUTPUT
   while(1){
      rotate_servo();// Calling rotate servo function
   }
    
}
