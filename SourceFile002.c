#pragma config(Motor,  port1,           right,         tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port10,          left,          tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(true)
	{
		motor[right] = vexRT[Ch2];
		motor[left]= vexRT[Ch3];
		// robot goes full speed

	}
}
