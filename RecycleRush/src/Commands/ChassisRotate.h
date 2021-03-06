// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef CHASSISROTATE_H
#define CHASSISROTATE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ChassisRotate: public Command {
protected:
	float mPassedAngle = 0.0;
	float mRotateAngle = 0.0;
	int mDownshiftCounter = 0;
	bool bCorrection = false;
public:
	ChassisRotate();
	ChassisRotate(float NewAngle, bool Correction = false);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
