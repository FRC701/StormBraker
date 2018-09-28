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
Intake::Intake() : Subsystem(kSubsystemName),
	intakeMotor(RobotMap::kIDIntakeMotor)
{
}

void Intake::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Intake::SetIntake(double speed){
	intakeMotor.Set(speed);
}

bool Intake::IsIntakeOn() {

	return false;
}
