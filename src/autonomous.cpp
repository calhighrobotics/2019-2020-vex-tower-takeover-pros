#include "main.hpp"
#include "motors.hpp"
#include "okapi/api.hpp"

#define LEFT_LIM 'g'
#define RIGHT_LIM 'h'

using namespace okapi;

void autonomous() {
  //local declaration of drive train
  auto dt = ChassisControllerFactory::create(
    -L_DR, R_DR, //left motor is reversed
    AbstractMotor::gearset::green,
    {4_in, 15.9375_in}
  );

  ADIButton left_lim(LEFT_LIM);
  ADIButton right_lim(LEFT_LIM);

  dt.setMaxVelocity(80);
  //bring out arms

  while(!right_lim.isPressed()){
    arm_l.move(127);
    arm_r.move(127);
  }
    //wait
    pros::delay(800);
  //run rollers
    roller_left.move_velocity(600); // we'll be able to pick up more cubes once speed carts come in
    roller_right.move_velocity(600);
  // allow preload to enter
      pros::delay(450);
  //moving
    dt.moveDistanceAsync(45_in);
    dt.waitUntilSettled();
  //stop rollers
    roller_left.move(0);
    roller_right.move(0);
  //move back and speed up
    dt.setMaxVelocity(175);
    dt.moveDistanceAsync(-20_in);
    dt.waitUntilSettled();
  //turn
    dt.turnAngleAsync(-110_deg);
    dt.waitUntilSettled();
  //move forward to goal
    dt.moveDistance(20_in);
    dt.waitUntilSettled();
  //push up
    push.move(127);
    pros::delay(2600);
    push.move(0);
  //roll out and pull arms back
    roller_left.move(-127);
    roller_right.move(127);
    arm_r.move(-127);
    arm_l.move(-127);
    pros::delay(1000);
    roller_left.move(0);
    roller_right.move(0);
    arm_r.move(0);
    arm_l.move(0);
}
