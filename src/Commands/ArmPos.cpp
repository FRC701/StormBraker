/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ArmPos.h"

ArmPos::ArmPos(int position) : mPosition(position), counter(0) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::arm.get());
}

// Called just before this Command runs the first time
void ArmPos::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ArmPos::Execute() {
	Arm::getInstance()->SetArmPos(mPosition);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmPos::IsFinished() {
	if (abs(Arm::getInstance()->GetPosError()) < 1000
			|| Arm::getInstance()->IsFwdLimitSwitchClosed()
			|| Arm::getInstance()->IsRevLimitSwitchClosed()) {
		if (counter > 29) {
			return true;
		}
		else {
			++counter;
			return false;
		}
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void ArmPos::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmPos::Interrupted() {

}
