#include <Commands/XBox_GTADrive.h>
#include "OI.h"
#include "RobotMap.h"
//Include h files for all the commands requiring the joysticks
#include "Commands/LiftTote.h" 
#include "Commands/LowerTote.h" 
#include "Commands/LockTarget.h"

OI::OI()
{
/********************************
 *Joystick declaration section
 *Joysticks are named and declared based on a USB channel found in RobotMap.h
 *Unused joysticks are commented out, no channel assigned, but left for code reuse
********************************/	
//	Logitech3DPro 	= new Joystick(Logitech3D_Channel); //Testing Command based architecture with H-drive from 2015
	XBoxController 	= new Joystick(XBoxController_Channel); //Command based arch with H-Drive from 2015
	PSController 	= new Joystick(PSController_Channel); //Froshbot Controller
//	MOHController	= new Joystick(MOHController_Channel);

/********************************
 *Button Definition Section
 *Button Defs have not been created for unused controllers
********************************/
/*  PS Controller Not Used
//PS Controller Buttons   */
	One			= new JoystickButton(PSController, 1);
//  JoystickButton*	One		=	new JoystickButton(PSController, 1);
/*					Two		=	new JoystickButton(PSController, 2),
					Three	=	new JoystickButton(PSController, 3),
					Four	=	new JoystickButton(PSController, 4),
					LTrig1	=	new JoystickButton(PSController, 5),
					RTrig1	=	new JoystickButton(PSController, 6),
					LTrig2	=	new JoystickButton(PSController, 7),
					RTrig2	=	new JoystickButton(PSController, 8),
					Nine	=	new JoystickButton(PSController, 9),
					Ten		=	new JoystickButton(PSController, 10);*/
//End PS Controller Buttons

//Logitech 3D Pro Section

//End Logitech 3D Pro Section

//XBox Controller Section
//These mappings are probably right, but not tested
//Remove this note once mapped accurately KJM
//Full controller mapped, unused buttons are commented both here and OI.h
	XBoxA			= new JoystickButton(XBoxController, 1);
	XBoxB			= new JoystickButton(XBoxController, 2);
	XBoxX			= new JoystickButton(XBoxController, 3);
	XBoxY			= new JoystickButton(XBoxController, 4);
	XBoxLBump		= new JoystickButton(XBoxController, 5);
	XBoxRBump		= new JoystickButton(XBoxController, 6);
//	XBoxBack		= new JoystickButton(XBoxController, 7);
//	XBoxStart		= new JoystickButton(XBoxController, 8);
//	XBoxLStick		= new JoystickButton(XBoxController, 9);
//	XBoxRStick		= new JoystickButton(XBoxController, 10);

//End XBox Controller Section

//MOH (Medal of Honor) Controller Section
//These mappings are probably right, but not tested
//Remove this note once mapped accurately KJM
//Full controller mapped, unused buttons are commented both here and OI.h
//	MOHA			= new JoystickButton(MOHController, 1);
//	MOHB			= new JoystickButton(MOHController, 2);
//	MOHX			= new JoystickButton(MOHController, 3);
//	MOHY			= new JoystickButton(MOHController, 4);
//	MOHLBump		= new JoystickButton(MOHController, 5);
//	MOHRBump		= new JoystickButton(MOHController, 6);
//	MOHLTrig			= new JoystickButton(MOHController, 7);
//	MOHRTrig		= new JoystickButton(MOHController, 8);
//	MOHLStick		= new JoystickButton(MOHController, 9);
//	MOHRStick		= new JoystickButton(MOHController, 10);

	//End XBox Controller Section

/********************************
 *Button-Command Association Section
 *Defs have not been created for unused controllers
********************************/
//Froshbot Button Commands

//Code to be determined
//See https://wpilib.screenstepslive.com/s/4485/m/13810/l/241904-running-commands-on-joystick-input

//End PS Controller Buttons

/********************************
 *
 *XBox Controller Button reading section
 *
********************************/

//	XBoxY		-> WhenPressed(new LiftTote());
	One		-> WhenPressed(new LockTarget());
	XBoxB		-> WhenPressed(new LowerTote());
	//XBoxRBump   -> WhenPressed();

/********************************
 *
 *End ExBox Buttons
 *
********************************/

}

/********************************
 *Logitech Joystick reading section
 *Button defs have not been created
********************************/
/*
double OI::ReadJoystickX()
{
	double Slew =	Logitech3DPro	-> GetRawAxis(0);
	return Slew;
}

double OI::ReadJoystickY()
{
	double Throttle =	Logitech3DPro	-> GetRawAxis(1);
	return Throttle;
}

double OI::ReadJoystickZ()
{
	double Twist =	Logitech3DPro	-> GetRawAxis(2);
	return Twist;
}
*/

/********************************
 *Xbox Joystick reading section
 *Button defs have not been created
********************************/

double OI::ReadJoystickX()
{
	double Slew =	XBoxController	-> GetRawAxis(0);
	return Slew;
}

double OI::ReadJoystickY()
{
	double Throttle =	XBoxController	-> GetRawAxis(1);
	return Throttle;
}
/*
double OI::ReadJoystickZ()
{
	double Twist =	XBoxController	-> GetRawAxis(2);
	return Twist;
}
*/
double OI::GetLeftTrigger()
{
	double Throttle = XBoxController	->	GetRawAxis(2);
	return Throttle;
}

double OI::GetRightTrigger()
{
	double Throttle = XBoxController	->	GetRawAxis(3);
	return Throttle;
}

bool OI::GetPrecision()
{
	bool ButtonReader = XBoxController	->	GetRawButton(RBumper_ID);
	return ButtonReader;
}

bool OI::GetBrake()
{
	bool ButtonReader = XBoxController	->	GetRawButton(LBumper_ID);
	return ButtonReader;
}

