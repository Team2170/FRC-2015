// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ChassisDriveStraightForTime.h"
#include <iostream>

ChassisDriveStraightForTime::ChassisDriveStraightForTime() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
ChassisDriveStraightForTime::ChassisDriveStraightForTime(double NewTime, bool Backwards)
{
	Requires(Robot::chassis);

	mDriveTime = NewTime;

	bDriveBackwards = Backwards;
}

// Called just before this Command runs the first time
void ChassisDriveStraightForTime::Initialize() {
	std::cout << "Current Yaw: " << Robot::chassis->ReadChassisYaw() << std::endl;
	Robot::chassis->ResetChassisYaw();
	Robot::chassis->movementData->ResetOdometer();
	Robot::chassis->movementData->Start();
	Command::SetTimeout(GetDriveTime());
}

// Called repeatedly when this Command is scheduled to run
void ChassisDriveStraightForTime::Execute() {
	Robot::chassis->DriveStraight(bDriveBackwards);
}

// Make this return true when this Command no longer needs to run execute()
bool ChassisDriveStraightForTime::IsFinished() {
	Robot::chassis->movementData->UpdateData();
	return Command::IsTimedOut();
}

// Called once after isFinished returns true
void ChassisDriveStraightForTime::End() {
	Robot::chassis->StopMotors();
	Robot::chassis->movementData->Stop();
	SmartDashboard::PutNumber("Auto Distance", Robot::chassis->movementData->GetOdometer());

}

double ChassisDriveStraightForTime::GetDriveTime(void) {
	double fTime = 0.0;

	if (bSmartDashCtrl) {
		fTime = (double)SmartDashboard::GetNumber(mKey);
		//Outputs what was
		SmartDashboard::PutNumber("TimeInputted", fTime);
		//Sets the range for the input
		fTime = fmin(fmax(fTime, 0), 15);
		//Displays the new number
		SmartDashboard::PutNumber("ChassisDriveStraightForTimeInput", fTime);
	}
	else {
		fTime = mDriveTime;
	}

	return fTime;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChassisDriveStraightForTime::Interrupted() {


}

ChassisDriveStraightForTime::ChassisDriveStraightForTime(std::string key) {
	Requires(Robot::chassis);

	mKey = key;
	bSmartDashCtrl = true;
}
