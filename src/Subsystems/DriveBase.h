/*
 * DriveBase.h
 *
 *  Created on: Jul 13, 2015
 *      Author: Developer
 */

#ifndef SRC_SUBSYSTEMS_DRIVEBASE_H_
#define SRC_SUBSYSTEMS_DRIVEBASE_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveBase: public Subsystem
{
//private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Talon *LeftDrive;
	Talon *RightDrive;
	Victor *HDrive;
	Encoder *RightEnc;
	Encoder *LeftEnc;

	DriveBase();
	void InitDefaultCommand();
	void Drive(double, double, bool, bool);
//	void PrecisionMode(double, double, double);
	void Reset();
	void Stop();
};



#endif /* SRC_SUBSYSTEMS_DRIVEBASE_H_ */
