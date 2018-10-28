#ifndef ARM_H
#define ARM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "AnalogInput.h"


class Arm: public frc::Subsystem {

private:


	static const char kSubsystemName[];
	static std::shared_ptr<Arm> self;

	WPI_TalonSRX armMotor;
	frc::AnalogInput armPot;

	double calibrateEncoderDown;
	double calibratePotDown;
	int mLastPos;

public:
	static std::shared_ptr<Arm> getInstance();

	Arm();
	void InitDefaultCommand() override;

	void SetArmMove(double speed);
	void SetArmPos(int position);

	bool IsFwdLimitSwitchClosed();
	bool IsRevLimitSwitchClosed();

	double GetArmPotValue();

	double GetPos();
	int GetLastPos() {
		return mLastPos;
	}
	double GetPosError();

	void ResetArmPos();
	void SetArmPosDown(double potentiometer, double encoder);
	void SetArmPosUp(double potentiometer, double encoder);
	double CalculateEncoderPos();

	void SetMotionMagic();

};

#endif
