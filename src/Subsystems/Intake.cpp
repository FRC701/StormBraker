#include "Intake.h"

#include "../RobotMap.h"

const char Intake::kSubsystemName[] = "Intake";

std::shared_ptr<Intake> Intake::self;

std::shared_ptr<Intake> Intake::getInstance() {
	if (! self) {
		self = std::shared_ptr<Intake>(new Intake);
	}
	return self;
}
Intake::Intake() : frc::Subsystem("Intake") {
	intakeMotor(RobotMap::kIDIntakeMotor)
}

void Intake::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ::SetIntake(0.0));
}

void Intake::SetIntake(double speed){
	intakeMotor(speed);
}

bool Intake::IsIntakeOn() {
  return intakeMotorTop.GetMotorOutputVoltage();
}
