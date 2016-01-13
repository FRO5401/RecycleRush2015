#ifndef XboxMoveSkid_H
#define XboxMoveSkid_H

#include "../CommandBase.h"
#include "WPILib.h"

class XboxMoveSkid: public CommandBase
{
public:
	XboxMoveSkid();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
