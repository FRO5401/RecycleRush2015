#ifndef Forward_H
#define Forward_H

#include "../CommandBase.h"
#include "WPILib.h"

class Forward: public CommandBase
{
public:
	//Nothing is changed
	Forward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
