	// RobotBuilder Version: 1.5
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
#include "Commands/ArmOpenClose.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/AutonomousDriveToScore.h"
#include "Commands/AutonomousPickupAndScore.h"
#include "Commands/ChassisDriveStraightForTime.h"
#include "Commands/ChassisRotate.h"
#include "Commands/DriveWithJoysticks.h"
#include "Commands/ElevatorDownOne.h"
#include "Commands/ElevatorManual.h"
#include "Commands/ElevatorPIDDownOne.h"
#include "Commands/ElevatorPIDUpOne.h"
#include "Commands/ElevatorUpOne.h"
#include "Commands/IntakeIn.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	joystickDriverOnPort2 = new Joystick(2);
	
	joystick2Button3 = new JoystickButton(joystickDriverOnPort2, 3);
	joystick2Button3->WhileHeld(new IntakeIn());
	joystickGunnerOnPort1 = new Joystick(1);
	
	joystickButton4 = new JoystickButton(joystickGunnerOnPort1, 4);
	joystickButton4->WhenPressed(new ElevatorManual());
	joystickButton3 = new JoystickButton(joystickGunnerOnPort1, 3);
	joystickButton3->WhenPressed(new ElevatorUpOne());
	joystickButton2 = new JoystickButton(joystickGunnerOnPort1, 2);
	joystickButton2->WhenPressed(new ElevatorDownOne());
	joystickButton1 = new JoystickButton(joystickGunnerOnPort1, 1);
	joystickButton1->WhenPressed(new ArmOpenClose());
	joystickDriverOnPort0 = new Joystick(0);
	
     

        // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

	SmartDashboard::PutData("DriveWithJoysticks", new DriveWithJoysticks());

	SmartDashboard::PutData("AutonomousDriveToScore", new AutonomousDriveToScore());

	SmartDashboard::PutData("AutonomousPickupAndScore", new AutonomousPickupAndScore());

	SmartDashboard::PutData("ChassisDriveStraightForTime", new ChassisDriveStraightForTime());

	SmartDashboard::PutData("ChassisRotate", new ChassisRotate());

	SmartDashboard::PutData("ElevatorUpOne", new ElevatorUpOne());

	SmartDashboard::PutData("ElevatorDownOne", new ElevatorDownOne());

	SmartDashboard::PutData("ArmOpenClose", new ArmOpenClose());

	SmartDashboard::PutData("ElevatorManual", new ElevatorManual());

	SmartDashboard::PutData("IntakeIn", new IntakeIn());

	SmartDashboard::PutData("ElevatorPIDUpOne", new ElevatorPIDUpOne());

	SmartDashboard::PutData("ElevatorPIDDownOne", new ElevatorPIDDownOne());


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	SmartDashboard::PutNumber("DrivingSensitivity", .5);
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

Joystick* OI::getJoystickDriverOnPort2() {
	return joystickDriverOnPort2;
}

Joystick* OI::getJoystickGunnerOnPort1() {
	return joystickGunnerOnPort1;
}

Joystick* OI::getJoystickDriverOnPort0() {
	return joystickDriverOnPort0;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
