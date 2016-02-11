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
#include "DriveBase.h"
#include "../RobotMap.h"
#include <Relay.h>
#include <DriverStation.h>

//#include "Preferences.h"

DriveBase::DriveBase() :	Subsystem("DriveBase")
{
  LeftDrive 	= new Talon(MotorLeft);
  RightDrive 	= new Talon(MotorRight);
  HDrive		= new Victor(MotorH);
  RightEnc		= new Encoder(Enc_Rt_A,Enc_Rt_B,true,Encoder::k1X);
  LeftEnc		= new Encoder(2,3, true, Encoder::k1X);
  LightValue	= new Relay(0);
//  RoboPrefs		= new Preferences;

  //SmartDashboard::PutNumber("Left Drive Value",LeftDriveFinal);
  //SmartDashboard::PutNumber("Right Drive Value",RightDriveFinal);
 // DSforDriveBase -> GetInstance();

}
void DriveBase::InitDefaultCommand()
{
	  //Default function when class is first created
		LeftEnc ->Reset();
		RightEnc ->Reset();
//		LeftEnc -> SetDistancePerPulse(DPP);
	SetDefaultCommand(new XBox_GTADrive());
}

void DriveBase::Drive(double LeftDriveDesired, double RightDriveDesired, bool lightsOn) //axes of joystick
{
	LeftDriveDesired = -1 * LeftDriveDesired;	//Corrects for reversed motor
	//LeftDriveFinal = LeftDriveDesired;
	//RightDriveFinal = RightDriveDesired;

	/*if (DSforDriveBase -> IsTest()){
		LeftDrive -> Set(SmartDashboard::GetNumber("LEFTDRIVE", LeftDriveFinal));
		RightDrive -> Set(SmartDashboard::GetNumber("RIGHTDRIVE",RightDriveFinal));
	} else {*/
		LeftDrive         -> Set(LeftDriveDesired); //passes desired state to speed controllers
		RightDrive         -> Set(RightDriveDesired);
	//}

	HDrive	->	Set(0); //GTA Drive does not use H Drive
	//if (lightsOn)
	//  LightValue -> Set(0);


	        //LiveWindow::GetInstance()->AddActuator("Dank Memes","Left Drive",LeftDrive);
	        //LiveWindow::GetInstance()->SetEnabled(true); //if uncommented, robot doesn't drive
	      //  SmartDashboard::PutData("Left Drive Value",LeftDrive);
	      //  SmartDashboard::PutData("Right Drive Value",RightDrive);
	       // SmartDashboard::PutValue("Lights",Relay::Get());
	//SmartDashboard::PutNumber("doesthiswork", plzwork);
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
