#ifndef _voids_H_
#define _voids_H_

// Sets the speeds of the left and right wheels of the chassis

void drive(int v, int w);
void closeClaw(); //Creates a command named "closeClaw"
void openClaw(); //Creates a command named "openClaw"
void userclaw(bool open, bool close, int hold); //Creates a command named "userclaw" that uses two logic variables named "open" and "clos" and one variable named "hold"
void stopAllMotors(); //Creates a command named "stopAllMotors"
void wait1Msec(int duration); //Creates a command named "wait1Msec" that uses one variable named "duration"

void drive(int v, int w); //Velocity in the Y-axis and rotational velocity around the Z-axis
void closeClaw();
void openClaw();
void userclaw(bool open, bool close, int hold);
void stopAllMotors();
void wait1Msec(int duration);
void 	stopClaw();

extern int DriveL;
extern int DriveR;
extern int backRight;
extern int topLift;
extern int frontRight;//reverse
extern int rightClaw;//reverse
extern int midRight;//reverse
extern int midLeft;
extern int leftClaw;
extern int frontLeft;
extern int backLeft;
extern int bottomLift;//reverse
extern int clawtime;
#endif // _CHASSIS_H_
