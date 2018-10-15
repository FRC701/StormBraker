/*
 * Elevator.h
 *
 *  Created on: Sep 28, 2018
 *      Author: VandenRobotics
 */

#ifndef SRC_COMMANDS_ELEVATORUP_H_
#define SRC_COMMANDS_ELEVATORUP_H_

#include "Commands/Subsystem.h"
#include "../Robot.h"



class ElevatorUp: public frc::Command {
public:

	ElevatorUp(double speed);

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	double mSpeed;


};



#endif /* SRC_COMMANDS_ELEVATORUP_H_ */
