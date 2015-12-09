#include "Forward.h"
#include "SmartDashboard/SmartDashboard.h"

Forward::Forward()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(drivebase);//Same as regular subsystem
}

// Called just before this Command runs the first time
void Forward::Initialize()
{
	drivebase->Stop();//Makes sure robot is motionless before acting
}

// Called repeatedly when this Command is scheduled to run
void Forward::Execute()
{
	//Copied code from FroshBot
	double Slew = 0;
	double Throttle = 1;
	double Left = -1;
	double Right = 1;

	SmartDashboard::PutNumber("X-Axis", Slew);
	SmartDashboard::PutNumber("Y-Axis", Throttle);

	drivebase->Drive(Left, Right, 0);//Drive function is from drivebase
}

// Make this return true when this Command no longer needs to run execute()
bool Forward::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Forward::End()
{
	drivebase->Drive(0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Forward::Interrupted()
{

}
