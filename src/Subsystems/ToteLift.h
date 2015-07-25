/*
 * ToteLift.h
 *
 *  Created on: Jul 13, 2015
 *      Author: FROgramming Team
 */

#ifndef SRC_SUBSYSTEMS_TOTELIFT_H_
#define SRC_SUBSYSTEMS_TOTELIFT_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"
class ToteLift: public Subsystem
{
private:
//First time using these as private.  First thing to check troubleshooting.

public:
	DoubleSolenoid* ToteLiftLeft;
	DoubleSolenoid* ToteLiftRight;
	Compressor* MainCompressor;

	ToteLift();
	void InitDefaultCommand();
	void Lift();
	void Lower();
};


#endif /* SRC_SUBSYSTEMS_TOTELIFT_H_ */
