/*
 * MOH-GTADrive.h
 *
 *  Created on: Jan 13, 2016
 *      Author: AFRO
 */

//#ifndef SRC_COMMANDS_XBOX_GTADRIVE_H_
//#define SRC_COMMANDS_XBOX_GTADRIVE_H_

#ifndef XBox_GTADrive_H
#define XBox_GTADrive_H

#include "../CommandBase.h"
#include "WPILib.h"

class XBox_GTADrive: public CommandBase
{
public:
	XBox_GTADrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif



//#endif /* SRC_COMMANDS_XBOX_GTADRIVE_H_ */
