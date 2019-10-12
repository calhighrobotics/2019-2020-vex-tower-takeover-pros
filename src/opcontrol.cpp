#include "main.h"
#include "motors.h"

void opcontrol() {
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
