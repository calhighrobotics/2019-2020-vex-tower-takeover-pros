#include "main.hpp"
#include "motors.hpp"

void autonomous() {
  arm_l.move(127);
  arm_r.move(127);
  //wait 1 second
  pros::delay(1000);
  //stop motors
  arm_l.move(0);
  arm_r.move(0);
}
