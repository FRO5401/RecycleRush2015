#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/JoystickMove.h"
#include "CommandBase.h"

#include "Commands/IntegerChooser.h"
#include "Commands/Backward.h"
#include "Commands/Forward.h"
//Include includes for each and every command
//OMFG It Worked!!
class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;//Command for autonomous mode
	LiveWindow *lw;
	SendableChooser *autoMode;
//  ^^SendableChoose is class for choosing in SmartDashboard
//  autoMode is just the name, could be named something else

	void RobotInit()
	{
		CommandBase::init();
		//autonomousCommand = new ExampleCommand();
		lw = LiveWindow::GetInstance();
		//Dashboard selected mode block
		autoMode = new SendableChooser();//Initializes autoMode as SendableChooser, like motors = new Victors
		autoMode->AddDefault("Default-IntegerChooser", new IntegerChooser());//Sets the default for the autoMode
		autoMode->AddObject("Backward", new Backward());//Sets a alternative choice
		SmartDashboard::PutData("Autonomous Mode", autoMode);//What???
		//End dash select block
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
//		if (autonomousCommand != NULL)
//			autonomousCommand->Start();
//			^^Original code, merely starts autonomous because selection is a direct change in the program
		autonomousCommand = (Command *) autoMode->GetSelected(); //Dashboard selection command
			autonomousCommand->Start();
//			^^New Code, does dashboard selection
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
		//^^makes autonomous program inactive when teleop initiates
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

