#include "main.hpp"
#include "motors.hpp"
#include <tr1/math.h>

void opcontrol() {
  pros::Controller master(CONTROLLER_MASTER);

  while (true) {

    //driving
    dr_l.move(master.get_analog(ANALOG_LEFT_Y) * 5);
    dr_r.move(master.get_analog(ANALOG_LEFT_Y) * 5);

    //arms
    arm_l.move(master.get_analog(ANALOG_RIGHT_Y));
    arm_r.move(master.get_analog(ANALOG_RIGHT_Y));

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
      push.move_velocity(150);
    } else if (master.get_digital(DIGITAL_L2)) {
      push.move_velocity(-150);
    } else {
      push.move_velocity(0);
    }

    //rollers
    if(master.get_digital(DIGITAL_A)){      // for some reason it only works when the
      right_roll.move(127 * 5);             //left and right are separated in different if statements
    } else if (master.get_digital(DIGITAL_B)){
      right_roll.move(-127 * 5);
    } else {
      right_roll.move(0);
    }

    if(master.get_digital(DIGITAL_A)){
      left_roll.move(127 * 5);
    } else if(master.get_digital(DIGITAL_B)){
      left_roll.move(-127 * 5);
    } else {
      left_roll.move(0);
    }

    pros::delay(20);
  }
}
