/*
 * LowerTote.cpp
 *
 *  Created on: Jul 23, 2015
 *      Author: FROGramming Team
 * Lower Tote Command for 2015 Recycle Rush Raptor
 * Command exists for one simple task, Lower the Tote Lifter.
 * Initialize invokes the function, and Finished returns true always.
 *
 */
#include "LowerTote.h"
#include "RobotMap.h"


LowerTote::LowerTote()
{
  Requires(totelift);
}
	void LowerTote::Initialize()
{
		totelift	->	Lower();
}

	void LowerTote::Execute(){};

	bool LowerTote::IsFinished()
{
	return true;
}

	void LowerTote::End(){};
	void LowerTote::Interrupted(){};
