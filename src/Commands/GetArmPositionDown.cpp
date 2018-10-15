/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "GetArmPositionDown.h"

GetArmPositionDown::GetArmPositionDown() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::arm.get());
}

// Called once when the command executes
void GetArmPositionDown::Initialize() {
	double armPotDown = Arm::getInstance()->GetArmPotValue();
	double armEncoderDown = Arm::getInstance()->GetPos();
	Arm::getInstance()->SetArmPosDown(armPotDown, armEncoderDown);
}
