//SMALL REd GOAL

#include "main.hpp"
#include "motors.hpp"
#include "okapi/api.hpp"

using namespace okapi;

void autonomous(){ //SMALL RED GOAL
//local declaration of drive train
auto drive = ChassisControllerBuilder()
    .withMotors(L_DR, R_DR)
    // Green gearset, 4 in wheel diam, 11.5 in wheel track
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 15.9375_in}, imev5GreenTPR})
    .build();
//bring out arms
  arm_l.move(127);
  arm_r.move(127);
  pros::delay(1200);
  arm_r.move(0);
  arm_l.move(0);
  pros::delay(200);
//run rollers
  roller_left.move(127);
  roller_right.move(127);
//moving
drive->setMaxVelocity(95);
  drive->moveDistanceAsync(45_in);
  drive->waitUntilSettled();
//stop rollers
  pros::delay(50);
  roller_left.move(0);
  roller_right.move(0);
//move back and speed up
  drive->setMaxVelocity(175);
  drive->moveDistanceAsync(-26_in);
  drive->waitUntilSettled();
  pros::delay(150);
//turn
  drive->turnAngleAsync(97_deg); // RED
  drive->waitUntilSettled();
//move forward to goal
drive->setMaxVelocity(200);
  drive->moveDistanceAsync(9_in);
  drive->waitUntilSettled();
  roller_left.move(-200);
  roller_right.move(-200);
  pros::delay(200);
  roller_left.move(0);
  roller_right.move(0);
//push up
  push.move(6000);
  pros::delay(4000);
  push.move(0);
  pros::delay(100);
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
