#include "main.hpp"
#include "motors.hpp"
#include "okapi/api.hpp"

using namespace okapi;

/*
figure out how to change motor unit to degree + calculate motor rotations to get
to the right spot for the arms. that should make the arms go to the right spot
every time; call with this position as a param.
*/

  void autonomous(){
  //local declaration of drive train
  auto drive = ChassisControllerBuilder()
                   .withMotors(L_DR, R_DR)
                   // Green gearset, 4 in wheel diam, 13.5 in wheel base
                   .withDimensions(AbstractMotor::gearset::red, {{4_in, 13.5_in}, imev5RedTPR})
                   .build();
  // push.move_voltage(MAX_MOTOR_VOLTAGE);
  // pros::delay(425);
  // push.move_voltage(0);
  //bring out arms
  arm_l.move(127);
  arm_r.move(127);
  pros::delay(1200);
  arm_r.move(0);
  arm_l.move(0);
  //run rollers
  roller_left.move(127);
  roller_right.move(127);
  //moving
  drive->setMaxVelocity(100);
  drive->moveDistance(8_in);
  drive->turnAngleAsync(-80_deg);
  drive->waitUntilSettled();
  drive->moveDistance(22_in);
  drive->waitUntilSettled();
  drive->turnAngle(-45_deg);
  drive->waitUntilSettled();
  drive->moveDistance(5_in);
  drive->waitUntilSettled();
  pros::delay(100);
  drive->moveDistance(-5_in);
  drive->waitUntilSettled();
  drive->turnAngle(200_deg);
  drive->waitUntilSettled();
  // drive->turnAngle(180_deg);
  // drive->waitUntilSettled();
  // drive->moveDistance(48_in);
  // drive->turnAngle(45_deg);
  pros::delay(3000); //delete
  //stop rollers
  roller_left.move(0);
  roller_right.move(0);
  // //move forward to goal
  // dr_l.move_voltage(MAX_MOTOR_VOLTAGE);
  // dr_r.move_voltage(MAX_MOTOR_VOLTAGE);
  // pros::delay(1100);
  // dr_l.move(0);
  // dr_r.move(0);
  // drive->waitUntilSettled();
  // //push up
  // push.move(6000);
  // pros::delay(4000);
  // push.move(0);
  // pros::delay(100);
  // roller_left.move(-200);
  // roller_right.move(-200);
  // pros::delay(100);
  // roller_left.move(0);
  // roller_right.move(0);
  // //roll out
  // roller_left.move_velocity(-200);
  // roller_right.move_velocity(-200);
  // drive->setMaxVelocity(100);
  // //move back
  // drive->moveDistanceAsync(-10_in);
  // pros::delay(1200);
  // roller_left.move(0);
  // roller_right.move(0);
}
