#include "Commands/XboxMoveSkid.h"
#include "RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"

XboxMoveSkid::XboxMoveSkid()
{
	//Declares required subsystems
	Requires(drivebase);

}

// Called just before this Command runs the first time
void XboxMoveSkid::Initialize()
{
	drivebase	-> Reset();
//	drivebase->Stop();
}

// Called repeatedly when this Command is scheduled to run
void XboxMoveSkid::Execute()
{
	double Slew                =        oi         ->ReadJoystickX();
	double Throttle        =        oi         ->ReadJoystickY();
	double Twist        =        oi         ->ReadJoystickZ();
	double V = (100-abs(Throttle)) * (Slew/100) + Slew;
	double W = (100-abs(Slew)) * (Throttle/100) + Throttle;
	double Right = (V-W)/2;
	double Left = (V+W)/2;
	drivebase        -> Drive(Left, Right);
}

// Make this return true when this Command no longer needs to run execute()
bool XboxMoveSkid::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void XboxMoveSkid::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void XboxMoveSkid::Interrupted()
{

}
