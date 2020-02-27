#include "main.hpp"
#include "motors.hpp"
#include "okapi/api.hpp"

using namespace okapi;

void arms_out(){
  arm_l.move(127);
  arm_r.move(127);
  pros::delay(1200);
  arm_r.move(0);
  arm_l.move(0);
  pros::delay(200);
}

void autonomous(){
  //local declaration of drive train
  auto drive = ChassisControllerBuilder()
      .withMotors(L_DR, R_DR)
      // Green gearset, 4 in wheel diam, 11.5 in wheel track
      .withDimensions(AbstractMotor::gearset::green, {{4_in, 16_in}, imev5GreenTPR})
      .build();

  // bring out arms
  arms_out();
  // run rollers
  roller_left.move(127);
  roller_right.move(127);
  //drive forward and pick up line of 4 + one on middle line
  drive->setMaxVelocity(100);
  drive->moveDistance(50_in);
  drive->waitUntilSettled();
  //drive backwards and then turn + pick up cube by tower
  drive->moveDistance(-5_in);
  drive->waitUntilSettled();
  drive->turnAngle(45_deg);
  drive->waitUntilSettled();
  drive->moveDistance(5_in);
  drive->waitUntilSettled();
  //turn around all the way and drive to goal
  drive->turnAngle(180_deg);
  drive->moveDistance(63_in);
  drive->waitUntilSettled();
  //push forward
  push.move_voltage(MAX_MOTOR_VOLTAGE);
  pros::delay(4000);
  push.move(0);
  pros::delay(100);
  //roll out and drive backwards out of goal
  roller_left.move_velocity(-200);
  roller_right.move_velocity(200);
  drive->moveDistanceAsync(-10_in);

}




// //SMALL REd GOAL
//
// #include "main.hpp"
// #include "motors.hpp"
// #include "okapi/api.hpp"
//
// using namespace okapi;
//
// /*
// figure out how to change motor unit to degree + calculate motor rotations to get to the right spot for the arms. that should make the arms go to the right spot every time; call with this position as a param.
// */
//
// void arms_move(const double position, const int32_t velocity){
//   int goal_position = position + arm_l.get_position();
//   arm_l.move_relative(100, velocity);
//   arm_r.move_relative(100, velocity);
//   while (abs(goal_position - arm_l.get_position()) > 5){
//     pros::delay(2);
//   }
//
//
// // void autonomous(){ //SMALL RED GOAL
// //local declaration of drive train
// auto drive = ChassisControllerBuilder()
//     .withMotors(L_DR, R_DR)
//     // Green gearset, 4 in wheel diam, 11.5 in wheel track
//     .withDimensions(AbstractMotor::gearset::green, {{4_in, 15.9375_in}, imev5GreenTPR})
//     .build();
// //bring out arms
//   arm_l.move(127);
//   arm_r.move(127);
//   pros::delay(1200);
//   arm_r.move(0);
//   arm_l.move(0);
//   pros::delay(200);
// //run rollers
//   roller_left.move(127);
//   roller_right.move(127);
// //moving
//   drive->setMaxVelocity(95);
//   drive->moveDistanceAsync(45_in);
//   drive->waitUntilSettled();
// //stop rollers
//   pros::delay(50);
//   roller_left.move(0);
//   roller_right.move(0);
// //move back and speed up
//   drive->setMaxVelocity(175);
//   drive->moveDistanceAsync(-26_in);
//   drive->waitUntilSettled();
//   pros::delay(150);
// //turn
//   drive->turnAngleAsync(97_deg); // RED
//   drive->waitUntilSettled();
// //move forward to goal
// drive->setMaxVelocity(200);
//   drive->moveDistanceAsync(9_in);
//   drive->waitUntilSettled();
//   roller_left.move(-200);
//   roller_right.move(-200);
//   pros::delay(200);
//   roller_left.move(0);
//   roller_right.move(0);
// //push up
//   push.move(6000);
//   pros::delay(4000);
//   push.move(0);
//   pros::delay(100);
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
