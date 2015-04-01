// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"



// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
Chassis* Robot::chassis = 0;
Elevator* Robot::elevator = 0;
Arm* Robot::arm = 0;
ElevatorPID* Robot::elevatorPID = 0;
Intake* Robot::intake = 0;
OI* Robot::oi = 0;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	chassis = new Chassis();
	elevator = new Elevator();
	arm = new Arm();
	elevatorPID = new ElevatorPID();
	intake = new Intake();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand = new AutonomousDriveToScore();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

	//Perform any one time chassis related calibrations
	Robot::chassis->CalibrateChassis();
	//Adds a sendable chooser to choose between AutonomousDriveToScore and AutonomousPickupAndScore
	chooser = new SendableChooser();
	chooser->AddDefault("DriveToScore", new AutonomousDriveToScore());
	chooser->AddObject("Pickup1ToteAndScore", new AutonomousPickupAndScore());
	chooser->AddObject("Pickup2TotesAndScore", new AutonomousPickupTwoTotesAndScore());
	chooser->AddObject("Pickup3TotesAndScore", new AutonomousPickupThreeTotesAndScore());
	chooser->AddObject("PickupCanAndScore", new AutonomousPickupCanAndScore());
	chooser->AddObject("PickupCanWait", new AutonomousKnockOverCan());
	chooser->AddObject("Auto Testing - DO NOT USE", new AutonomousTesting());
	SmartDashboard::PutData("Autonomous Modes", chooser);

	//Simple Vision camera code
	//CameraServer::GetInstance()->SetQuality(50);
	//The camera name (ex "cam0") can be found through the roborio web interface
    //CameraServer::GetInstance()->StartAutomaticCapture("cam0");
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
	}

void Robot::AutonomousInit() {
	//run autonomous command using sendable chooser

	autonomousCommand = (Command *) chooser->GetSelected();
	if (autonomousCommand != NULL) {
		autonomousCommand->Start();
	}
}

void Robot::AutonomousPeriodic() {
//	chassis->movementData->UpdateData();
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
}


void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

