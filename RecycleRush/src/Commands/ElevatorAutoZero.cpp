// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ElevatorAutoZero.h"

ElevatorAutoZero::ElevatorAutoZero() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::elevator);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void ElevatorAutoZero::Initialize() {
	Robot::elevator->motor->Set(-.3);
}

// Called repeatedly when this Command is scheduled to run
void ElevatorAutoZero::Execute() {
	

}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorAutoZero::IsFinished() {
	return (Robot::elevator->GetLowerSafety());
}

// Called once after isFinished returns true
void ElevatorAutoZero::End() {
	Robot::elevator->Stop();
	Robot::elevator->shaftEncoder->Reset();
	Robot::elevator->SmartDashboardOutputs();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorAutoZero::Interrupted() {
	Robot::elevator->Stop();
}
