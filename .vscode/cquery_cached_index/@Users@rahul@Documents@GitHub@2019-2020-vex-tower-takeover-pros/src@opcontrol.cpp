#include "main.h"
#include "motors.h"
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
    if(master.get_digital(DIGITAL_A)){
      roll_r.move(127);
      roll_l.move(127);
    } else if(master.get_digital(DIGITAL_B)){
      roll_r.move(-127);
      roll_l.move(-127);
    } else {
      roll_l.move_velocity(0);
      roll_r.move_velocity(0);
    }
    pros::delay(20);
  }
}
