/*
 * LiftTote.h
 *
 *  Created on: Jul 23, 2015
 *      Author: FROGramming Team
 * Lift Tote Command for 2015 Recycle Rush Raptor
 *
 *
 */
#ifndef LIFTTOTE_H
#define LIFTTOTE_H

#include "../CommandBase.h"
#include "WPILib.h"

class LiftTote: public CommandBase
{
public:
	LiftTote();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
#endif
