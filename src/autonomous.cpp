#include "main.hpp"
#include "motors.hpp"
#include "okapi/api.hpp"
#include "sensors.hpp"

using namespace okapi;

void autonomous() {
  //local declaration of drive train
  auto dt = ChassisControllerFactory::create(
    -L_DR, R_DR, //left motor is reversed
    AbstractMotor::gearset::green,
    {4_in, 15.9375_in}
  );

  dt.setMaxVelocity(45);

  pros::delay(25); // allow robot to settle
  //bring out arms
    while(right_lim.get_value() != true){
      arm_l.move(127);
      arm_r.move(127);
    }
  //run rollers
    roller_left.move_velocity(600);
    roller_right.move_velocity(600);
  //moving
    dt.moveDistanceAsync(46_in);
    dt.waitUntilSettled();
    pros::delay(400);
  //stop rollers
    roller_left.move(0);
    roller_right.move(0);
  //move back and speed up
    dt.setMaxVelocity(180);
    dt.moveDistanceAsync(-20_in);
    dt.waitUntilSettled();
  //turn
    dt.turnAngleAsync(-103_deg);
    dt.waitUntilSettled();
  //move forward to goal
    dt.moveDistance(22_in);
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
