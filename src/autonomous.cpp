#include "main.hpp"
#include "motors.hpp"
#include "sensors.hpp"
#include "okapi/api.hpp"

using namespace okapi;

void autonomous() {
  //local declaration of drive train
  auto dt = ChassisControllerFactory::create(
    -L_DR, R_DR,
    AbstractMotor::gearset::green,
    {4_in, 16_in}
  );

  // auto rollers = AsyncControllerFactory::velPID(L_ROLL, -R_ROLL, 0.001, 0.0001);
  // rollers.setTarget(200);
  // rollers.setTarget(0);

  //get ready for driver control
  arm_l.move(127);
  arm_r.move(127);
  //wait 1 second
  pros::delay(1000);
  //stop motors
  arm_l.move(0);
  arm_r.move(0);
  //moving 50_in
  dt.moveDistanceAsync(50_in);
  roller_left.move(200);
  roller_right.move(200);
  dt.waitUntilSettled();
  //turn around
  dt.turnAngleAsync(180_deg);
  dt.waitUntilSettled();
  roller_left.move(0);
  roller_right.move(0);

  //move forward 29.5_in
  dt.moveDistance(29.5_in);
  dt.waitUntilSettled();
  //turn left 90º
  dt.turnAngle(45_deg);
  dt.waitUntilSettled();
  //move forward 19_in
  dt.moveDistance(19_in);
}
