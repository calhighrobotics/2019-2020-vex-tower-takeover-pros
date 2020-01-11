#include "main.hpp"
#include "motors.hpp"
#include "okapi/api.hpp"

using namespace okapi;

void autonomous(){ //SMALL RED/BLUE GOALS
//local declaration of drive train
auto drive = ChassisControllerBuilder()
    .withMotors(L_DR, R_DR)
    // Green gearset, 4 in wheel diam, 11.5 in wheel track
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 15.9375_in}, imev5GreenTPR})
    .build();
//bring out arms
  arm_l.move(127);
  arm_r.move(127);
  pros::delay(600);
  arm_r.move(0);
  arm_l.move(0);
//run rollers
  roller_left.move(600);
  roller_right.move(600);
//moving
drive->setMaxVelocity(45);
  drive->moveDistanceAsync(48_in);
  drive->waitUntilSettled();
//stop rollers
  pros::delay(100);
  roller_left.move(0);
  roller_right.move(0);
//move back and speed up
  drive->setMaxVelocity(170);
  drive->moveDistanceAsync(-26_in);
  drive->waitUntilSettled();
  pros::delay(150);
//turn
  drive->turnAngleAsync(107_deg); // RED
  // drive->turnAngleAsync(-107_deg); // BLUE
  drive->waitUntilSettled();
//move forward to goal
drive->setMaxVelocity(180);
  drive->moveDistanceAsync(23_in);
  drive->waitUntilSettled();
//push up
  push.move(90); //went the wrong way!!
  pros::delay(2000);
  push.move(0);
//roll out and pull arms back
  roller_left.move_velocity(-200);
  roller_right.move_velocity(200);
  arm_l.move_velocity(-127);
  arm_r.move_velocity(-127);
  pros::delay(800);
  roller_left.move(0);
  roller_right.move(0);
  arm_r.move(0);
  arm_l.move(0);
//move back
  drive->moveDistance(-10_in);
}

// void autonomous() { BIG BLUE
// //local declaration of drive train
// auto drive = ChassisControllerBuilder()
//     .withMotors(L_DR, R_DR)
//     // Green gearset, 4 in wheel diam, 11.5 in wheel track
//     .withDimensions(AbstractMotor::gearset::green, {{4_in, 15.9375_in}, imev5GreenTPR})
//     .build();
// //bring out arms
//   arm_l.move(127);
//   arm_r.move(127);
//   pros::delay(200);
//   roller_left.move(600);
//   roller_right.move(600);
//   pros::delay(400);
//   arm_r.move(0);
//   arm_l.move(0);
// //run rollers
//
// //moving
// drive->setMaxVelocity(45);
//   drive->moveDistanceAsync(48_in);
//   drive->waitUntilSettled();
// //move back and speed up
//   drive->setMaxVelocity(170);
// //turn
//   drive->turnAngleAsync(103_deg); // BLUE
//   // drive->turnAngleAsync(-103_deg); // RED
//   drive->waitUntilSettled();
// //move forward to goal
// drive->setMaxVelocity(180);
//   drive->moveDistanceAsync(48_in);
//   pros::delay(1550);
//   roller_left.move(0);
//   roller_right.move(0);
//   drive->waitUntilSettled();
//
// //push up
//   push.move(90);
//   pros::delay(1950);
//   push.move(0);
// //roll out and pull arms back
//   roller_left.move_velocity(-200);
//   roller_right.move_velocity(200);
//   arm_l.move_velocity(-127);
//   arm_r.move_velocity(-127);
//   pros::delay(800);
//   roller_left.move(0);
//   roller_right.move(0);
//   arm_r.move(0);
//   arm_l.move(0);
// //move back
//   drive->moveDistance(-10_in);
// }
