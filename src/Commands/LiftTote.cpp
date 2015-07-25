/*
 * LiftTote.cpp
 *
 *  Created on: Jul 23, 2015
 *      Author: FROGramming Team
 * Lift Tote Command for 2015 Recycle Rush Raptor
 * Command exists for one simple task, lift the Tote Lifter.
 * Initialize invokes the function, and Finished returns true always.
 *
 */
#include "LiftTote.h"
#include "RobotMap.h"

LiftTote::LiftTote()
{
  Requires(totelift);
}
	void LiftTote::Initialize()
{
	totelift	->	Lift();
}

	void LiftTote::Execute(){};

	bool LiftTote::IsFinished()
{
	return true;
}

	void LiftTote::End(){};
	void LiftTote::Interrupted(){};
