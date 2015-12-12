/*
 * RedMode.h
 *
 *  Created on: Dec 4, 2015
 *      Author: AFRO
 */

#ifndef SRC_COMMANDS_REDMODE_H_
#define SRC_COMMANDS_REDMODE_H_

#include "../CommandBase.h"
#include "WPILib.h"

class RedMode: public CommandBase
{
public:
	RedMode();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_REDMODE_H_ */
