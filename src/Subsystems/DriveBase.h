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
	Preferences *RoboPrefs;

	DriveBase();
	void InitDefaultCommand();
	void Drive(double, double, double, double);
	void Stop();
	void Reset();
	void PrecisionMode(double, double, double);
};



#endif /* SRC_SUBSYSTEMS_DRIVEBASE_H_ */
