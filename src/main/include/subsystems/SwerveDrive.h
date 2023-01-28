// RobotBuilder Version: 4.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// ROBOTBUILDER TYPE: Subsystem.
#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include <frc/Encoder.h>
#include <rev/CANSparkMax.h>
#include "subsystems/SwervePod.h"
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <units/velocity.h>

#define FRONT_RIGHT  0
#define FRONT_LEFT  1
#define BACK_RIGHT  2
#define BACK_LEFT  3

#define k_DB (double)0.07
/**
 * SwerveDrive header file
 *
 * @author 2826WaveRobotics
 */
class SwerveDrive: public frc2::SubsystemBase {
    // It's desirable that everything possible is private except
    // for methods that implement subsystem capabilities
    private:        

        rev::CANSparkMax *m_rightBottomMotor;
        rev::CANSparkMax *m_rightTopMotor;
        rev::CANSparkMax *m_leftBottomMotor;
        rev::CANSparkMax *m_leftTopMotor;
        rev::CANSparkMax *m_pointBottomMotor;
        rev::CANSparkMax *m_pointTopMotor;

        frc::SwerveDriveKinematics<3> *m_kinematics;

        SwervePod *m_rightPod;
        SwervePod *m_leftPod;
        SwervePod *m_pointPod;     

    public:
        // length of the intake side
        const double robotWidth = 0.717;
        // length of the point to the midpoint of the intake side
        const double robotHeight = 0.617;

        SwerveDrive();

        void Periodic() override;
        void SimulationPeriodic() override;

        /**
         * Function that takes inputs from the joysticks and transforms
         * the inputs into states (speed, angle) that individual swerve modules will utilize
         * 
         * @param foward joystick input from left x-axis (LX)
         * @param strafe joystick input from left y-axis (LY)
         * @param rotation joystick input from right x-axis (RX)
         **/
        void DrivePods(double forward, double strafe, double rotation);

        void initialize();
        
};
