#pragma once

#include <Commands/Command.h>

class SetClimber : public frc::Command {
public:
	SetClimber(double speed);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
private:
	double mSpeed;
};
