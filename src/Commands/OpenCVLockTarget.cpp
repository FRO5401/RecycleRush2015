#include <Commands/OpenCVLockTarget.h>
#include <Subsystems/OpenCVTargetAq.h>



OpenCVLockTarget::OpenCVLockTarget()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(opencvtargetaq);
}

// Called just before this Command runs the first time
void OpenCVLockTarget::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void OpenCVLockTarget::Execute()
{
	opencvtargetaq	->	Search();

}

// Make this return true when this Command no longer needs to run execute()
bool OpenCVLockTarget::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void OpenCVLockTarget::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OpenCVLockTarget::Interrupted()
{

}
