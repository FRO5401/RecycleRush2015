#ifndef CheckGyro_H
#define CheckGyro_H

#include "../CommandBase.h"
#include "WPILib.h"

class CheckGyro: public CommandBase
{
public:
	CheckGyro();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
