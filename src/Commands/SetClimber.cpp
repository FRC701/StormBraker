#include "SetClimber.h"
#include "Subsystems/Climber.h"
#include "OI.h"

SetClimber::SetClimber(double speed): mSpeed(speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Climber::getInstance().get());
}

// Called just before this Command runs the first time
void SetClimber::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SetClimber::Execute() {
  Climber::getInstance()->Climb(mSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool SetClimber::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SetClimber::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetClimber::Interrupted() {

}

