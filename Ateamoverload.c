#pragma config(Motor,  port2,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           leftNine,      tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port4,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           rightNine,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           spinning1,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port7,           spinning2,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           spinning3,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           spinning4,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port10,          track,         tmotorVex393_HBridge, openLoop)
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

static const float ticksPerInch = 0.95 * (627.2 / (4.0 * PI));
//adjust to compensate for wheel slip
static const float ticksPerRev = 1.11 * (ticksPerInch * 12.0 * PI);

void move(float dist, int speed, bool hold)
{
	resetMotorEncoder(rightMotor);
	resetMotorEncoder(leftMotor);

	setMotorTarget(rightMotor, dist*ticksPerInch, speed, hold);
	setMotorTarget(leftMotor, dist*ticksPerInch, speed, hold);

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


task autonomous()
{
  //move(6, 100, false);
  //spin(0.25, 100, false);
  //move(20, 100,false);
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

  // User control code here, inside the loop
			nMotorPIDSpeedCtrl[leftMotor] = RegIdle;
			nMotorPIDSpeedCtrl[leftNine] = RegIdle;
			nMotorPIDSpeedCtrl[rightMotor] = RegIdle;
			nMotorPIDSpeedCtrl[rightNine] = RegIdle;
			nMotorPIDSpeedCtrl[spinning1] = RegIdle;
 			nMotorPIDSpeedCtrl[spinning2] = RegIdle;
			nMotorPIDSpeedCtrl[spinning3] = RegIdle;
			nMotorPIDSpeedCtrl[spinning4] = RegIdle;
			nMotorPIDSpeedCtrl[track] = RegIdle;

	while (1 == 1)
  {
    // Driving Motor Control
    motor[leftMotor] = (int)(vexRT[Ch3] / 2);
    motor[rightMotor] = (int)(vexRT[Ch2] / 2);

    // Arm Control
   	if(vexRT[Btn7U] == 1)
    {
      motor[leftNine] = -127;
      motor[rightNine] = -127;
    }
    else if(vexRT[Btn7D] == 1)
    {
      motor[leftNine] = 127;
      motor[rightNine] = 127;
    }
    else
    {
      motor[leftNine] = 12;
      motor[rightNine] = 12;
		}

		if(vexRT[Btn5U] == 1)
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
		if(vexRT[Btn6U] == 1)
    {
    	motor[track] = 127;
    }
    else if(vexRT[Btn6D] == 1)
    {
    	motor[track] = 0;
    }
    if(vexRT[Btn8U] == 1)
    {
    	motor[leftMotor] = 0;
   		motor[leftNine] = 0;
  		motor[rightMotor] = 0;
	   	motor[rightNine] = 0;
   		motor[spinning1] = 0;
   		motor[spinning2] = 0;
   		motor[spinning3] = 0;
   		motor[spinning4] = 0;
   		motor[track] = 0;
   	}
    delay(10);
  }
}
