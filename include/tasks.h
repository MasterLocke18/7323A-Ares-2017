#ifndef _tasks_H_
#define _tasks_H_

// Sets the speeds of the left and right wheels of the chassis
void power(); //Creates a command named "power"
void ESTOP(); //Creates a command named "ESTOP"
void Lift(int used); //Creates a command named "Lift"
void LiftPOS(int value); //Creates a command named "LiftPOS"
void LiftDown(); //Creates a command named "LiftDown"
void	LiftUp(); //Creates a command named "LiftUp"
extern int Max_Height;
extern int Mix_Height;
#endif // _CHASSIS_H_
