/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "PosToggle.h"
#include "Robot.h"

PosToggle::PosToggle() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::arm.get());
}

// Called just before this Command runs the first time
void PosToggle::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void PosToggle::Execute() {
	auto arm = Arm::getInstance();
	auto position = arm->GetLastPos();

	switch(position)
	{
	case -90:
		position = -30;
		break;
	case -30:
		position = -90;
		break;
	case 90:
		position = 30;
		break;
	case 30:
		position = 90;
		break;
	default:
		position = 0;
		break;
	};

	arm->SetArmPos(position);
}

// Make this return true when this Command no longer needs to run execute()
bool PosToggle::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void PosToggle::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PosToggle::Interrupted() {

}
