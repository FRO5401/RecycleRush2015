#include "JoystickMove.h"
#include "RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"

JoystickMove::JoystickMove()
{
	//Declares required subsystems
	Requires(drivebase);

}

// Called just before this Command runs the first time
void JoystickMove::Initialize()
{
//	drivebase->Stop();
}

// Called repeatedly when this Command is scheduled to run
void JoystickMove::Execute()
{
	double Slew		=	oi 	->ReadJoystickX();
	double Throttle	=	oi 	->ReadJoystickY();
	double Twist	=	oi 	->ReadJoystickZ();
	double Left 	= Twist - Throttle;
	double Right 	= Twist + Throttle;
	double H		= Slew;
	SmartDashboard::PutNumber("X-Axis", Slew);
	SmartDashboard::PutNumber("Y-Axis", Throttle);
	drivebase	-> Drive(Left, Right, H);
}

// Make this return true when this Command no longer needs to run execute()
bool JoystickMove::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void JoystickMove::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickMove::Interrupted()
{

}
