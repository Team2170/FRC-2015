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
#include "Commands/ArmCalibrate.h"
#include "Commands/ArmClose.h"
#include "Commands/ArmOpen.h"
#include "Commands/ArmOpenClose.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/AutonomousDriveToScore.h"
#include "Commands/AutonomousPickupAndScore.h"
#include "Commands/AutonomousPickupCanAndScore.h"
#include "Commands/AutonomousPickupThreeTotesAndScore.h"
#include "Commands/AutonomousPickupTwoTotesAndScore.h"
#include "Commands/AutonomousTesting.h"
#include "Commands/ChassisCalibrate.h"
#include "Commands/ChassisDriveStraightForDistance.h"
#include "Commands/ChassisDriveStraightForTime.h"
#include "Commands/ChassisPIDDriveStraightForDistance.h"
#include "Commands/ChassisPIDRotate.h"
#include "Commands/ChassisRotate.h"
#include "Commands/DriveWithJoysticks.h"
#include "Commands/ElevatorAutoZero.h"
#include "Commands/ElevatorDownOne.h"
#include "Commands/ElevatorFeederPickup.h"
#include "Commands/ElevatorFeederStage.h"
#include "Commands/ElevatorFloorPickup.h"
#include "Commands/ElevatorFloorStage.h"
#include "Commands/ElevatorGotoPosition.h"
#include "Commands/ElevatorManual.h"
#include "Commands/ElevatorPIDDownOne.h"
#include "Commands/ElevatorPIDUpOne.h"
#include "Commands/ElevatorPlatformPlace.h"
#include "Commands/ElevatorPlatformStage.h"
#include "Commands/ElevatorUpOne.h"
#include "Commands/IntakeCalibrate.h"
#include "Commands/IntakeClose.h"
#include "Commands/IntakeIn.h"
#include "Commands/IntakeOpen.h"
#include "Commands/IntakeOpenClose.h"
#include "Commands/IntakeOut.h"
#include "Commands/IntakeSpin.h"
#include "Commands/IntakeSpinLeft.h"
#include "Commands/IntakeSpinRight.h"
#include "Commands/IntakeStop.h"
#include "Commands/RotateWithBumpersLeft.h"
#include "Commands/RotateWithBumpersRight.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
	// Process operator interface input here.
	//COMMENTED OUT UNTIL DRIVE TEAM MAKES TANK DRIVE SENSITIVITY CODE
	//SmartDashboard::PutNumber("DrivingSensitivity", .5);

	// Create SD key fields here!!  Not at the END !!!
	SmartDashboard::PutNumber("ChassisDriveStraightForTimeInput", 2);

	SmartDashboard::PutNumber("ChassisRotateAngleInput", 90);

	// All defaults below are theoretical and should be replaced by real world tuning of encoder positions using manual joystick positioning
	SmartDashboard:: PutNumber("ElevatorFeederTop",    3.5*654);           // 3.5 totes to allow for feeder diagonal tote slide-in
	SmartDashboard:: PutNumber("ElevatorFeederBot",    2.0*654 - 2.0*54);  // 2.0 totes minus roughly 2   inches to get fingers below tote lips
	SmartDashboard:: PutNumber("ElevatorFloorTop",     2.0*654 + 2.0*54);  // 2.0 totes plus  roughly 2   inches for inter-tote clearance
	SmartDashboard:: PutNumber("ElevatorFloorBot",     1.0*654 - 2.0*54);  // 1.0 tote  minus roughly 2   inches to get fingers below tote lips
	SmartDashboard:: PutNumber("ElevatorPlatformTop",  1.0*654 + 3.0*54);  // 1.0 tote  plus  roughly 3   inches to clear 2" platform
	SmartDashboard:: PutNumber("ElevatorPlatformBot",  1.0*654 + 1.5*54);  // 1.0 tote  plus  roughly 1.5 inches to have stack land on 2" platform

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	joystickDriverOnPort2 = new Joystick(2);
	
	joystick2Button7 = new JoystickButton(joystickDriverOnPort2, 7);
	joystick2Button7->WhenPressed(new IntakeStop());
	joystick2Button5 = new JoystickButton(joystickDriverOnPort2, 5);
	joystick2Button5->WhileHeld(new IntakeSpinRight());
	joystick2Button4 = new JoystickButton(joystickDriverOnPort2, 4);
	joystick2Button4->WhileHeld(new IntakeSpinLeft());
	joystick2Button3 = new JoystickButton(joystickDriverOnPort2, 3);
	joystick2Button3->WhileHeld(new IntakeIn());
	joystick2Button2 = new JoystickButton(joystickDriverOnPort2, 2);
	joystick2Button2->WhileHeld(new IntakeOut());
	joystick2Button1 = new JoystickButton(joystickDriverOnPort2, 1);
	joystick2Button1->WhenPressed(new IntakeOpenClose());
	joystickGunnerOnPort1 = new Joystick(1);
	
	joystickButton11 = new JoystickButton(joystickGunnerOnPort1, 11);
	joystickButton11->WhenPressed(new ElevatorFloorPickup());
	joystickButton5 = new JoystickButton(joystickGunnerOnPort1, 5);
	joystickButton5->WhenPressed(new ElevatorManual());
	joystickButton4 = new JoystickButton(joystickGunnerOnPort1, 4);
	joystickButton4->WhenPressed(new ElevatorFeederPickup());
	joystickButton3 = new JoystickButton(joystickGunnerOnPort1, 3);
	joystickButton3->WhenPressed(new ElevatorFeederStage());
	joystickButton2 = new JoystickButton(joystickGunnerOnPort1, 2);
	joystickButton2->WhenPressed(new ElevatorFloorStage());
	joystickButton1 = new JoystickButton(joystickGunnerOnPort1, 1);
	joystickButton1->WhenPressed(new ArmOpenClose());
	joystickDriverOnPort0 = new Joystick(0);
	
	joystickRightBumper = new JoystickButton(joystickDriverOnPort0, 6);
	joystickRightBumper->WhenPressed(new RotateWithBumpersRight());
	joystickLeftBumper = new JoystickButton(joystickDriverOnPort0, 5);
	joystickLeftBumper->WhenPressed(new RotateWithBumpersLeft());
     

        // SmartDashboard Buttons
	SmartDashboard::PutData("AutonomousDriveToScore", new AutonomousDriveToScore());


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	SmartDashboard:: PutNumber("distanceBetweenLevels", 654);

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
