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
#include <Commands/SetElevatorPos.h>
#include "Commands/SetIntake.h"

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    coDriver.reset(new frc::Joystick(1));

    driver.reset(new frc::Joystick(0));


    // SmartDashboard Buttons
    frc::SmartDashboard::PutData("ArmForward", new ArmMove(1));
    frc::SmartDashboard::PutData("ArmBackward", new ArmMove(-1));
    frc::SmartDashboard::PutData("ArmPosition1", new ArmPos(1000));
    frc::SmartDashboard::PutData("ArmPosition2", new ArmPos(2000));
    frc::SmartDashboard::PutData("ElevatorPosition1", new SetElevatorPos(1000));
    frc::SmartDashboard::PutData("ElevatorPosition2", new SetElevatorPos(2000));
    frc::SmartDashboard::PutData("ElevatorUp", new SetElevatorMove(1));
    frc::SmartDashboard::PutData("ElevatorDown", new SetElevatorMove(-1));
    frc::SmartDashboard::PutData("ClimberOff", new ClimberOff());
    frc::SmartDashboard::PutData("IntakeOff", new IntakeOff());
    frc::SmartDashboard::PutData("Engage Claw", new ClawEngage());
    frc::SmartDashboard::PutData("Disengage Claw", new ClawDisengage());
    frc::SmartDashboard::PutData("IntakeIn", new SetIntake(0.5));
    frc::SmartDashboard::PutData("IntakeOut", new SetIntake(-0.5));
    frc::SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<frc::Joystick> OI::getdriver() {
   return driver;
}

std::shared_ptr<frc::Joystick> OI::getcoDriver() {
   return coDriver;
}

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
