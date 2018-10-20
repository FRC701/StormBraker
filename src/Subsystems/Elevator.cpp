#include "Elevator.h"
#include "../RobotMap.h"

static const int kSlotIndex = 0;

const char Elevator::kSubsystemName[] = "Elevator";

std::shared_ptr<Elevator> Elevator::self;

std::shared_ptr<Elevator> Elevator::getInstance() {
	if (! self) {
		self = std::shared_ptr<Elevator>(new Elevator);
	}
	return self;
}
static double calcFeedforward() {
	static const double kMaxUnitsPer100ms = 3675.0;

	double feedForward = 1023.0 / kMaxUnitsPer100ms;

	return feedForward;
}

static double calcP() {
	static const double kEigthUnitsPerRev = 4096.0 / 1.0;
	double pGain = 1 * 1023.0 / kEigthUnitsPerRev;
	return pGain;
}
Elevator::Elevator() : Subsystem(kSubsystemName),
	topElevator(RobotMap::kIDTopElevator),
	bottomElevator(RobotMap::kIDBottomElevator)
{
	SetUpTalons();
	SetUpMotionMagic();
}

void Elevator::InitDefaultCommand() {

}

void Elevator::SetElevator(double speed) {
	topElevator.Set(ControlMode::PercentOutput, speed);
}

void Elevator::setElevatorPos(int position) {
	topElevator.Set(ControlMode::MotionMagic, position);
}

void Elevator::SetUpTalons() {
	topElevator.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,
			kPID_PrimaryClosedLoop,
			kTimeout_10Millis);
	topElevator.ConfigForwardSoftLimitEnable(false, kTimeout_10Millis);
	topElevator.ConfigReverseSoftLimitEnable(false, kTimeout_10Millis);
	topElevator.ConfigForwardLimitSwitchSource(LimitSwitchSource_FeedbackConnector, LimitSwitchNormal_NormallyOpen, kTimeout_10Millis);
	topElevator.ConfigReverseLimitSwitchSource(LimitSwitchSource_FeedbackConnector, LimitSwitchNormal_NormallyOpen, kTimeout_10Millis);
	topElevator.SetSensorPhase(true);
	topElevator.SetInverted(false);
	topElevator.ConfigPeakOutputForward(0.1, kTimeout_10Millis);
	topElevator.ConfigPeakOutputReverse(-0.02, kTimeout_10Millis);

	bottomElevator.SetInverted(true);
	bottomElevator.Follow(topElevator);

}

void Elevator::SetUpMotionMagic() {
	topElevator.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, kTimeout_10Millis);
	topElevator.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, kTimeout_10Millis);

	topElevator.ConfigNominalOutputForward(0, kTimeout_10Millis);
	topElevator.ConfigNominalOutputReverse(0, kTimeout_10Millis);
	topElevator.ConfigPeakOutputForward(1, kTimeout_10Millis);
	topElevator.ConfigPeakOutputReverse(-1, kTimeout_10Millis);

	static const double kF = calcFeedforward();
	static const double kP = calcP();
	static const double kI = 0;
	static const double kD = 0;
	static const double kMaxVelocity = 3675;
	static const int kCruiseVelocity = kMaxVelocity;
	static const int kMotionAcceleration = kCruiseVelocity * 2;

	topElevator.SelectProfileSlot(kSlotIndex, kPID_PrimaryClosedLoop);
	topElevator.Config_kF(kSlotIndex, kF, kTimeout_10Millis);
	topElevator.Config_kP(kSlotIndex, kP, kTimeout_10Millis);
	topElevator.Config_kI(kSlotIndex, kI, kTimeout_10Millis);
	topElevator.Config_kD(kSlotIndex, kD, kTimeout_10Millis);
	topElevator.ConfigMotionCruiseVelocity(kCruiseVelocity, kTimeout_10Millis);
	topElevator.ConfigMotionAcceleration(kMotionAcceleration, kTimeout_10Millis);

}

bool Elevator::IsFwdLimitSwitchClosed() {
	return topElevator.GetSensorCollection().IsFwdLimitSwitchClosed();
}

bool Elevator::IsRevLimitSwitchClosed() {
	return topElevator.GetSensorCollection().IsRevLimitSwitchClosed();
}

double Elevator::GetPosError() {
	return topElevator.GetClosedLoopError(kSlotIndex);
}
