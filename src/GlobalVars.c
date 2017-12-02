//Allows all commands, variables, etc. defined in the below header files to be used in this file
#include "main.h"
#include "GlobalVars.h"
#define GYRO_PORT 3




int count = 0;                    //Which autonomous to do by default
const unsigned int leftButton = 1;//Pre-Auton Variables
const unsigned int centerButton = 2;
const unsigned int rightButton = 4;
char option_1[] = "Simple Auton";//Replaced all strings with char arrays
char option_2[] = "Left Cube";
char option_3[] = "Right Cube";
char option_4[] = "Skills Auton";
char Mode[] = "Usercontrol";




int clawtime = 900;                                                             //Declars a variable named "clawtime" and initializes it to 900
int clawsign = 1;          //Needs to be either 1 or -1                         //Declars a variable named "clawsign" and initializes it to 1
int clawEnable = 1;          //Needs to be either 0 or 1                        //Declars a variable named "clawEnable" and initializes it to 1
int clawFuzz = 1;          //How far does the claw move in ESTOP_RATE ms        //Declars a variable named "clawFuzz" and initializes it to 1
int clawStartTime = 100;                                                        //Declars a variable named "slawStartTime" and initializes it to 100
int ESTOP_RATE = 10;                                                            //Declars a variable named "ESTOP_RATE" and initializes it to 10
int driveSign = 1;                                                              //Declars a variable named "driveSign" and initializes it to 1
//int Limit = 0;                                                                //Declars a variable named "Limit" and initializes it to 0
int holdSet;                                                                    //Declars a variable named "holdset"

/*
//This section allows for the name of a motor port to be used in replace of the number of the motor port
int backRight  = 1;                                                             //Declars a variable named "backRight" and initializes it to 1
int topLift    = 2;                                                             //Declars a variable named "topLift" and initializes it to 2
int frontRight = 3;  //reverse                                                  //Declars a variable named "frontRight" and initializes it to 3
int rightClaw  = 4;  //reverse                                                  //Declars a variable named "rightClaw" and initializes it to 4
int midRight   = 5;  //reverse                                                  //Declars a variable named "midRight" and initializes it to 5
int midLeft    = 6;                                                             //Declars a variable named "midLeft" and initializes it to 6
int leftClaw   = 7;                                                             //Declars a variable named "leftClaw" and initializes it to 7
int frontLeft  = 8;                                                             //Declars a variable named "frontLeft" and initializes it to 8
int bottomLift = 9;   //reverse                                                 //Declars a variable named "bottomLift" and initializes it to 9
int backLeft   =10;                                                             //Declars a variable named "backLeft" and initializes it to 10
*/

int DriveL = 2;
int DriveR = 9;


int Bat1;                                                                       //Declars a variable named "Bat1"
int Bat2;                                                                       //Declars a variable named "Bat2"
int Bat3;                                                                       //Declars a variable named "Bat3"
int status = 1;                                                                 //Declars a variable named "status" and initializes it to 1
int Max_Height = 825;   //The maximum desired height of the lift - 0800         //Declara a variable named "Max_Height" and initializes it to 825
int Min_Height = 3100;                                                          //Declars a variable named "Min_Hieght" and initializes it to 3100
int LiftAngle  = 2;                                                             //Declars a variable named "LiftAngle" and initializes it to 2
int Limit = 0;                                                                  //Declars a variable named "Limit" and initializes it to 0



int lgyro;
int rgyro;
