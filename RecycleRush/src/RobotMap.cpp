// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
SpeedController* RobotMap::chassisLeftMotor = NULL;
SpeedController* RobotMap::chassisRightMotor = NULL;
RobotDrive* RobotMap::chassisDriveMotors = NULL;
Gyro* RobotMap::chassisYawGyro = NULL;
Encoder* RobotMap::chassisChassisEncoder = NULL;
Encoder* RobotMap::elevatorShaftEncoder = NULL;
SpeedController* RobotMap::elevatorMotor = NULL;
DigitalInput* RobotMap::elevatorLowerLimit = NULL;
DigitalInput* RobotMap::elevatorUpperLimit = NULL;
DoubleSolenoid* RobotMap::armDoubleSolenoid = NULL;
Encoder* RobotMap::elevatorPIDShaftEncoder = NULL;
SpeedController* RobotMap::elevatorPIDMotor = NULL;
Relay* RobotMap::intakeLeftMotor = NULL;
Relay* RobotMap::intakeRightMotor = NULL;
DoubleSolenoid* RobotMap::intakeDoubleSolenoid = NULL;
DigitalInput* RobotMap::intakeToteReceivedLimit = NULL;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();

	chassisLeftMotor = new Talon(0);
	lw->AddActuator("Chassis", "LeftMotor", (Talon*) chassisLeftMotor);
	
	chassisRightMotor = new Talon(1);
	lw->AddActuator("Chassis", "RightMotor", (Talon*) chassisRightMotor);
	
	chassisDriveMotors = new RobotDrive(chassisLeftMotor, chassisRightMotor);
	
	chassisDriveMotors->SetSafetyEnabled(true);
        chassisDriveMotors->SetExpiration(0.1);
        chassisDriveMotors->SetSensitivity(0.5);
        chassisDriveMotors->SetMaxOutput(1.0);
        

	chassisYawGyro = new Gyro(0);
	lw->AddSensor("Chassis", "YawGyro", chassisYawGyro);
	chassisYawGyro->SetSensitivity(0.007);
	chassisChassisEncoder = new Encoder(5, 6, false, Encoder::k4X);
	lw->AddSensor("Chassis", "ChassisEncoder", chassisChassisEncoder);
	chassisChassisEncoder->SetDistancePerPulse(1.0);
        chassisChassisEncoder->SetPIDSourceParameter(Encoder::kRate);
	elevatorShaftEncoder = new Encoder(0, 1, false, Encoder::k4X);
	lw->AddSensor("Elevator", "ShaftEncoder", elevatorShaftEncoder);
	elevatorShaftEncoder->SetDistancePerPulse(1.0);
        elevatorShaftEncoder->SetPIDSourceParameter(Encoder::kRate);
	elevatorMotor = new Talon(2);
	lw->AddActuator("Elevator", "Motor", (Talon*) elevatorMotor);
	
	elevatorLowerLimit = new DigitalInput(2);
	lw->AddSensor("Elevator", "LowerLimit", elevatorLowerLimit);
	
	elevatorUpperLimit = new DigitalInput(3);
	lw->AddSensor("Elevator", "UpperLimit", elevatorUpperLimit);
	
	armDoubleSolenoid = new DoubleSolenoid(0, 0, 1);      
	lw->AddActuator("Arm", "DoubleSolenoid", armDoubleSolenoid);
	
	elevatorPIDShaftEncoder = new Encoder(8, 9, false, Encoder::k4X);
	lw->AddSensor("ElevatorPID", "ShaftEncoder", elevatorPIDShaftEncoder);
	elevatorPIDShaftEncoder->SetDistancePerPulse(1.0);
        elevatorPIDShaftEncoder->SetPIDSourceParameter(Encoder::kRate);
	elevatorPIDMotor = new Talon(9);
	lw->AddActuator("ElevatorPID", "Motor", (Talon*) elevatorPIDMotor);
	
	intakeLeftMotor = new Relay(0);
	lw->AddActuator("Intake", "LeftMotor", intakeLeftMotor);
	
	intakeRightMotor = new Relay(1);
	lw->AddActuator("Intake", "RightMotor", intakeRightMotor);
	
	intakeDoubleSolenoid = new DoubleSolenoid(0, 2, 3);      
	lw->AddActuator("Intake", "DoubleSolenoid", intakeDoubleSolenoid);
	
	intakeToteReceivedLimit = new DigitalInput(4);
	lw->AddSensor("Intake", "ToteReceivedLimit", intakeToteReceivedLimit);
	


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
