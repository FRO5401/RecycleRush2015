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
	double 	Twist       =	oi	->	ReadJoystickX();
	double 	Throttle 	=	oi	->	GetTrigger();
	bool 	Precision	=	oi	->	GetPrecision();
	bool 	Brake		=	oi	->	GetBrake();
	double Right,Left, Sensitivity;

	if (Precision) { //Sets drive precision based on RobotMap and Precision Mode
		Sensitivity	=	Drive_Sensitivity_Precise;
	} else {
		Sensitivity	=	Drive_Sensitivity_Default;
	}

	if (Brake) {
		Right = 0;
		Left = 0;
	} else if (Twist > 0){									//Positive X axis means right turn
	Right = Throttle * (1 - Twist) * Sensitivity;
	Left = Throttle * (1) * Sensitivity;
	} else {
		Right = Throttle * (1) * Sensitivity;
		Left = Throttle * (1 + Twist) * Sensitivity;
	}

	drivebase        -> Drive(Left, Right, Precision, Brake);
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
