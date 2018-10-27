#include "ctre/Phoenix.h"


#include "Chassis.h"
#include "../RobotMap.h"
#include "Commands/TankDrive.h"

const char Chassis::kSubsystemName[] = "Chassis";
std::shared_ptr<Chassis> Chassis::self;

std::shared_ptr<Chassis> Chassis::getInstance() {
  if (! self) {
    self = std::shared_ptr<Chassis>(new Chassis);
  }
  return self;
}

static const int kSlot0 = 0;

Chassis::Chassis() : Subsystem(kSubsystemName),
    left1Wheel(RobotMap::kIDLeft1Wheel),
    left2Wheel(RobotMap::kIDLeft2Wheel),
    right1Wheel(RobotMap::kIDRight1Wheel),
    right2Wheel(RobotMap::kIDRight2Wheel)
	{
	right1Wheel.SetInverted(true);
	right2Wheel.SetInverted(true);
	left2Wheel.Follow(left1Wheel);
	right2Wheel.Follow(right1Wheel);
	}

void Chassis::InitDefaultCommand() {
	SetDefaultCommand(new TankDrive);
}

void Chassis::SetTankDrive(double left, double right) {
  left1Wheel.Set(left);
  right1Wheel.Set(right);
}

bool Chassis::IsCubeIn() {
	return ! left1Wheel.GetSensorCollection().IsRevLimitSwitchClosed();
}

double Chassis::GetLeftEncoderValue() {
	return left1Wheel.GetSelectedSensorPosition(kSlot0);
}

double Chassis::GetRightEncoderValue() {
	return right1Wheel.GetSelectedSensorPosition(kSlot0);
}


