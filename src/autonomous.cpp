//SMALL BLUE GOAL

#include "main.hpp"
#include "motors.hpp"
#include "okapi/api.hpp"

using namespace okapi;

void autonomous(){
  //local declaration of drive train
  auto drive = ChassisControllerBuilder()
      .withMotors(L_DR, R_DR)
      // Green gearset, 4 in wheel diam, 11.5 in wheel track
      .withDimensions(AbstractMotor::gearset::green, {{4_in, 15.9375_in}, imev5GreenTPR})
      .build();
  drive->setMaxVelocity(40);
  drive->moveDistance(12_in);
  drive->waitUntilSettled();
  drive->moveDistance(-6_in);
  //bring out arms
  arm_l.move(127);
  arm_r.move(127);
  pros::delay(1200);
  arm_r.move(0);
  arm_l.move(0);
}
