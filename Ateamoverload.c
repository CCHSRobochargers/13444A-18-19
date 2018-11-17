#pragma config(Sensor, dgtl11, auto1,          sensorDigitalIn)
#pragma config(Sensor, dgtl12, autoselect,     sensorDigitalIn)
#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightNine,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           flipper,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           leftM2,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rightM2,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           leftNine,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           rightMotor,    tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void cap(void)
	{
		motor(leftMotor) = 127;
		motor(rightMotor) = 127;
		motor(leftM2) = 127;
		motor(rightM2) = 127;
		delay(500);
		// go forward somewhat
		motor(leftMotor) = -127;
		motor(rightMotor) = -127;
		motor(leftM2) = -127;
		motor(rightM2) = -127;
		delay(300);
		// back up somewhat to put the tines down
		motor(leftMotor) = 127;
		motor(rightMotor) = 127;
		motor(leftM2) = 127;
		motor(rightM2) = 127;
		delay(1240);
		// go forward to the cap
		motor(leftMotor) = -100;
		motor(rightMotor) = 100;
		motor(leftM2) = -100;
		motor(rightM2) = 100;
		delay(1000);
		// turn somewhat to move the ball out from under the cap
		motor(leftMotor) = -100;
		motor(rightMotor) = -100;
		motor(leftM2) = -100;
		motor(rightM2) = -100;
		delay(1000);
		// back up to stop touching the cap
		motor(leftMotor) = 0;
		motor(rightMotor) = 0;
		motor(leftM2) = 0;
		motor(rightM2) = 0;
		// stop so the robot doesn't go crazy
	}
void flag(void)
	{
		motor(leftMotor) = -127;
		motor(leftM2) = -127;
		motor(rightMotor) = -127;
		motor(rightM2) = -127;
		delay(2500);
		// go backwards to the low flag
		motor(leftMotor) = 127;
		motor(leftM2) = 127;
		motor(rightMotor) = 127;
		motor(rightM2) = 127;
		delay(1000);
		// come back to the starting square
		motor(leftMotor) = 0;
		motor(leftM2) = 0;
		motor(rightMotor) = 0;
		motor(rightM2) = 0;
		// stop so the robot doesn't break anything
	}

task autonomous()
{
	if(SensorValue (auto1) == 0) //needs the jumper in port 11
	{
		flag();
	}

	if(SensorValue (autoselect) == 0) //needs the jumper cable out of port 12
	{
		cap();
	}
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{

//int lift;

while (1 == 1)
{
	// Driving Motor Control
	motor[leftMotor] = vexRT[Ch3];
	motor[leftM2] = vexRT[Ch3];
	motor[rightMotor] = vexRT[Ch2];
	motor[rightM2] = vexRT[Ch2];

	if(vexRT[Btn7U] == 1)
	{
		motor[leftNine] = 70;
		motor[rightNine] = 70;
	}
	else if(vexRT[Btn7D] == 1)
	{
		motor[leftNine] = -70;
		motor[rightNine] = -70;
	}
	else
	{
		motor[leftNine] = 17;
		motor[rightNine] = 17;
	}
	// this is our lift control

	/*lift = vexRT[Ch2] + 20;
	if(lift > 127)
	{
	lift = 127;
	}
	motor[leftNine] = lift;
	motor[rightNine] = lift;*/

	/*if(vexRT[Btn5U] == 1)
	{
	motor[spinning1] = 127;
	motor[spinning2] = 127;
	motor[spinning3] = 127;
	motor[spinning4] = 127;
	}
	else
	{
	motor[spinning1] = 0;
	motor[spinning2] = 0;
	motor[spinning3] = 0;
	motor[spinning4] = 0;
	}
	// shooting mechanism control

	if(vexRT[Btn6U] == 1)
	{
	motor[track] = 127;
	}
	else if(vexRT[Btn6D] == 1)
	{
	motor[track] = 0;
	}
	// control for the belt that carries the balls up to the shooter
	*/
	if(vexRT[Btn8L] == 1)
	{
		motor[flipper] = 127;
	}
	else if(vexRT[Btn8D] == 1)
	{
		motor[flipper] = -127;
	}
	else
	{
		motor[flipper] = 0;
	}
	// cap flipper control*/

	if(vexRT[Btn8U] == 1)
	{
		motor[leftMotor] = 0;
		motor[leftNine] = 0;
		motor[rightMotor] = 0;
		motor[rightNine] = 0;
		/*motor[spinning1] = 0;
		motor[spinning2] = 0;
		motor[spinning3] = 0;
		motor[spinning4] = 0;
		motor[track] = 0;*/
	}
	delay(10);
}
}
