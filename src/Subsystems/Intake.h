#ifndef INTAKE_H
#define INTAKE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "Commands/SetIntake.h"


class Intake: public frc::Subsystem {
private:
	static const char kSubsystemName[];
	static std::shared_ptr<Intake> self;
	WPI_TalonSRX intakeMotor;

public:
	static std::shared_ptr<Intake> getInstance();

	Intake();

	void InitDefaultCommand();
	void SetIntake(double speed);
	bool IsIntakeOn();
	bool IsCubeIn();

};

#endif
