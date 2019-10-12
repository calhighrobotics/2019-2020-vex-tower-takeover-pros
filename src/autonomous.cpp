#include "main.h"
#include "motors.h"

/*
 * The autonomous should do the following:
 * 1. Lift up to full then back down.
 * 2. Drop arms.
*/

void autonomous() {
  while (!((dr_l.get_position() < 105) && (dr_l.get_position() > 95))) {
    // Continue running this loop as long as the motor is not within +-5 units of its goal
    dr_l.move_relative(1500, 200); // Moves 10 rotations forward
    pros::delay(2);
  }
  dr_r.move_relative(1500, 200); // Moves 10 rotations forward
  while (!((dr_r.get_position() < 105) && (dr_r.get_position() > 95))) {
    // Continue running this loop as long as the motor is not within +-5 units of its goal
    pros::delay(2);
  }
  drop_r.move_relative(100, 200);
  while (!((drop_r.get_position() < 105) && (drop_r.get_position() > 95))) {
    // Continue running this loop as long as the motor is not within +-5 units of its goal
    pros::delay(2);
  }
  drop_l.move_relative(100, -200);
  while (!((drop_l.get_position() < 105) && (drop_l.get_position() > 95))) {
    // Continue running this loop as long as the motor is not within +-5 units of its goal
    pros::delay(2);
  }
}
