#include "CheckGyro.h"

CheckGyro::CheckGyro()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(drivebase);
}

// Called just before this Command runs the first time
void CheckGyro::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CheckGyro::Execute()
{
	drivebase		->ReportGyro();

}

// Make this return true when this Command no longer needs to run execute()
bool CheckGyro::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void CheckGyro::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CheckGyro::Interrupted()
{

}
