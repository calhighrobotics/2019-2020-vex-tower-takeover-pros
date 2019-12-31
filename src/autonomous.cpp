#include "main.hpp"
#include "motors.hpp"
#include "okapi/api.hpp"

#define LEFT_LIM 'g'
#define RIGHT_LIM 'h'

using namespace okapi;

void autonomous() { // RED AUTONOMOUS
//local declaration of drive train
auto dt = ChassisControllerFactory::create(
  -L_DR, R_DR, //left motor is reversed
  AbstractMotor::gearset::green,
  {4_in, 15.9375_in}
);

ADIButton left_lim(LEFT_LIM);
ADIButton right_lim(RIGHT_LIM);

dt.setMaxVelocity(45);

pros::delay(25); // allow robot to settle
//bring out arms
  arm_r.move(127);
  arm_l.move(127);
  pros::delay(800);
  arm_r.move(0);
  arm_l.move(0);
//run rollers
  roller_left.move_velocity(600); // we'll be able to pick up more cubes once speed cartridges come in
  roller_right.move_velocity(600);
  //ignore preload until speed cartridges
  // // allow preload to enter
  // pros::delay(450);
//moving
  dt.moveDistanceAsync(47_in);
  dt.waitUntilSettled();
  pros::delay(400);
//stop rollers
  roller_left.move(0);
  roller_right.move(0);
//move back and speed up
  dt.setMaxVelocity(180);
  dt.moveDistanceAsync(-22_in);
  dt.waitUntilSettled();
//turn
  dt.turnAngleAsync(110_deg);
  dt.waitUntilSettled();
//move forward to goal
  dt.moveDistance(19_in);
  dt.waitUntilSettled();
//push up
  push.move(127);
  pros::delay(2725);
  push.move(0);
//roll out and pull arms back
  roller_left.move(-127);
  roller_right.move(127);
  arm_r.move(-127);
  arm_l.move(-127);
  pros::delay(800);
  roller_left.move(0);
  roller_right.move(0);
  arm_r.move(0);
  arm_l.move(0);
//move back
  dt.moveDistance(-3_in);
}
