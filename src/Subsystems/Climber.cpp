#include "Climber.h"
#include "SetClimber.h"
#include "Commands/ClimberOff.h"
#include "../RobotMap.h"
#include "DoubleSolenoid.h"

static frc::DoubleSolenoid::Value kClimberEngage = frc::DoubleSolenoid::kForward;
static frc::DoubleSolenoid::Value kClimberDisengage = frc::DoubleSolenoid::kReverse;

const char Climber::kSubsystemName[] = "Climber";

std::shared_ptr<Climber> Climber::self;
std::shared_ptr<Climber> Climber::getInstance() {
  if (! self) {
    self = std::shared_ptr<Climber>(new Climber);
  }
  return self;
}

Climber::Climber() : Subsystem(kSubsystemName),
    rightClimber(RobotMap::kIDRightClimber),
	leftClimber(RobotMap::kIDLeftClimber),
	climberShifter(RobotMap::kIDClimberForward, RobotMap::kIDClimberReverse)
{
	climberShifter.Set(DoubleSolenoid::kForward);

}

void Climber::InitDefaultCommand() {
	SetDefaultCommand(new SetClimber(0.0));
}

void Climber::ClimberEngage() {
	climberShifter.Set(kClimberEngage);
}

void Climber::ClimberDisengage() {
	climberShifter.Set(kClimberDisengage);
}

void Climber::Climb(double speed){
  rightClimber.Set(speed);
  leftClimber.Set(speed);
}
