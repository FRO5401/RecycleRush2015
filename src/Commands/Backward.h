#ifndef Backward_H
#define Backward_H

#include "../CommandBase.h"
#include "WPILib.h"

class Backward: public CommandBase
{
public:
	Backward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
