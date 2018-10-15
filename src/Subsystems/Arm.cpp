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
		  armMotor(RobotMap::kIDArmMotor)
{

}
void Arm::InitDefaultCommand() {
}



// Put methods for controlling this subsystem
// here. Call these from Commands.

