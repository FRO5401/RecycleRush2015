#include <Commands/XBox_GTADrive.h>
#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
//Include includes for each and every command
//OMFG It Worked!!
class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;

	void RobotInit()
	{
		CommandBase::init();
		//autonomousCommand = new ExampleCommand();
		lw = LiveWindow::GetInstance();
		//CameraServer::GetInstance() -> SetQuality(50);
		//CameraServer::GetInstance() -> StartAutomaticCapture("cam0");
	}
	

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
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
		lw->SetEnabled(true);
	}
};

START_ROBOT_CLASS(Robot);

