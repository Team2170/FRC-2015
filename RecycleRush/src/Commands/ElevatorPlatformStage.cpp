// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "ElevatorPlatformStage.h"
#include "ElevatorGotoPosition.h"

ElevatorPlatformStage::ElevatorPlatformStage() {

	// Move Arm to tote level 1, plus 3" clearance in order to clear 2" Scoring Platform
	AddSequential(new ElevatorGotoPosition( 654.0*1 + 54*3.0 ));		// Initial estimate 816
}
