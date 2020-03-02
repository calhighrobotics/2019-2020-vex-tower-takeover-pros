//SMALL REd GOAL

#include "main.hpp"
#include "motors.hpp"
#include "okapi/api.hpp"

using namespace okapi;

/*
figure out how to change motor unit to degree + calculate motor rotations to get to the right spot for the arms. that should make the arms go to the right spot every time; call with this position as a param.
*/

void arms_move(const double position, const int32_t velocity){
  int goal_position = position + arm_l.get_position();
  arm_l.move_relative(100, velocity);
  arm_r.move_relative(100, velocity);
  while (abs(goal_position - arm_l.get_position()) > 5){
    pros::delay(2);
  }
}

void autonomous(){ //SMALL RED GOAL
//local declaration of drive train
auto drive = ChassisControllerBuilder()
    .withMotors(L_DR, R_DR)
    // Green gearset, 4 in wheel diam, 11.5 in wheel track
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 15.9375_in}, imev5GreenTPR})
    .build();
//bring out arms
  arm_l.move(110);
  arm_r.move(110);
  pros::delay(1000);
  arm_r.move(0);
  arm_l.move(0);
  pros::delay(200);
//run rollers
  roller_left.move(127);
  roller_right.move(127);
//moving
  pros::delay(170);
  drive->setMaxVelocity(95);
  drive->moveDistanceAsync(60_in);
  drive->waitUntilSettled();
//stop rollers
  pros::delay(50);
  roller_left.move(0);
  roller_right.move(0);
//move back and speed up
  drive->setMaxVelocity(175);
  drive->moveDistanceAsync(-26_in);
  drive->waitUntilSettled();
  pros::delay(50);
//turn
  drive->turnAngleAsync(188_deg); // RED
  drive->waitUntilSettled();
//move forward to goal
 drive->setMaxVelocity(175);
  drive->moveDistanceAsync(22_in);
  drive->waitUntilSettled();
  roller_left.move(-200);
  roller_right.move(-200);
  pros::delay(150);
  roller_left.move(0);
  roller_right.move(0);
//push up
  push.move(6000);
  pros::delay(3500);
  push.move(0);
  pros::delay(100);
  roller_left.move_velocity(200); //roll out while going up
  roller_right.move_velocity(200);
  pros::delay(200);
//roll out and pull arms back
  roller_left.move_velocity(-180);
  roller_right.move_velocity(-180);
  arm_l.move_velocity(-117);
  arm_r.move_velocity(-117);
  pros::delay(600);
  roller_left.move_velocity(200);
  roller_right.move_velocity(200);
  pros::delay(600);
  drive->moveDistanceAsync(-6_in);
  pros::delay(100);
  roller_left.move(0);
  roller_right.move(0);
  arm_r.move(0);
  arm_l.move(0);
//move back
  drive->moveDistance(-15_in);
}
