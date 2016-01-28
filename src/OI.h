#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
//	Joystick *Logitech3DPro;
	Joystick *XBoxController;  //Trying these private IAW GearsBot example
//	Joystick *PSController;
//	Joystick *MOHController;
// XBoxButton Declarations
	Button *XBoxA;
	Button *XBoxB;
	Button *XBoxX;
	Button *XBoxY;
	Button *XBoxLBump;
	Button *XBoxRBump;
//	Button *XBoxBack;
//	Button *XBoxStart;
//	Button *XBoxLStick;
//	Button *XBoxRStick;

// XBoxButton Declarations
//	Button *MOHA;
//	Button *MOHB;
//	Button *MOHX;
//	Button *MOHY;
//	Button *MOHLBump;
//	Button *MOHRBump;
//	Button *MOHLTrig;
//	Button *MOHRTrig;
//	Button *MOHLStick;
//	Button *MOHRStick;


public:
	OI();
	double ReadJoystickX();
	double ReadJoystickY();
//	double ReadJoystickZ();
	double GetLeftTrigger();
	double GetRightTrigger();
	bool GetPrecision();
	bool GetBrake();

};

#endif
