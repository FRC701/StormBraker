/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/ArmMove.h>

ArmMove::ArmMove(double speed) : mSpeed(speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::arm.get());
}

// Called just before this Command runs the first time
void ArmMove::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ArmMove::Execute() {
	Arm::getInstance()->SetArmMove(mSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmMove::IsFinished() {
	if (Arm::getInstance()->IsFwdLimitSwitchClosed() == true || Arm::getInstance()->IsRevLimitSwitchClosed() == true) {
		return true;
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void ArmMove::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmMove::Interrupted() {

}
