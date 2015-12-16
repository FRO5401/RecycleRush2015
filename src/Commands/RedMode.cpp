/*
 * RedMode.cpp
 *
 *  Created on: Dec 4, 2015
 *      Author: AFRO
 */

#include "RedMode.h"
#include "RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"

RedMode::RedMode()
{
	//Declares required subsystems
	Requires(drivebase);

}

// Called just before this Command runs the first time
void RedMode::Initialize()
{
	drivebase->Stop();
}

// Called repeatedly when this Command is scheduled to run
void RedMode::Execute()
{
//	const double Half = 0.5 * Full; //Constant for throttling half speed. Full defined in RobotMap
	double Slew		=	0;
	double Throttle	=	-1;
	double Left 	= -1;
	double Right 	= -1;

	SmartDashboard::PutNumber("X-Axis", Slew);
	SmartDashboard::PutNumber("Y-Axis", Throttle);

//	drivebase	-> Drive(Left, Right, 0, JoySense);
	Wait(10);
}

// Make this return true when this Command no longer needs to run execute()
bool RedMode::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RedMode::End()
{
	drivebase	-> Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RedMode::Interrupted()
{

}

