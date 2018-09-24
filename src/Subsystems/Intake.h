#ifndef INTAKE_H
#define INTAKE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"


class Intake: public frc::Subsystem {
private:

public:
	static std::shared_ptr<Intake> getInstance();

	Intake();

	void InitDefaultCommand();
	void SetIntake(double speed);
	bool IsIntakeOn();

};

#endif
