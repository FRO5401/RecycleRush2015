#include <Commands/JoystickMoveSkid.h>
#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Commands/GreenMode.h"
#include "Commands/RedMode.h"

//Include includes for each and every command
//OMFG It Worked!!
class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	SendableChooser *autoMode;

	void RobotInit()
	{
		CommandBase::init();
		lw = LiveWindow::GetInstance();
		autoMode = new SendableChooser();
		autoMode->AddDefault("Default-Green", new GreenMode());
		autoMode->AddObject("Red", new RedMode());
		SmartDashboard::PutData("Autonomous Mode", autoMode);
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		autonomousCommand = (Command *) autoMode->GetSelected(); //Dashboard selection command
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();

	}

	void TeleopPeriodic()
	{

		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

