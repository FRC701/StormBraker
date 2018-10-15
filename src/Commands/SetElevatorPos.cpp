/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/SetElevatorPos.h>

SetElevatorPos::SetElevatorPos(int position) : mPosition(position), counter(0) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::elevator.get());
}

// Called just before this Command runs the first time
void SetElevatorPos::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SetElevatorPos::Execute() {
	Elevator::getInstance()->setElevatorPos(mPosition);
}

// Make this return true when this Command no longer needs to run execute()
bool SetElevatorPos::IsFinished() {
	if (Elevator::getInstance()->GetPosError() < 1000
			|| Elevator::getInstance()->IsFwdLimitSwitchClosed()
			|| Elevator::getInstance()->IsRevLimitSwitchClosed()) {
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
void SetElevatorPos::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetElevatorPos::Interrupted() {

}
