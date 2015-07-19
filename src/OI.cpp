#include "OI.h"
#include "RobotMap.h"
#include "Commands/JoystickMove.h" //071615 Didn't include this, despite the comment below
//Include h files for all the commands requiring the joysticks

OI::OI()
{
/********************************
 *Joystick declaration section
 *Joysticks are named and declared based on a USB channel found in RobotMap.h
 *Unused joysticks are commented out, no channel assigned, but left for code reuse
********************************/	
	Logitech3DPro 	= new Joystick(Logitech3D_Channel); //Testing Command based architecture with H-drive from 2015
//	XBoxController 	= new Joystick(XBoxController_Channel); //Commented Out for Froshbot - Using PS Controller
//	PSController 	= new Joystick(PSController_Channel); //Froshbot Controller

/********************************
 *Button Definition Section
 *Button Defs have not been created for unused controllers
********************************/
/*
//PS Controller Buttons  
//Tentatively created but completely inaccurate, need to map these buttons accurately later.  
//Remove this ^ note when this is mapped. - KJM
  JoystickButton*	Up		=	new JoystickButton(PSController, 1),
				Down		=	new JoystickButton(PSController, 2),
				Left		=	new JoystickButton(PSController, 3),
				Right		=	new JoystickButton(PSController, 4),
				One		=	new JoystickButton(PSController, 5),
				Two		=	new JoystickButton(PSController, 6),
				Three		=	new JoystickButton(PSController, 7),
				Four		=	new JoystickButton(PSController, 8),
				LTrig1	=	new JoystickButton(PSController, 9),
				RTrig1	=	new JoystickButton(PSController, 10),
				LTrig2	=	new JoystickButton(PSController, 11),
				RTrig2	=	new JoystickButton(PSController, 12),
				Nine		=	new JoystickButton(PSController, 13),
				Ten		=	new JoystickButton(PSController, 14);
//End PS Controller Buttons
*/
//Logitech 3D Pro Section
//End Logitech 3D Pro Section

/********************************
 *Button-Command Association Section
 *Defs have not been created for unused controllers
********************************/
//Froshbot Button Commands

//Code to be determined
//See https://wpilib.screenstepslive.com/s/4485/m/13810/l/241904-running-commands-on-joystick-input

//End PS Controller Buttons

}

/********************************
 *Logitech Joystick reading section
 *Button defs have not been created
********************************/
//071615, just realized these were all pulling 0-axis.  This may cure everything.
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
