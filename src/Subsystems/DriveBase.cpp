/*
 * DriveBase.cpp
 *
 *  Created on: Jul 13, 2015
 *      Author: KJM
 * H-drive for 2015 Recycle Rush Robot, test case for Command Arch
 *
 *
 */
#include "DriveBase.h"
#include "../RobotMap.h"
#include "../Commands/JoystickMove.h"
//#include "Preferences.h"

DriveBase::DriveBase() :	Subsystem("DriveBase")
{
  LeftDrive 	= new Talon(MotorLeft);
  RightDrive 	= new Talon(MotorRight);
  HDrive		= new Victor(MotorH);
  RightEnc		= new Encoder(Enc_Rt_A,Enc_Rt_B,true,Encoder::k1X);
  LeftEnc		= new Encoder(2,3, true, Encoder::k1X);
//  RoboPrefs		= new Preferences;
}
void DriveBase::InitDefaultCommand()
{
	  //Default function when class is first created
		LeftEnc ->Reset();
		RightEnc ->Reset();
		LeftEnc -> SetDistancePerPulse(DPP);
	SetDefaultCommand(new JoystickMove());
}

void DriveBase::Drive(double LeftDriveDesired, double RightDriveDesired, double HDriveDesired, double Sensitivity) //axes of joystick
{
//  RoboPrefs = Preferences::GetInstance();
//  Sensitivity = SmartDashboard::GetNumber("JoystickSensitivity", JoySense); //Use this to debug and dial in the sensitivity on the joystick
  SmartDashboard::PutNumber("Drive Left", LeftEnc -> Get());
  SmartDashboard::PutNumber("Drive Right", RightEnc -> Get());
  SmartDashboard::PutNumber("Drive Left", LeftEnc -> GetDistance());
  SmartDashboard::PutNumber("Drive Right", RightEnc -> GetDistance());
  LeftDrive 	-> Set(Sensitivity * LeftDriveDesired); //passes desired state to speed controllers
  RightDrive 	-> Set(Sensitivity * RightDriveDesired);
  HDrive		-> Set(Sensitivity * HDriveDesired);

}

void DriveBase::Stop()
{

  LeftDrive		-> Set(0);
  RightDrive	-> Set(0);
  HDrive		-> Set(0);

}

void DriveBase::Reset()
{
	LeftEnc ->Reset();
	RightEnc ->Reset();
	LeftDrive		-> Set(0);
	RightDrive	-> Set(0);
	HDrive		-> Set(0);

}

void DriveBase::PrecisionMode(double LeftDriveDesired, double RightDriveDesired, double HDriveDesired)
{
	LeftDrive->Set(LeftDriveDesired*JoyPrecise);
	RightDrive->Set(LeftDriveDesired*JoyPrecise);
	HDrive->Set(HDriveDesired*JoyPrecise);
}

//}
/*End TankDrive subsystem
 *
 */

