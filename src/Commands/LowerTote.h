/*
 * LowerTote.h
 *
 *  Created on: Jul 23, 2015
 *      Author: FROGramming Team
 * Lower Tote Command for 2015 Recycle Rush Raptor
 *
 *
 */
#ifndef LowerTOTE_H
#define LowerTOTE_H

#include "../CommandBase.h"
#include "WPILib.h"

class LowerTote: public CommandBase
{
public:
	LowerTote();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
#endif
