#include "Intake.h"
#include "RobotMap.h"
#include "Commands/SetIntake.h"

const char Intake::kSubsystemName[] = "Intake";

std::shared_ptr<Intake> Intake::self;

using CommandSetIntake = SetIntake;	// Avoid collision between class name and method name

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
	this->SetDefaultCommand(new CommandSetIntake(0.0));
}

void Intake::SetIntake(double speed){
	intakeMotor.Set(speed);
}

bool Intake::IsCubeIn() {

	return intakeMotor.GetSensorCollection().IsFwdLimitSwitchClosed();
}
