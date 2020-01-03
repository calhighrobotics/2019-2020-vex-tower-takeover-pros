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

//bring out arms
  arm_l.move(127);
  arm_r.move(127);
  pros::delay(800);
  arm_r.move(0);
  arm_l.move(0);
//run rollers
  roller_left.move(600);
  roller_right.move(600);
// allow preload to enter
  pros::delay(200);
//moving
dt.setMaxVelocity(35);
  dt.moveDistanceAsync(14_in);
  dt.waitUntilSettled();
dt.setMaxVelocity(45);
  dt.moveDistanceAsync(33_in);
  dt.waitUntilSettled();
  pros::delay(200);
//move back and speed up
  dt.setMaxVelocity(190);
  dt.moveDistanceAsync(-24_in);
  dt.waitUntilSettled();
//turn
  dt.turnAngleAsync(-105_deg);
  dt.waitUntilSettled();
//move forward to goal
  dt.moveDistanceAsync(18_in);
  //stop rollers
    roller_left.move(0);
    roller_right.move(0);
  dt.waitUntilSettled();
//push up
  push.move(90); //went the wrong way!!
  pros::delay(2000);
  push.move(0);
//roll out and pull arms back
  roller_left.move(-127);
  roller_right.move(127);
  arm_l.move(-127);
  arm_r.move(-127);
  pros::delay(800);
  roller_left.move(0);
  roller_right.move(0);
  arm_r.move(0);
  arm_l.move(0);
//move back
  dt.moveDistance(-10_in);
}
