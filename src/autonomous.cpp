#include "main.hpp"
#include "motors.hpp"
#include "sensors.hpp"
#include "okapi/api.hpp"

using namespace okapi;

void autonomous() {
  //local declaration of drive train
  auto dt = ChassisControllerFactory::create(
    -L_DR, R_DR, //left motor is reversed
    AbstractMotor::gearset::green,
    {4_in, 15.9375_in}
  );

  dt.setMaxVelocity(45);
  //bring out arms
    arm_l.move(127);
    arm_r.move(127);
    //wait 1 second
    pros::delay(1000);
    //stop motors
    arm_l.move(0);
    arm_r.move(0);
  //run rollers
    roller_left.move_velocity(600); // we'll be able to pick up more cubes once speed carts come in
    roller_right.move_velocity(600);
  //moving
    dt.moveDistanceAsync(45_in);
    dt.waitUntilSettled();
  //move back
    dt.moveDistanceAsync(-20_in);
    dt.waitUntilSettled();
  //turn
    dt.turnAngleAsync(-110_deg);
    dt.waitUntilSettled();
  //speed up
    dt.setMaxVelocity(150);
  //stop rollers
    roller_left.move(0);
    roller_right.move(0);
  //move forward to goal
    dt.moveDistance(20_in);
    dt.waitUntilSettled();
  //push up
}
