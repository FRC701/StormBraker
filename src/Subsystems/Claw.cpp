#include "Claw.h"
#include "../RobotMap.h"

static frc::DoubleSolenoid::Value kClawEngage = frc::DoubleSolenoid::kForward;
static frc::DoubleSolenoid::Value kClawDisengage = frc::DoubleSolenoid::kReverse;


const char Claw::kSubsystemName[] = "Claw";

std::shared_ptr<Claw> Claw::self;

std::shared_ptr<Claw> Claw::getInstance() {
        if (! self) {
          self = std::shared_ptr<Claw>(new Claw);
        }
        return self;
}

Claw::Claw() : Subsystem(kSubsystemName),
	clawSolenoid(RobotMap::kIDClawForward, RobotMap::kIDClawReverse)
{
	clawSolenoid.Set(DoubleSolenoid::kForward);

}

void Claw::InitDefaultCommand() {

}

void Claw::ClawEngage() {
	clawSolenoid.Set(kClawEngage);
}

void Claw::ClawDisengage() {
	clawSolenoid.Set(kClawDisengage);
}
