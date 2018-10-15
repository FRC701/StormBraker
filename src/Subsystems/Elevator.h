#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "ctre/Phoenix.h"
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <AnalogInput.h>
#include <Preferences.h>


class Elevator: public frc::Subsystem {
private:
	static const char kSubsystemName[];
	static std::shared_ptr<Elevator> self;
	WPI_TalonSRX topElevator;
	WPI_TalonSRX bottomElevator;

	void SetUpTalons();
	void SetUpMotionMagic();

public:
	static std::shared_ptr<Elevator> getInstance();


	Elevator();
	void InitDefaultCommand() override;
	void SetElevator(double speed);
	void setElevatorPos(int position);
	bool IsFwdLimitSwitchClosed();
	bool IsRevLimitSwitchClosed();

	double GetPosError();


};

#endif
