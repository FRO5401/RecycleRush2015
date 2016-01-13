/*
 * DriveBase.cpp
 *
 *  Created on: Jul 13, 2015
 *      Author: KJM
 * Skid steer using Xbox controller, practice for Stronghold
 *
 *
 */
#include <Commands/XboxMoveSkid.h>
#include "DriveBase.h"
#include "../RobotMap.h"
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
//		LeftEnc -> SetDistancePerPulse(DPP);
	SetDefaultCommand(new XboxMoveSkid());
}

void DriveBase::Drive(double LeftDriveDesired, double RightDriveDesired) //axes of joystick
{
	LeftDrive         -> Set(LeftDriveDesired); //passes desired state to speed controllers
	        RightDrive         -> Set(RightDriveDesired);

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
/*
void DriveBase::PrecisionMode(double LeftDriveDesired, double RightDriveDesired, double HDriveDesired)
{
	LeftDrive->Set(LeftDriveDesired * JoyPrecise);
	RightDrive->Set(LeftDriveDesired * JoyPrecise);
//	HDrive->Set(HDriveDesired*JoyPrecise);
}
*/
//}
