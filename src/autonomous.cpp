#include "main.hpp"
#include "motors.hpp"

void autonomous() {
  dr_l.move(127);
  dr_r.move(127);
  //wait 1 second
  pros::delay(500);
  //stop motors
  dr_l.move(0);
  dr_r.move(0);
  //wait 1/2 second
  pros::delay(500);
  //go backwards
  dr_l.move(-127);
  dr_r.move(-127);
  //we like to move it move it
  pros::delay(700);
  //STOP!
  dr_l.move(0);
  dr_r.move(0);
  //get ready for driver control
  arm_l.move(127);
  arm_r.move(127);
  //wait 1 second
  pros::delay(1000);
  //stop motors
  arm_l.move(0);
  arm_r.move(0);
}
