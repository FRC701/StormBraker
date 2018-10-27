// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "OI.h"

using Joystick = frc::Joystick;
using SmartDashboard = frc::SmartDashboard;

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/ClimberOff.h"
#include "Commands/IntakeOff.h"
#include "Commands/TankDrive.h"
#include "Commands/SetElevatorMove.h"
#include "Commands/ArmMove.h"
#include "Commands/ArmPos.h"
#include "Commands/ClawEngage.h"
#include "Commands/ClawDisengage.h"
#include "Commands/IntakeIn.h"
#include "Commands/Outtake.h"
#include <Commands/SetElevatorPos.h>
#include "Commands/SetIntake.h"

std::shared_ptr<OI> OI::self;

std::shared_ptr<OI> OI::getInstance() {
	if (! self) {
		self = std::make_shared<OI>();
	}
	return self;
}

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI()
: driver(new Joystick(0))
, dA(driver.get(), kButtonA_ID)
, dB(driver.get(), kButtonB_ID)
, dX(driver.get(), kButtonX_ID)
, dY(driver.get(), kButtonY_ID)
, dLB(driver.get(), kButtonLB_ID)
, dRB(driver.get(), kButtonRB_ID)
, coDriver(new Joystick(1))
, coA(coDriver.get(), kButtonA_ID)
, coB(coDriver.get(), kButtonB_ID)
, coX(coDriver.get(), kButtonX_ID)
, coY(coDriver.get(), kButtonY_ID)
, coLB(coDriver.get(), kButtonLB_ID)
, coRB(coDriver.get(), kButtonRB_ID)
, coStart(coDriver.get(), kButtonStart_ID)
, coSelect(coDriver.get(), kButtonSelect_ID)
{
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

    // SmartDashboard Buttons
    SmartDashboard::PutData("Arm Forward", new ArmMove(0.3));
    SmartDashboard::PutData("Arm Backward", new ArmMove(-0.3));
    SmartDashboard::PutData("ArmPosition1", new ArmPos(1000));
    SmartDashboard::PutData("ArmPosition2", new ArmPos(2000));
    SmartDashboard::PutData("ElevatorPosition1", new SetElevatorPos(1000));
    SmartDashboard::PutData("ElevatorPosition2", new SetElevatorPos(2000));
    SmartDashboard::PutData("ElevatorUp", new SetElevatorMove(1));
    SmartDashboard::PutData("ElevatorDown", new SetElevatorMove(-1));
    SmartDashboard::PutData("ClimberOff", new ClimberOff());
    SmartDashboard::PutData("Engage Claw", new ClawEngage());
    SmartDashboard::PutData("Disengage Claw", new ClawDisengage());
    SmartDashboard::PutData("TankDrive", new TankDrive());
    SmartDashboard::PutData("Intake On", new IntakeIn);
    SmartDashboard::PutData("Intake Off", new SetIntake(0));
    SmartDashboard::PutData("Out Take", new Outtake);
    SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<Joystick> OI::getdriver() {
   return driver;
}

std::shared_ptr<Joystick> OI::getcoDriver() {
   return coDriver;
}

double OI::getDriverLeftYAxis() const {
	return driver->GetRawAxis(kLeftYAxis_ID);
}

double OI::getDriverRightYAxis() const {
	return driver->GetRawAxis(kRightYAxis_ID);
}

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
