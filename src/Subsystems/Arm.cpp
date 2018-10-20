#include "Arm.h"
#include "../RobotMap.h"
#include <Preferences.h>

using frc::Preferences;

const char Arm::kSubsystemName[] = "Arm";
const std::string kKey = "ArmScale";
const std::string kKeyPot = "ArmPotBottom";

std::shared_ptr<Arm> Arm::self;

std::shared_ptr<Arm> Arm::getInstance() {
        if (! self) {
          self = std::shared_ptr<Arm>(new Arm);
        }
        return self;
}
Arm::Arm() : Subsystem(kSubsystemName),
		armMotor(RobotMap::kIDArmMotor),
		armPot(RobotMap::kIDArmPot),
		calibrateEncoderDown(0),
		calibratePotDown(0)
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

double Arm::GetPos() {
	 return armMotor.GetSelectedSensorPosition(kPID_PrimaryClosedLoop);
 }

double Arm::GetPosError() {
	return armMotor.GetClosedLoopError(0);
}

void Arm::ResetArmPos() {
	armMotor.SetSelectedSensorPosition(0, kPID_PrimaryClosedLoop, kTimeout_10Millis);
}

void Arm::SetArmPosDown(double potentiometer, double encoder) {
	calibrateEncoderDown = encoder;
	calibratePotDown = potentiometer;
}

void Arm::SetArmPosUp(double potentiometer, double encoder) {
	double scaleFactor = (calibrateEncoderDown - encoder) / (calibratePotDown - potentiometer);
	Preferences::GetInstance()->PutDouble(kKey, scaleFactor);
	Preferences::GetInstance()->PutDouble(kKeyPot, calibratePotDown);
}

double Arm::CalculateEncoderPos() {
	return Preferences::GetInstance()->GetDouble(kKey,0) * (Arm::GetArmPotValue() - Preferences::GetInstance()->GetDouble(kKeyPot,0));
}
