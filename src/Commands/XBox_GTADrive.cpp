/*
 * MOH-GTADrive.cpp
 *
 *  Created on: Jan 13, 2016
 *      Author: AFRO
 */

#include <Commands/XBox_GTADrive.h>
#include "RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"

//double plzwork = 0;

XBox_GTADrive::XBox_GTADrive()
{
	//Declares required subsystems
	Requires(drivebase);
	plzwork = 0;
	plzwork2 = false;
}

// Called just before this Command runs the first time
void XBox_GTADrive::Initialize()
{
	drivebase	-> Reset();
//	drivebase->Stop();
	SmartDashboard::PutNumber("doesthiswork", plzwork);
	SmartDashboard::PutNumber("yesthisworks", plzwork2);
}

// Called repeatedly when this Command is scheduled to run
void XBox_GTADrive::Execute()
{
	double 	Slew       =	oi	->	ReadJoystickX();
	double Throttle 	=	oi	->	GetRightTrigger();
	double Reverse 	=	oi	->	GetLeftTrigger();
	bool 	Precision	=	oi	->	GetPrecision();
	bool 	Brake		=	oi	->	GetBrake();
	double Right,Left, Sensitivity;
	//bool turn 			= 	oi  -> 	GetButtonX();
	bool lightsOn		= oi -> GetButtonB();

	if (Precision) { //Sets drive precision based on RobotMap and Precision Mode
		Sensitivity	=	Drive_Sensitivity_Precise;
	} else {
		Sensitivity	=	Drive_Sensitivity_Default;
	}

	if (Brake) {
		Right = 0;
		Left = 0;
	//} else if (turn) {
	//	Left = -1 * (Sensitivity * Slew);
	//	Right = 1 * (Sensitivity * Slew);
	} else if (Slew > 0){									//Positive X axis(slew) means right turn
		Left = (Throttle - Reverse) * (1 - Slew) * Sensitivity;
		Right = (Throttle-Reverse) * (1) * Sensitivity;
	} else {
		Left = (Throttle-Reverse) * (1) * Sensitivity;
		Right = (Throttle-Reverse) * (1 + Slew) * Sensitivity;
	}

	SmartDashboard::PutNumber("Throttle Value",Throttle);
	SmartDashboard::PutNumber("Reverse Value",Reverse);
	SmartDashboard::PutNumber("Slew Value",Slew);
	//SmartDashboard::PutBoolean("Turn",turn);

	//For testing
	plzwork = SmartDashboard::GetNumber("doesthiswork", plzwork);
	if (plzwork != 0)
		std::cout << "It works! - " << plzwork << std::endl;
	else
		std::cout << "You failed!" << std::endl;

	plzwork2 = SmartDashboard::GetNumber("yesthisworks", plzwork2);
		if (plzwork)
			std::cout << "Works as well! - " << plzwork2 << std::endl;
		else
			std::cout << "You epicly failed!" << std::endl;


	//drivebase ->

	drivebase        -> Drive(Left, Right, plzwork);
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
