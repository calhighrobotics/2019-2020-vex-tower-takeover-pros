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
  pros::delay(600);
  arm_r.move(0);
  arm_l.move(0);
//run rollers
  roller_left.move(600);
  roller_right.move(600);
//moving
dt.setMaxVelocity(45);
  dt.moveDistanceAsync(48_in);
  dt.waitUntilSettled();
//stop rollers
  roller_left.move(0);
  roller_right.move(0);
  // pros::delay(200);
//move back and speed up
  dt.setMaxVelocity(170);
  dt.moveDistanceAsync(-24_in);
  dt.waitUntilSettled();
  pros::delay(150);
//turn
  dt.turnAngleAsync(-110_deg);
  dt.waitUntilSettled();
//move forward to goal
dt.setMaxVelocity(180);
  dt.moveDistanceAsync(20_in);
  dt.waitUntilSettled();
//spit out cubes just a little
  roller_left.move_velocity(-200);
  roller_right.move_velocity(200);
  pros::delay(200);
  roller_left.move_velocity(0);
  roller_right.move_velocity(0);
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
  dt.moveDistance(-10_in);
}
