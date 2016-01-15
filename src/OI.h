#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *Logitech3DPro;
	Joystick *XBoxController;  //Trying these private IAW GearsBot example
//	Joystick *PSController;
// XBoxButton Declarations
	Button *XBoxA;
	Button *XBoxB;
	Button *XBoxX;
	Button *XBoxY;
//	Button *XBoxLBump;
//	Button *XBoxRBump;
//	Button *XBoxBack;
//	Button *XBoxStart;
//	Button *XBoxLStick;
//	Button *XBoxRStick;


public:
	OI();
	double ReadJoystickX();
	double ReadJoystickY();
	double ReadJoystickZ();
	double GetTrigger();
	bool GetPrecision();
	bool GetBrake();
};

#endif
