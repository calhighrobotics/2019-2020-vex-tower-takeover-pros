#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
 #define L_DR 13
 #define R_DR 20
 #define BELT 11
 #define L_ROLL 14
 #define R_ROLL 21
 #define L_DROP 1
 #define R_DROP 18
 #define PUSH 17

void opcontrol() {
  pros::Motor dr_l(L_DR, true); //REVERSED
  pros::Motor dr_r(R_DR);
  pros::Motor belt(BELT);
  pros::Motor roll_l(R_ROLL);
  pros::Motor roll_r(L_ROLL);
  pros::Motor drop_l(L_DROP);
  pros::Motor drop_r(R_DROP);
  pros::Motor push(PUSH);

  pros::Controller master(CONTROLLER_MASTER);

  while (true) {
    dr_l.move_velocity(master.get_analog(ANALOG_LEFT_Y)*5);
    dr_r.move_velocity(master.get_analog(ANALOG_LEFT_Y)*5);

    belt.move(abs(master.get_analog(ANALOG_RIGHT_Y)));

    //point turn algo
    if (master.get_digital(DIGITAL_R1)) {
      dr_l.move_velocity(200);
      dr_r.move_velocity(-200);
    } else if (master.get_digital(DIGITAL_L1)) {
      dr_l.move_velocity(-200);
      dr_r.move_velocity(200);
    }

    //pushing mechanism
    if (master.get_digital(DIGITAL_R2)) {
      push.move_velocity(200);
    } else if (master.get_digital(DIGITAL_L2)) {
      push.move_velocity(-200);
    } else {
      push.move_velocity(0);
    }

    //rollers
    if(master.get_digital(DIGITAL_A)){
      roll_r.move(127);
      roll_l.move(-127);
    } else if(master.get_digital(DIGITAL_B)){
      roll_r.move(-127);
      roll_l.move(127);
    } else {
      roll_l.move(0);
      roll_r.move(0);
    }

    //droppers
    if(master.get_digital(DIGITAL_X)){
      drop_r.move(127);
      drop_l.move(-127);
    } else if(master.get_digital(DIGITAL_Y)){
      drop_r.move(-127);
      drop_l.move(127);
    } else {
      drop_r.move(0);
      drop_l.move(0);
    }

    pros::delay(20);

  }
}
