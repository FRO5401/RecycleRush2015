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

DriveBase::DriveBase() :	Subsystem("DriveBase")
{
  LeftDrive 	= new Talon(MotorLeft);
  RightDrive 	= new Talon(MotorRight);
  HDrive		= new Victor(MotorH);
}
  void DriveBase::InitDefaultCommand()
  {
	  //Default function when class is first created
		SetDefaultCommand(new JoystickMove());

  }

void DriveBase::Drive(double LeftDriveDesired, double RightDriveDesired, double HDriveDesired) //axes of joystick
  {

  LeftDrive 	-> Set(LeftDriveDesired); //passes desired state to speed controllers
  RightDrive 	-> Set(RightDriveDesired);
  HDrive		-> Set(HDriveDesired);

  }

  void DriveBase::Stop()
  {

  LeftDrive		-> Set(0);
  RightDrive	-> Set(0);
  HDrive		-> Set(0);

  }
//}
/*End TankDrive subsystem
 *
 */

