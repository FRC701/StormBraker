/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "DirectionToggle.h"
#include "Robot.h"

DirectionToggle::DirectionToggle() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::arm.get());
}

// Called just before this Command runs the first time
void DirectionToggle::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DirectionToggle::Execute() {
	auto arm = Arm::getInstance();
	arm->SetArmPos(arm->GetLastPos() * -1);

}

// Make this return true when this Command no longer needs to run execute()
bool DirectionToggle::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DirectionToggle::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DirectionToggle::Interrupted() {

}
