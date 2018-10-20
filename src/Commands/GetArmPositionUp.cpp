/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "GetArmPositionUp.h"

GetArmPositionUp::GetArmPositionUp() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::arm.get());
}

// Called once when the command executes
void GetArmPositionUp::Initialize() {
	int armPotUp = Arm::getInstance()->GetArmPotValue();
	int armEncoderUp = Arm::getInstance()->GetPos();
	Arm::getInstance()->SetArmPosUp(armPotUp, armEncoderUp);
}
