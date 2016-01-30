/*
 * ToteLift.cpp
 *
 *  Created on: Jul 23, 2015
 *      Author: FROGramming Team
 * Tote Lift for 2015 Recycle Rush Raptor
 *
 *
 */

#include "ToteLift.h"
#include "../RobotMap.h"

ToteLift::ToteLift() : Subsystem("ToteLift")
{
	ToteLiftLeft 	=	new DoubleSolenoid(SolenoidCAN_ID, ToteLiftChannel_LeftFwd, ToteLiftChannel_LeftRev);
	ToteLiftRight 	= 	new DoubleSolenoid(SolenoidCAN_ID, ToteLiftChannel_RightFwd, ToteLiftChannel_RightRev);
	MainCompressor	=	new Compressor();
	MainCompressor	->Stop();
}
void ToteLift::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	//No default command for ToteLift
}
void ToteLift::Lift()
{
	ToteLiftLeft	->	Set(DoubleSolenoid::Value::kForward);
	ToteLiftRight	->	Set(DoubleSolenoid::Value::kForward);

}
void ToteLift::Lower()
{
	ToteLiftLeft	->	Set(DoubleSolenoid::Value::kReverse);
	ToteLiftRight	->	Set(DoubleSolenoid::Value::kReverse);
}
