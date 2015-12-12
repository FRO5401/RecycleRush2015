/*
 * GreenMode.h
 *
 *  Created on: Dec 4, 2015
 *      Author: AFRO
 */

#ifndef SRC_COMMANDS_GREENMODE_H_
#define SRC_COMMANDS_GREENMODE_H_

#include "../CommandBase.h"
#include "WPILib.h"

class GreenMode: public CommandBase
{
public:
	GreenMode();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_GREENMODE_H_ */
