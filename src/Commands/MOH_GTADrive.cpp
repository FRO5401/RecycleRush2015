/*
 * MOH-GTADrive.cpp
 *
 *  Created on: Jan 13, 2016
 *      Author: AFRO
 */

#include "Commands/MOH_GTADrive.h"
#include "RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"

MOH_GTADrive::MOH_GTADrive()
{
	//Declares required subsystems
	Requires(drivebase);

}

// Called just before this Command runs the first time
void MOH_GTADrive::Initialize()
{
	drivebase	-> Reset();
//	drivebase->Stop();
}

// Called repeatedly when this Command is scheduled to run
void MOH_GTADrive::Execute()
{
	double Twist        =	oi	->	ReadJoystickX();
	double FwdThrottle  =	oi	->	GetLeftTrigger();
	double RearThrottle	=	oi	->	GetRightTrigger();
	double Right,Left;

	if (Twist > 0){									//Positive X axis means right turn
	Right = (FwdThrottle - RearThrottle) * (1 - Twist);
	Left = (FwdThrottle - RearThrottle) * (1);
	} else {
		Right = (FwdThrottle - RearThrottle) * (1);
		Left = (FwdThrottle - RearThrottle) * (1 + Twist);
	}
	drivebase        -> Drive(Left, Right);
}

// Make this return true when this Command no longer needs to run execute()
bool MOH_GTADrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MOH_GTADrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MOH_GTADrive::Interrupted()
{

}
