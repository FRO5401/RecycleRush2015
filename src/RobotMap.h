#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 * TABLE OF CONTENTS
 * 1.0 Joysticks
 * 2.0 Speed Controllers
 * 3.0 Pneumatics
 */

/************************************************************************************
 *1.0 Input Joysticks Section
 *Unused controllers are commented out, no channel assigned, but left for code reuse
********************************/

const int Logitech3D_Channel		=	0;	//Commented out, no channel assigned
const int XBoxController_Channel	=	1;	//Commented out, no channel assigned
//const int PSController_Channel		=	1;//Main controller for Froshbot

const double Drive_Sensitivity_Default	=	1;
const double Drive_Sensitivity_Precise	=	0.2;

const int LBumper_ID	=	6;
const int RBumper_ID	=	7;
/************************************************************************************
 *End Joysticks
************************************************************************************/

/************************************************************************************
 *2.0 Speed Controller Section
************************************************************************************/
const int MotorLeft 	= 1;
const int MotorRight 	= 0;
const int MotorH		= 2;
/************************************************************************************
 *End Speed Controllers
************************************************************************************/

/************************************************************************************
 *3.0 Pneumatics Section
************************************************************************************/
const int SolenoidCAN_ID				= 0;
const int ToteLiftChannel_LeftFwd		= 0;
const int ToteLiftChannel_LeftRev		= 1;
const int ToteLiftChannel_RightFwd		= 2;
const int ToteLiftChannel_RightRev		= 3;

/************************************************************************************
 *End Pneumatics
************************************************************************************/


/************************************************************************************
 *4.0 Sensor Section
************************************************************************************/
const int Enc_Rt_A				= 0;
const int Enc_Rt_B				= 1;
const int Enc_Lt_A				= 2;
const int Enc_Lt_B				= 3;

/************************************************************************************
 *End Sensors
************************************************************************************/


// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;



#endif
