/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

//Allows all commands, variables, etc. defined in the below header files to be used in this file
 #include "main.h"
 #include "voids.h"
 #include "tasks.h"
 #include "options.h"
/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */


void operatorControl() {
  lcdPrint(uart2,0,"Auton Test");
  //SimpleAutonomous();
  delay(2000);//please remove this before competion
  //SimpleAutonomous();
	while (1)
  {
    int threshold = 30, v = 0, w = 0;
    if(abs(joystickGetAnalog(1, 3)) > threshold || abs(joystickGetAnalog(1, 4)) > threshold)
    {
      v = joystickGetAnalog(1, 3);
      w = joystickGetAnalog(1, 4);
      if(joystickGetDigital(1, 5, JOY_DOWN) == 1)
      {
        v = v / 2;
        w = w / 2;
      }
    }
    else
    {
      if(abs(joystickGetAnalog(2, 3)) > threshold || abs(joystickGetAnalog(2, 4)) > threshold)
      {
        v = joystickGetAnalog(2, 3);
        w = joystickGetAnalog(2, 4);
        if(joystickGetDigital(2, 5, JOY_DOWN) == 1)
        {
          v = v / 2;
          w = w / 2;
        }
      }
      drive(v,w);
    }
		/*int central  = joystickGetAnalog(1, 3)+joystickGetAnalog(2, 3);
    int lateral = joystickGetAnalog(1, 4);
		int rotational   = joystickGetAnalog(1, 1)+joystickGetAnalog(2, 1);
		drive(central, lateral, rotational); //Allows the user to control the movement of the robot*/
		bool open  = (joystickGetDigital(1,8,JOY_RIGHT))||(joystickGetDigital(2,8,JOY_RIGHT))||(joystickGetDigital(1,5,JOY_UP))||(joystickGetDigital(2,5,JOY_UP));
		bool close = (joystickGetDigital(1,8,JOY_DOWN))||(joystickGetDigital(2,8,JOY_DOWN))||(joystickGetDigital(1,5,JOY_DOWN))||(joystickGetDigital(2,5,JOY_UP));
		int  hold  = (joystickGetDigital(1,8,JOY_LEFT))||(joystickGetDigital(2,8,JOY_LEFT));
		userclaw(open, close, hold); //Allows the user to control the claw
    Lift(joystickGetDigital(1,6,JOY_UP)-joystickGetDigital(1,6,JOY_DOWN)+joystickGetDigital(2,6,JOY_UP)-joystickGetDigital(2,6,JOY_DOWN)); //Allows the user to control the lift
		delay(20);
	}
}
