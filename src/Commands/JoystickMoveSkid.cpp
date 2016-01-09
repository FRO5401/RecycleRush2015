#include <Commands/JoystickMoveSkid.h>
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
	drivebase	-> Reset();
//	drivebase->Stop();
}

// Called repeatedly when this Command is scheduled to run
void JoystickMove::Execute()
{
	double Slew                =        oi         ->ReadJoystickX();
	double Throttle        =        oi         ->ReadJoystickY();
	double Twist        =        oi         ->ReadJoystickZ();
	double V = (100-abs(Throttle)) * (Twist/100) + Twist;
	double W = (100-abs(Twist)) * (Throttle/100) + Throttle;
	double Right = (V-W)/2;
	double Left = (V+W)/2;
	drivebase        -> Drive(Left, Right);
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
