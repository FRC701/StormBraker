#include "Climber.h"
#include "ClimberOff.h"
#include "../RobotMap.h"

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
	leftClimber(RobotMap::kIDLeftClimber)
{


}

void Climber::InitDefaultCommand() {
  SetDefaultCommand(new ClimberOff);
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

