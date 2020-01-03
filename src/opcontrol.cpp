#include "main.hpp"
#include "motors.hpp"
#include "sensors.hpp"
#include <tr1/math.h>

void opcontrol() {
  pros::Controller master(CONTROLLER_MASTER);

  while (true) {

    //driving
    if(abs(master.get_analog(ANALOG_LEFT_Y)) > 10){
      dr_l.move(master.get_analog(ANALOG_LEFT_Y) * 5);
      dr_r.move(master.get_analog(ANALOG_LEFT_Y) * 5);
    } else if(master.get_digital(DIGITAL_L1)){
      dr_r.move_velocity(600);
      dr_l.move_velocity(-600);
    } else if (master.get_digital(DIGITAL_R1)){
      dr_l.move_velocity(600);
      dr_r.move_velocity(-600);
    } else {
      dr_r.move(0);
      dr_l.move(0);
    }

    //arms
    arm_l.move((master.get_analog(ANALOG_RIGHT_Y) * 8)/10);
    arm_r.move((master.get_analog(ANALOG_RIGHT_Y) * 8)/10);

    //pushing mechanism
    if (master.get_digital(DIGITAL_R2)) {
      push.move(127);
    } else if (master.get_digital(DIGITAL_L2)) {
      push.move(-127);
    } else {
      push.move_velocity(0);
    }

    //rollers
    if(master.get_digital(DIGITAL_A)){// spin in
      roller_left.move(127);
      roller_right.move(127);
    } else if(master.get_digital(DIGITAL_B)){ // spin out
      roller_left.move((3 * -127)/4);
      roller_right.move((3 * -127)/4);
    } else { // STOP! in the name of the law!
      roller_right.move(0);
      roller_left.move(0);
    }
  }
}
