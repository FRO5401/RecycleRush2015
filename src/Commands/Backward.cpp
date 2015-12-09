#include "Backward.h"

Backward::Backward()
{
	// Use Requires() here to declare subsystem dependencies
	Requires (drivebase);
}

// Called just before this Command runs the first time
void Backward::Initialize()
{
	drivebase->Stop();
}

// Called repeatedly when this Command is scheduled to run
void Backward::Execute()
{
	//Copied Forward but change the values to go in right direction
	double Slew = 0;
	double Throttle = -1;
	double Left = 1;
	double Right = -1;

	SmartDashboard::PutNumber("X-Axis", Slew);
	SmartDashboard::PutNumber("Y-Axis", Throttle);

	drivebase->Drive(Left, Right, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool Backward::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Backward::End()
{
	drivebase->Drive(0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Backward::Interrupted()
{

}
