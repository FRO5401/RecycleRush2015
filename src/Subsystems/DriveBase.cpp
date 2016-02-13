/*
 * DriveBase.cpp
 *
 *  Created on: Jul 13, 2015
 *      Author: KJM
 * Skid steer using Xbox controller, practice for Stronghold
 *
 *
 */
#include <Commands/XBox_GTADrive.h>
#include "Commands/CheckGyro.h"
#include "DriveBase.h"
#include "../RobotMap.h"
//#include "Preferences.h"
#include <Timer.h>

Timer *TimeCount = new Timer();

DriveBase::DriveBase() :	Subsystem("DriveBase")
{
  LeftDrive 	= new Talon(MotorLeft);
  RightDrive 	= new Talon(MotorRight);
  HDrive		= new Victor(MotorH);
  RightEnc		= new Encoder(Enc_Rt_A,Enc_Rt_B,true,Encoder::k1X);
  LeftEnc		= new Encoder(2,3, true, Encoder::k1X);
  MainGyro		= new ADXRS450_Gyro();
//  RoboPrefs		= new Preferences;
  GyroScalar	= 1;
  //Timer *TimeCount = new Timer();
}
void DriveBase::InitDefaultCommand()
{
	  //Default function when class is first created
		LeftEnc ->Reset();
		RightEnc ->Reset();
//		LeftEnc -> SetDistancePerPulse(DPP);
	SetDefaultCommand(new XBox_GTADrive());
}

void DriveBase::Drive(double LeftDriveDesired, double RightDriveDesired) //axes of joystick
{
	LeftDriveDesired = -1 * LeftDriveDesired;	//Corrects for reversed motor
	LeftDrive         -> Set(LeftDriveDesired); //passes desired state to speed controllers
	        RightDrive         -> Set(RightDriveDesired);
	        HDrive	->	Set(0); //GTA Drive does not use H Drive

	//gyro and time output to log
	float gyro = (GyroScalar * MainGyro	->	GetAngle());
	double Time = TimeCount -> Get();
	std::cout << gyro << ", " << Time << "\n";
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

float DriveBase::ReportGyro()
{
	float Angle = (GyroScalar * MainGyro	->	GetAngle());
	//SmartDashboard::PutNumber("Gyro Angle", Angle); //do this elsewhere
	return Angle;
}
