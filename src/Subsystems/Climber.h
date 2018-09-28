#ifndef CLIMBER_H
#define CLIMBER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "DoubleSolenoid.h"

class Climber: public frc::Subsystem {
private:

	static const char kSubsystemName[];
	static std::shared_ptr<Climber> self;

	WPI_TalonSRX rightClimber;
	WPI_TalonSRX leftClimber;
	DoubleSolenoid climberShifter;

public:
	static std::shared_ptr<Climber> getInstance();


	Climber();
	void InitDefaultCommand() override;
	void ClimberEngage();
	void ClimberDisengage();

};

#endif
