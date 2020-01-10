#include "main.hpp"
#include "motors.hpp"
#include "okapi/api.hpp"

using namespace okapi;

void autonomous() {
//local declaration of drive train
auto drive = ChassisControllerBuilder()
    .withMotors(L_DR, R_DR)
    // Green gearset, 4 in wheel diam, 15.9375 in in wheel track
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
drive->moveDistanceAsync(45_in);
drive->waitUntilSettled();
// moving around cube
drive->setMaxVelocity(55);
// moving
drive->moveDistanceAsync(70_in);
drive->waitUntilSettled();
//stop rollers
pros::delay(200);
roller_left.move(0);
roller_right.move(0);
//move back and speed up
drive->setMaxVelocity(170);
drive->moveDistanceAsync(-26_in);
drive->waitUntilSettled();
pros::delay(150);
//turn
drive->turnAngleAsync(-35_deg); // SKILLS
// drive->turnAngleAsync(107_deg); // RED
// drive->turnAngleAsync(-107_deg); // BLUE
drive->waitUntilSettled();
//move forward to goal
drive->setMaxVelocity(180);
drive->moveDistanceAsync(20_in);
drive->setMaxVelocity(80);
drive->setMaxVelocity(180);
drive->moveDistanceAsync(3_in);
drive->waitUntilSettled();
//push up
push.move(90);
pros::delay(2100);
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
