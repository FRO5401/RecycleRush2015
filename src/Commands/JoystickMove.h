

#ifndef JoystickMove_H
#define JoystickMove_H

#include "../CommandBase.h"
#include "WPILib.h"

class JoystickMove: public CommandBase
{
public:
	JoystickMove();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
