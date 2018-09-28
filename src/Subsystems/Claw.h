#ifndef CLAW_H
#define CLAW_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "DoubleSolenoid.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Claw: public frc::Subsystem {

private:
	static const char kSubsystemName[];
	static std::shared_ptr<Claw> self;
	DoubleSolenoid clawSolenoid;

public:

	static std::shared_ptr<Claw> getInstance();

	Claw();

		void InitDefaultCommand() override;
		void ClawEngage();
		void ClawDisengage();

};

#endif
