#include "Arm.h"
#include "../RobotMap.h"
#include <Preferences.h>

using frc::Preferences;

static const int kSlotIndex = 0;

const char Arm::kSubsystemName[] = "Arm";
const std::string kKey = "ArmScale";
const std::string kKeyPot = "ArmPotBottom";

static const double kMaxFwdEncoderPos = 26500.0;
static const double kMaxPercentVBus = 0.3;	// Maximum percent to apply to the motor.
											// The low value is safety and speed of the arm.
// Determine max velocity by measuring units per 100ms as the arm is moving
// This is a guess. Velocity was not measured.
static const double kVelocityMaxUnitsPer100ms = 3675.0;

std::shared_ptr<Arm> Arm::self;

std::shared_ptr<Arm> Arm::getInstance() {
        if (! self) {
          self = std::shared_ptr<Arm>(new Arm);
        }
        return self;
}

static double calcFeedforward() {
	double feedForward = kMaxPercentVBus * 1023.0 / kVelocityMaxUnitsPer100ms;

	return feedForward;
}

static double calcP() {
	static const double kEigthUnitsPerRev = 4096.0 / 1.0;
	double pGain = kMaxPercentVBus * 1023.0 / kEigthUnitsPerRev;
	return pGain;
}

double degreesToTicks(int degrees) {
	return kMaxFwdEncoderPos*degrees/90;
}

Arm::Arm() : Subsystem(kSubsystemName),
		armMotor(RobotMap::kIDArmMotor),
		armPot(RobotMap::kIDArmPot),
		calibrateEncoderDown(0),
		calibratePotDown(0)
{
	Arm::SetMotionMagic();
	Arm::ResetArmPos();
}

void Arm::InitDefaultCommand() {
}

void Arm::SetArmMove(double speed) {
	armMotor.Set(ControlMode::PercentOutput, speed);
}

void Arm::SetArmPos(int position) {
	armMotor.Set(ControlMode::MotionMagic, degreesToTicks(position));
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

void Arm::SetMotionMagic() {
	armMotor.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, kTimeout_10Millis);
	armMotor.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, kTimeout_10Millis);

	armMotor.ConfigNominalOutputForward(0, kTimeout_10Millis);
	armMotor.ConfigNominalOutputReverse(0, kTimeout_10Millis);
	armMotor.ConfigPeakOutputForward(0.5, kTimeout_10Millis);
	armMotor.ConfigPeakOutputReverse(-0.5, kTimeout_10Millis);

	static const double kF = calcFeedforward();
	static const double kP = calcP();
	static const double kI = 0;
	static const double kD = 0;
	static const double kMaxVelocity = kVelocityMaxUnitsPer100ms;
	static const int kCruiseVelocity = kMaxVelocity;
	static const int kMotionAcceleration = kCruiseVelocity * 2;

	armMotor.SelectProfileSlot(kSlotIndex, kPID_PrimaryClosedLoop);
	armMotor.Config_kF(kSlotIndex, kF, kTimeout_10Millis);
	armMotor.Config_kP(kSlotIndex, kP, kTimeout_10Millis);
	armMotor.Config_kI(kSlotIndex, kI, kTimeout_10Millis);
	armMotor.Config_kD(kSlotIndex, kD, kTimeout_10Millis);
	armMotor.ConfigMotionCruiseVelocity(kCruiseVelocity, kTimeout_10Millis);
	armMotor.ConfigMotionAcceleration(kMotionAcceleration, kTimeout_10Millis);
}
