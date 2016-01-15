/*
 * MOH-GTADrive.h
 *
 *  Created on: Jan 13, 2016
 *      Author: AFRO
 */

#ifndef SRC_COMMANDS_MOH_GTADRIVE_H_
#define SRC_COMMANDS_MOH_GTADRIVE_H_

#ifndef MOH_GTADrive_H
#define MOH_GTADrive_H

#include "../CommandBase.h"
#include "WPILib.h"

class MOH_GTADrive: public CommandBase
{
public:
	MOH_GTADrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif



#endif /* SRC_COMMANDS_MOH_GTADRIVE_H_ */
