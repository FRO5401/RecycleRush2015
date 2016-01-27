/*
 * MOH-GTADrive.cpp
 *
 *  Created on: Jan 13, 2016
 *      Author: AFRO
 */

#include <Commands/XBox_GTADrive.h>
#include "RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"

XBox_GTADrive::XBox_GTADrive()
{
	//Declares required subsystems
	Requires(drivebase);

}

// Called just before this Command runs the first time
void XBox_GTADrive::Initialize()
{
	drivebase	-> Reset();
//	drivebase->Stop();
}

// Called repeatedly when this Command is scheduled to run
void XBox_GTADrive::Execute()
{
	double 	Slew       =	oi	->	ReadJoystickX();
	double 	Throttle 	=	oi	->	GetRightTrigger();
	double 	Reverse 	=	oi	->	GetLeftTrigger();
	bool 	Precision	=	oi	->	GetPrecision();
	bool 	Brake		=	oi	->	GetBrake();
	double Right,Left, Sensitivity;
	bool turn = false;

	if (Precision) { //Sets drive precision based on RobotMap and Precision Mode
		Sensitivity	=	Drive_Sensitivity_Precise;
	} else {
		Sensitivity	=	Drive_Sensitivity_Default;
	}

	if (Throttle == 0 && Reverse == 0)
		turn = true;

	if (Brake) {
		Right = 0;
		Left = 0;
	} else if (Slew > 0){									//Positive X axis means right turn
		if (turn){ //Turn right
			Left = -1 * Sensitivity;
			Right = 1 * Sensitivity;
		} else{
			Left = (Throttle - Reverse) * (1 - Slew) * Sensitivity;
			Right = (Throttle-Reverse) * (1) * Sensitivity;
		}
	} else {
		if (turn){ //Turn left
			Left = 1 * Sensitivity;
			Right = -1 * Sensitivity;
		} else {
			Left = (Throttle-Reverse) * (1) * Sensitivity;
			Right = (Throttle-Reverse) * (1 + Slew) * Sensitivity;
		}
	}


	drivebase        -> Drive(Left, Right);
}

// Make this return true when this Command no longer needs to run execute()
bool XBox_GTADrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void XBox_GTADrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void XBox_GTADrive::Interrupted()
{

}
