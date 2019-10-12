#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

/**
 * the autonomous should do the following:
 * 1. lift up to full then back down
 * 2. arms drop
*/


void autonomous() {
  pros::Motor dr_l(13, true); //REVERSED
  pros::Motor dr_r(20);
	pros::Motor drop_r (18);
	pros::Motor drop_l (1);

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
