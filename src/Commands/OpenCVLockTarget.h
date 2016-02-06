#ifndef OpenCVLockTarget_H
#define OpenCVLockTarget_H

#include "../CommandBase.h"
#include "WPILib.h"
//#include "opencv2/opencv.hpp"


class OpenCVLockTarget: public CommandBase
{
public:
	OpenCVLockTarget();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
