#pragma config(Motor,  port2,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           leftNine,      tmotorServoContinuousRotation, openLoop)
<<<<<<< HEAD
#pragma config(Motor,  port4,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           rightNine,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port6,           center,        tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

static const float ticksPerInch = 0.95 * (627.2 / (4.0 * PI));
//adjust to compensate for wheel slip
=======
#pragma config(Motor,  port4,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           rightNine,     tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

static const float ticksPerInch = 0.95 * (627.2 / (4.0 * PI));

>>>>>>> f6bf8cb57a78b623809a1a239b643194244ba62e
static const float ticksPerRev = 1.11 * (ticksPerInch * 12.0 * PI);

void move(float dist, int speed, bool hold)
{
	resetMotorEncoder(rightMotor);
	resetMotorEncoder(leftMotor);

<<<<<<< HEAD
	setMotorTarget(leftMotor, dist*ticksPerInch, speed, hold);
	setMotorTarget(rightMotor, dist*ticksPerInch, speed, hold);
=======
	setMotorTarget(rightMotor, dist*ticksPerInch, speed, hold);
	setMotorTarget(leftMotor, dist*ticksPerInch, speed, hold);
	// printf("%f", dist*ticksPerInch);
>>>>>>> f6bf8cb57a78b623809a1a239b643194244ba62e

	while (!getMotorTargetCompleted(rightMotor) && !getMotorTargetCompleted(leftMotor))
		wait1Msec(10);
}

void spin(float rev, int speed, bool hold)
{
	resetMotorEncoder(rightMotor);
	resetMotorEncoder(leftMotor);

	setMotorTarget(rightMotor, rev*ticksPerRev, speed, hold);
	setMotorTarget(leftMotor, -rev*ticksPerRev, speed, hold);

	while (!getMotorTargetCompleted(rightMotor) && !getMotorTargetCompleted(leftMotor))
		wait1Msec(10);
}

<<<<<<< HEAD
task main()
{
	// drive forward
	move(6, 127, false);

	// do a 360
	spin(1, 100, false);

	// run into the wall
	move(12, 127,false);

=======

task autonomous()
{
	//drive forward
	move(3.0, 127, false);
	//do a 360
	spin(1.0, 127, false);
	//run into the wall
	move(12.0, 127, false);
>>>>>>> f6bf8cb57a78b623809a1a239b643194244ba62e
}