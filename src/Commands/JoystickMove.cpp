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
	drivebase	-> Reset();
//	drivebase->Stop();
}

// Called repeatedly when this Command is scheduled to run
void JoystickMove::Execute()
{
	double Slew		=	oi 	->ReadJoystickX();
	if (Slew < deadX && Slew > (-1*deadX))
		Slew = 0;

	double Throttle	=	oi 	->ReadJoystickY();
	if (Throttle < deadY && Throttle > (-1*deadY))
		Throttle = 0;
	double Twist	=	oi 	->ReadJoystickZ();
	if (Twist < deadZ && Twist > (-1*deadZ))
		Twist = 0;
//	if (Logitech3DPro -> GetRawButton(Thumb))
//	{
//		double Sense	=	JoyPrecise;
//	} else double Sense = JoySense;

	double Left 	= Twist + Throttle;
	double Right 	= Twist - Throttle;
	double H		= Slew;
	SmartDashboard::PutNumber("X-Axis", Slew);
	SmartDashboard::PutNumber("Y-Axis", Throttle);
	SmartDashboard::PutNumber("Twist", Twist);

	double PrecisionMode = oi	->GetRawButton2();
	if(PrecisionMode == 1){
		drivebase->PrecisionMode(Left, Right, H);
	}else{
	drivebase	-> Drive(Left, Right, H, JoySense);//Sends the drive parameters with the default RobotMap Sensitivity, see DriveBase to override from the SmartDash
	}
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
