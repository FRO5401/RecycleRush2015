/*
 * Catapult targeting for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 */

#include <Commands/LockTarget.h>
#include "RobotMap.h"
bool Lock;

LockTarget::LockTarget()
{
  Requires(waterytart);
}
	void LockTarget::Initialize() {
	};

	void LockTarget::Execute(){
/*
 * This will do image processing, to locate the target and properly move the robot to the launch site
 * Then it will set a bool flag Lock to indicate target lock
 * When finished, it will kick off the launch command
 */
		waterytart	->	Search();

	};

	bool LockTarget::IsFinished()
{
//	return Lock;
		return false;
}

	void LockTarget::End(){
//		new Launch();
	}

	void LockTarget::Interrupted(){};
