/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "GetArmPos.h"
#include "Robot.h"

GetArmPos::GetArmPos() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::arm.get());
}

// Called once when the command executes
void GetArmPos::Initialize() {
	double speed;
	if (Arm::getInstance()->IsFwdLimitSwitchClosed()) {
		speed = -0.3;
	}
	else {
		speed = 0.3;
	}
	Arm::getInstance()->SetArmMove(speed);
}
