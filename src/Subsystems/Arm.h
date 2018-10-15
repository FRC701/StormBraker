#ifndef ARM_H
#define ARM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"


class Arm: public frc::Subsystem {

private:


	static const char kSubsystemName[];
	static std::shared_ptr<Arm> self;

	WPI_TalonSRX armMotor;

public:
	static std::shared_ptr<Arm> getInstance();

	Arm();
	void InitDefaultCommand() override;

};

#endif
