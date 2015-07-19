#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:

public:
	Joystick *Logitech3DPro;
//	Joystick *XBoxController;
//	Joystick *PSController;

	OI();
    double ReadJoystickX();
    double ReadJoystickY();
    double ReadJoystickZ();
};

#endif
