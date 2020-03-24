// #include "main.hpp"
// #include "motors.hpp"
// #include "okapi/api.hpp"

// using namespace okapi;

// /*
// figure out how to change motor unit to degree + calculate motor rotations to get
// to the right spot for the arms. that should make the arms go to the right spot
// every time; call with this position as a param.
// */

//   void autonomous(){
//   //local declaration of drive train
//   auto drive = ChassisControllerBuilder()
//                    .withMotors(L_DR, R_DR)
//                    // Green gearset, 4 in wheel diam, 13.5 in wheel base
//                    .withDimensions(AbstractMotor::gearset::red, {{4_in, 13.5_in}, imev5RedTPR})
//                    .build();
//   push.move_voltage(MAX_MOTOR_VOLTAGE);
//   pros::delay(425);
//   push.move_voltage(0);

//   //bring out arms
//   arm_l.move(127);
//   arm_r.move(127);
//   pros::delay(1200);
//   arm_r.move(0);
//   arm_l.move(0);

//   //run rollers
//   roller_left.move(127);
//   roller_right.move(127);

//   //moving
//   drive->setMaxVelocity(100);
//   drive->moveDistance(8_in);
//   drive->turnAngleAsync(-77_deg);
//   drive->waitUntilSettled();
//   drive->moveDistance(22_in);
//   drive->waitUntilSettled();
//   drive->turnAngle(165_deg);
//   drive->waitUntilSettled();
//   roller_left.move(0);
//   roller_right.move(0);

//   //move forward to goal
//   dr_l.move_voltage(MAX_MOTOR_VOLTAGE);
//   dr_r.move_voltage(MAX_MOTOR_VOLTAGE);
//   pros::delay(1100);
//   dr_l.move(0);
//   dr_r.move(0);
//   drive->waitUntilSettled();

//   //push up
//   push.move(6000);
//   pros::delay(4000);
//   push.move(0);
//   pros::delay(100);
//   roller_left.move(-200);
//   roller_right.move(-200);
//   pros::delay(100);
//   roller_left.move(0);
//   roller_right.move(0);

//   //roll out
//   roller_left.move_velocity(-200);
//   roller_right.move_velocity(-200);
//   drive->setMaxVelocity(100);

//   //move back
//   drive->moveDistanceAsync(-10_in);
//   pros::delay(1200);
//   roller_left.move(0);
//   roller_right.move(0);
// }

#include "main.hpp"
#include "motors.hpp"
#include "okapi/api.hpp"

using namespace okapi;

void autonomous()
{
  //local declaration of drive train
  auto drive = ChassisControllerBuilder()
                   .withMotors(L_DR, R_DR)
                   // Green gearset, 4 in wheel diam, 15.9375 in wheel base
                   .withDimensions(AbstractMotor::gearset::green, {{4_in, 15.9375_in}, imev5GreenTPR})
                   .build();

  //bring out arms
  arm_l.move(127);
  arm_r.move(127);
  pros::delay(1250);
  arm_r.move(0);
  arm_l.move(0);
  //twitch up for tip wheel
  push.move_voltage(MAX_MOTOR_VOLTAGE);
  pros::delay(500);
  push.move_voltage(-MAX_MOTOR_VOLTAGE);
  pros::delay(500);
  push.move_voltage(0);
  //run rollers
  roller_left.move_voltage(MAX_MOTOR_VOLTAGE);
  roller_right.move_voltage(MAX_MOTOR_VOLTAGE);
  //moving
  drive->setMaxVelocity(105);
  drive->moveDistanceAsync(60_in);
  drive->waitUntilSettled();
  //stop rollers
  roller_left.move(0);
  roller_right.move(0);
  //move back and speed up
  drive->setMaxVelocity(175);
  drive->moveDistanceAsync(-26_in);
  drive->waitUntilSettled();
  pros::delay(150);
  //turn
  drive->turnAngleAsync(-187_deg);
  drive->waitUntilSettled();
  //move forward to goal
  drive->setMaxVelocity(200);
  dr_l.move_voltage(MAX_MOTOR_VOLTAGE);
  dr_r.move_voltage(MAX_MOTOR_VOLTAGE);
  pros::delay(950);
  dr_l.move(0);
  dr_r.move(0);
  drive->waitUntilSettled();
  //roll out to straighten cubes
  roller_left.move_voltage(-MAX_MOTOR_VOLTAGE);
  roller_right.move_velocity(-MAX_MOTOR_VOLTAGE);
  pros::delay(200);
  roller_left.move_velocity(0);
  roller_right.move_velocity(0);
  //push up
  push.move_voltage(MAX_MOTOR_VOLTAGE);
  pros::delay(4000);
  push.move(0);
  pros::delay(100);
  //roll out
  roller_left.move_velocity(-100);
  roller_right.move_velocity(-100);
  drive->setMaxVelocity(100);
  //move back
  drive->moveDistance(-10_in);
  roller_left.move(0);
  roller_right.move(0);
  push.move_voltage(-MAX_MOTOR_VOLTAGE);
}