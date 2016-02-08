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
	Image *frame;

	void RobotInit()
	{
		CommandBase::init();
		//autonomousCommand = new ExampleCommand();
		lw = LiveWindow::GetInstance();
		CameraServer::GetInstance() -> SetQuality(50);
		CameraServer::GetInstance() -> StartAutomaticCapture("cam0");
		//frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
		//CameraServer::GetInstance()->SetImage(frame);
		std::cout << "RobotInit" << std::endl;
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
		std::cout << "TeleopPeriodic" << std::endl;
		if (SmartDashboard::GetBoolean("JASON", true))
				std::cout << "Yes." << std::endl;
			else
				std::cout << "No." << std::endl;
		//frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
		//CameraServer::GetInstance()->SetImage(frame);
		double dumb = SmartDashboard::GetNumber("Are you dumb?",0.0);
		//SmartDashboard::PutNumber("Recieved - Are you dumb?", dumb);
		std::cout << dumb << std::endl;
	}

	void TestPeriodic()
	{
		lw->Run();
		lw->SetEnabled(true);
	}
};

START_ROBOT_CLASS(Robot);

