#include "Arm.h"
#include "../RobotMap.h"

const char Arm::kSubsystemName[] = "Arm";

std::shared_ptr<Arm> Arm::self;

std::shared_ptr<Arm> Arm::getInstance() {
        if (! self) {
          self = std::shared_ptr<Arm>(new Arm);
        }
        return self;
}
Arm::Arm() : Subsystem(kSubsystemName),
		armMotor(RobotMap::kIDArmMotor),
		armPot(RobotMap::kIDArmPot)
{

}
void Arm::InitDefaultCommand() {
}

void Arm::SetArmMove(double speed) {
	armMotor.Set(ControlMode::PercentOutput, speed);
}

void Arm::SetArmPos(int position) {
	armMotor.Set(ControlMode::Position, position);
}

bool Arm::IsFwdLimitSwitchClosed() {
	return armMotor.GetSensorCollection().IsFwdLimitSwitchClosed();
}

bool Arm::IsRevLimitSwitchClosed() {
	return armMotor.GetSensorCollection().IsRevLimitSwitchClosed();
}

double Arm::GetArmPotValue() {
	return armPot.GetValue();
}
