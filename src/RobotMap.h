#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

/********************************
 *Input Joysticks Section
 *Unused controllers are commented out, no channel assigned, but left for code reuse
********************************/

const int Logitech3D_Channel		=	0;	//Commented out, no channel assigned
//const int XBoxController_Channel	=	;	//Commented out, no channel assigned
//const int PSController_Channel		=	1;//Main controller for Froshbot
/********************************
 *End Joysticks
********************************/

/********************************
 *Speed Controller Section
********************************/
const int MotorLeft 	= 1;
const int MotorRight 	= 0;
const int MotorH		= 2;
/********************************
 *End Speed Controllers
********************************/

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

#endif
