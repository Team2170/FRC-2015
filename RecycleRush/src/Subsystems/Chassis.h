// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef CHASSIS_H
#define CHASSIS_H
#include "Commands/Subsystem.h"
#include "../MotionData.h"
#include "../MaxSonarEZ1.h"
#include "../LowPassFilter.h"
#include "WPILib.h"


#define DEADBAND(val, limit)	((fabs(val) < limit) ? 0.0 : val)

/**
 *
 *
 * @author ExampleAuthor
 */
class Chassis: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	float mAutoVelocity = 0.4;
	const float mDefaultAutoRotatationVelocity = 1.0;
	const float mDefaultAutoMagnitude = 0.6;
	const float mDefaultAutoVelocity = 0.4;
	float mCurrentAutoRotationVelocity = 1.0;
	float mCurrentAutoMagnitude = 0.6;
	float mYawGain = -0.3;
	LowPassFilter* LeftStickFilter;
	LowPassFilter* RightStickFilter;

	double AxisPower(double axis, double exponent);
	bool bDriveStraight = false;
	const bool bSwapDirection = true;
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	SpeedController* leftMotor;
	SpeedController* rightMotor;
	RobotDrive* driveMotors;
	Gyro* yawGyro;
	Encoder* chassisEncoder;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	BuiltInAccelerometer* internalAccel;
	MotionData* movementData;
	MaxSonarEZ1* payloadRange = NULL;

	Chassis();
	void InitDefaultCommand();

	void StopMotors();

	void DriveStraight(bool Backwards = false);
	void DriveStraight(float magnitude);
	void TurnClockwise();
	void TurnCounterclockwise();

	void ResetChassisYaw();
	float ReadChassisYaw();
	void CalibrateChassis();
	float ReadChassisDistance();
	void ResetChassisDistance();

	void TankDriveWithTriggers(float Left, float Right, float Trigger);

	float getCurrentAutoMagnitude() const;
	void setCurrentAutoMagnitude(float currentAutoMagnitude = -0.3);
	float getCurrentAutoRotationVelocity() const;
	void setCurrentAutoRotationVelocity(float currentAutoRotationVelocity = 1.0);

	float getAutoVelocity() const {
		return mAutoVelocity;
	}

	void setAutoVelocity(float autoVelocity = 0.4) {
		mAutoVelocity = autoVelocity;
	}
};

#endif
