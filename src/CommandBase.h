#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "OI.h"
#include "WPILib.h"
//include includes for each subsystem
#include "Subsystems/DriveBase.h"
#include "Subsystems/ToteLift.h"
#include "Subsystems/WateryTart.h"
#include "Subsystems/OpenCVTargetAq.h"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static DriveBase *drivebase;
	static ToteLift *totelift;
	static OI *oi;
	static WateryTart 	*waterytart;
	static OpenCVTargetAq	*opencvtargetaq;

};

#endif
