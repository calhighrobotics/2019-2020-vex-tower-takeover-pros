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
    if (master.get_digital(DIGITAL_L2)) {
      arm_l.move_velocity(200);
      arm_r.move_velocity(200);
    } else if (master.get_digital(DIGITAL_L1)) {
      arm_l.move_velocity(-200);
      arm_r.move_velocity(-200);
    } else {
      arm_l.move(0);
      arm_r.move(0);
    }

    //point turn algo
    if (master.get_analog(ANALOG_RIGHT_X) > 0) {
      dr_l.move_velocity(200);
      dr_r.move_velocity(-200);
    } else if (master.get_analog(ANALOG_RIGHT_X) < 0) {
      dr_l.move_velocity(-200);
      dr_r.move_velocity(200);
    }

    //pushing mechanism
    if (master.get_digital(DIGITAL_X)) {
      push.move_velocity(150);
    } else if (master.get_digital(DIGITAL_B)) {
      push.move_velocity(-150);
    } else {
      push.move_velocity(0);
    }

    //rollers
    if(master.get_digital(DIGITAL_R1)){ // spin in
      roller_left.move_velocity(600);
      roller_right.move_velocity(600);
    } else if(master.get_digital(DIGITAL_R2)){ // spin out
      roller_left.move_velocity(-450);
      roller_right.move_velocity(-450);
    } else {
      roller_right.move(0);
      roller_left.move(0);
    }

    pros::delay(20);
  }
}
