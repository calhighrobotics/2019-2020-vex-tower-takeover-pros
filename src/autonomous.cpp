#include "main.hpp"
#include "motors.hpp"
#include "okapi/api.hpp"

using namespace okapi;

auto dt = ChassisControllerFactory::create(
  L_DR, R_DR,
  AbstractMotor::gearset::green,
  {4_in, 15.9375_in}
);

const double rollkP = 0.001;
const double rollkI = 0.0001;
const double rollkD = 0.0001;

auto left_arm = AsyncControllerFactory::posIntegrated(L_ARM);
auto right_arm = AsyncControllerFactory::posIntegrated(R_ARM);

void autonomous() {
  // arm_l.move(127);
  // arm_r.move(127);
  // //wait
  // pros::delay(1000);
  // //stop motors
  // arm_l.move(0);
  // arm_r.move(0);

  left_arm.setTarget(300);
  right_arm.setTarget(300);
  dt.moveDistanceAsync(42.9_in);
  roller_left.move(127);
  roller_right.move(127);
  dt.waitUntilSettled();
  //turn left 90º
  dt.turnAngleAsync(90_deg);
  dt.waitUntilSettled();
  roller_left.move(0);
  roller_right.move(0);
  //move forward 19.4_in
  dt.moveDistance(19.4_in);
  dt.waitUntilSettled();
  //turn left 90º
  dt.turnAngle(90_deg);
  dt.waitUntilSettled();
  //move forward 30.7_in
  dt.moveDistance(30.7_in);
}
