// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "DriveWithJoysticks.h"

DriveWithJoysticks::DriveWithJoysticks() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void DriveWithJoysticks::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoysticks::Execute() {
	// Gather the XBox controller left and right joystick Y axes values from the most recently received
	// Driver Station transmission packet, and send them to the chassis SendJoystickYAxesToMotors method
	Robot::chassis->SendJoystickYAxesToMotors(
		Robot::oi->getJoystickDriverOnPort0()->GetRawAxis(1),
		Robot::oi->getJoystickDriverOnPort0()->GetRawAxis(5));
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoysticks::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveWithJoysticks::End() {
	// Stop the drive motors
	Robot::chassis->StopMotors();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoysticks::Interrupted() {
	// Invoke our own End method
	End();

}
