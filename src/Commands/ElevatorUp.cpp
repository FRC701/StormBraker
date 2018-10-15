/*
 * ElevatorOn.cpp
 *
 *  Created on: Sep 28, 2018
 *      Author: VandenRobotics
 */

#include <Commands/ElevatorUp.h>

ElevatorUp::ElevatorUp(double speed) : mSpeed(speed) {

	Requires(Robot::elevator.get());

}

void ElevatorUp::Initialize() {

}

void ElevatorUp::Execute() {
	Elevator::getInstance()->SetElevator(mSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorUp::IsFinished() {
    return Elevator::getInstance()->IsFwdLimitSwitchClosed();
}

// Called once after isFinished returns true
void ElevatorUp::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorUp::Interrupted() {

}


