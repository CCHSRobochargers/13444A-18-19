#pragma config(Sensor, dgtl8,  autoany,        sensorDigitalIn)
#pragma config(Sensor, dgtl9,  autofour,       sensorDigitalIn)
#pragma config(Sensor, dgtl10, autored,        sensorDigitalIn)
#pragma config(Sensor, dgtl11, autoblue,       sensorDigitalIn)
#pragma config(Sensor, dgtl12, autocap,        sensorDigitalIn)
#pragma config(Motor,  port1,           leftback,      tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightM2,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftNine,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           new,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rightNine,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           leftM2,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           leftMotor,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          rightback,     tmotorVex393_HBridge, openLoop, reversed)
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
	slaveMotor(leftM2, leftMotor);
	slaveMotor(rightM2, rightMotor);
	slaveMotor(leftback, leftMotor);
	slaveMotor(rightback, rightMotor);

	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
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
void blue_cap(void)
{
	motor(leftMotor) = 127;
	motor(rightMotor) = 127;
	delay(500);
	// go forward somewhat
	motor(leftMotor) = -75;
	motor(rightMotor) = -75;
	delay(300);
	// back up somewhat to put the tines down
	motor(leftMotor) = 80;
	motor(rightMotor) = 80;
	delay(1100);
	// go forward to the cap
	motor(leftMotor) = -80;
	motor(rightMotor) = 80;
	delay(450);
	// turn somewhat to move the ball out from under the cap
	motor(leftMotor) = 45;
	motor(rightMotor) = -45;
	delay(450);
	// turn back to face the other cap
	motor(leftMotor) = -100;
	motor(rightMotor) = -100;
	delay(500);
	// back up to stop touching the cap
	motor(leftMotor) = 0;
	motor(rightMotor) = 0;
	// stop so the robot doesn't go crazy
	delay(1000);

	delay(1000);

	// flip the second cap
}
void red_cap(void)
{
	motor(leftMotor) = 127;
	motor(rightMotor) = 127;
	delay(500);
	// go forward somewhat
	motor(leftMotor) = -75;
	motor(rightMotor) = -75;
	delay(300);
	// back up somewhat to put the tines down
	motor(leftMotor) = 80;
	motor(rightMotor) = 80;
	delay(1100);
	// go forward to the cap
	motor(leftMotor) = 80;
	motor(rightMotor) = -80;
	delay(450);
	// turn somewhat to move the ball out from under the cap
	motor(leftMotor) = -45;
	motor(rightMotor) = 45;
	delay(450);
	// turn back to face the other cap
	motor(leftMotor) = -100;
	motor(rightMotor) = -100;
	delay(500);
	// back up to stop touching the cap
	motor(leftMotor) = 0;
	motor(rightMotor) = 0;
	// stop so the robot doesn't go crazy
	delay(1000);

	delay(1000);

	// flip the second cap
}
void any_cap(void)
{
	motor(leftMotor) = 127;
	motor(rightMotor) = 127;
	delay(500);
	// go forward somewhat
	motor(leftMotor) = -75;
	motor(rightMotor) = -75;
	delay(300);
	// back up somewhat to put the tines down
	motor(leftMotor) = 75;
	motor(rightMotor) = 75;
	delay(1000);
	// go forward to the cap
	motor(leftMotor) = -80;
	motor(rightMotor) = 80;
	delay(450);
	// turn somewhat to move the ball out from under the cap
	motor(leftMotor) = 45;
	motor(rightMotor) = -45;
	delay(450);
	// turn back to face the other cap
	motor(leftMotor) = -100;
	motor(rightMotor) = -100;
	delay(500);
	// back up to stop touching the cap
	motor(leftMotor) = 0;
	motor(rightMotor) = 0;
	// stop so the robot doesn't go crazy
}
void blue_flag(void)
{
	motor(leftMotor) = -127;
	motor(rightMotor) = -127;
	delay(2500);
	// drive backwards to the low flag
	motor(leftMotor) = 0;
	motor(rightMotor) = 0;
	// stop so the robot doesn't break anything
}
void red_flag(void)
{
	motor(leftMotor) = -127;
	motor(rightMotor) = -127;
	delay(2500);
	// go backwards to the low flag
	motor(leftMotor) = 127;
	motor(rightMotor) = 127;
	delay(1000);
	// go forward some
	motor(leftMotor) = 127;
	motor(rightMotor) = -127;
	delay(2000);
	// turn to face the cap
	motor(leftMotor) = 0;
	motor(rightMotor) = 0;
	// stop so the robot doesn't break anything
}

task autonomous()
{
	if(SensorValue (autoblue) == 0) //needs the digital in port 11
	{
		blue_flag();
	}

	if(SensorValue (autocap) == 0) //needs the digital in port 12
	{
		blue_cap();
	}
	if(SensorValue (autored) == 0)// needs the digital in port 10
	{
		red_flag();
	}
	if(SensorValue (autofour) == 0)// needs the digital in port 9
	{
		red_cap();
	}
	if(SensorValue (autoany) == 0)// needs the digital in port 8
	{
		any_cap();
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
	bool go = false;
	bool backwheel = false;
	// User control code here, inside the loop

	while (true)
	{
		motor[leftMotor] = vexRT[Ch3];
		motor[rightMotor] = vexRT[Ch2];
		// drivetrain control

		if(vexRT[Btn7U] == 1)
		{
			motor[leftNine] = 100;
			motor[rightNine] = 100;
		}
		else if(vexRT[Btn7D] == 1)
		{
			motor[leftNine] = -100;
			motor[rightNine] = -100;
		}
		else
		{
			motor(leftNine) = 17;
			motor(rightNine)= 17;
		}
		// control for the lift

		if(backwheel)// backwheel is true
		{
			motor(new) = 127;
		}
		else if (!backwheel)// backwheel is false
		{
			motor(new) = 0;
		}
		if(vexRT[Btn5U] == 1)// turn backwheel off
		{
			backwheel = false;
		}
		else if(vexRT[Btn5D] == 1)// turn backwheel on
		{
			backwheel = true;
		}
		// control for the wheel flip going forward

		if(go)
		{
			motor[new] =  -127;
		}
		else if(!go)
		{
			motor[new] = 0;
		}
		if(vexRT[Btn6D] == 1)
		{
			go = false;
		}
		else if (vexRT[Btn6U] == 1)
		{
			go = true;
		}
		// control for the wheel flip going backward
	}
}
