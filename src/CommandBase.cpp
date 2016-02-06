#include "CommandBase.h"
#include "Commands/Scheduler.h"

//add includes for each subsystem of the robot
#include "Subsystems/DriveBase.h"
#include "Subsystems/ToteLift.h"
#include "Subsystems/OpenCVTargetAq.h"

// Initialize a single static instance of all of your subsystems to NULL
DriveBase* CommandBase::drivebase = NULL;
ToteLift* CommandBase::totelift = NULL;
OI* CommandBase::oi = NULL;
WateryTart*	CommandBase::waterytart		= NULL;
OpenCVTargetAq*	CommandBase::opencvtargetaq	=	NULL;


CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	drivebase = new DriveBase();
	totelift = new ToteLift();
	waterytart	= new WateryTart();
	opencvtargetaq = new OpenCVTargetAq();

	oi = new OI();
}
