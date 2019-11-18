#include "main.h"
#include "motors.h"
#include "okapi/api.hpp"

using namespace okapi;

const double rollkP = 0.001;
const double rollkI = 0.0001;
const double rollkD = 0.0001;

auto dt = ChassisControllerFactory::create(
  L_DR, R_DR,
  AbstractMotor::gearset::green,
  {4_in, 15.9375_in}
);

auto roller_l = AsyncControllerFactory::posPID(L_ROLL, rollkP, rollkI, rollkD);
auto roller_r = AsyncControllerFactory::posPID(R_ROLL, rollkP, rollkI, rollkD);


void autonomous() {
  //Algorithm :
  //move forward 42.9_in
  // dt.moveDistanceAsync(42.9_in);
  // roller_l.setTarget(300);
  // roller_r.setTarget(300);
  // dt.waitUntilSettled();
  // //turn left 90º
  // dt.turnAngle(90_deg);
  // //move forward 19.4_in
  // dt.moveDistance(19.4_in);
  // //turn left 90º
  // dt.turnAngle(90_deg);
  // //move forward 30.7_in
  // dt.moveDistance(30.7_in);
}
