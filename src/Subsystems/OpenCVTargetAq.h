#ifndef OpenCVTargetAq_H
#define OpenCVTargetAq_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class OpenCVTargetAq: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	OpenCVTargetAq();
	void InitDefaultCommand();
};

#endif
