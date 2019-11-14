#include "main.h"
#include "motors.h"
#include <tr1/math.h>

void opcontrol() {
  pros::Controller master(CONTROLLER_MASTER);

  while (true) {

    double theta = atan2(master.get_analog(ANALOG_LEFT_Y) , master.get_analog(ANALOG_LEFT_X));

    if(master.get_analog(ANALOG_LEFT_Y) < 0 || master.get_analog(ANALOG_LEFT_X) < 0){
      theta += M_PI;
    }

    theta *= 180/(M_PI);

    if(theta >= 85 && theta <= 95){
      // forwards as given by y
      dr_l.move_velocity(master.get_analog(ANALOG_LEFT_Y)*5);
      dr_r.move_velocity(master.get_analog(ANALOG_LEFT_Y)*5);
    } else if (theta >= 265 && theta <= 275){
      //backwards as given by y
      dr_l.move_velocity(master.get_analog(ANALOG_LEFT_Y)*5);
      dr_r.move_velocity(master.get_analog(ANALOG_LEFT_Y)*5);
    } else if ((theta <= 5 && theta > 0) || (theta >= 355 && theta < 360)){
      //pivot right
      dr_l.move_velocity(200);
      dr_r.move_velocity(-200);
    } else if (theta >= 175 && theta <= 180){
      //pivot left
      dr_l.move_velocity(-200);
      dr_r.move_velocity(200);
    }

    //arms
    arm_l.move(master.get_analog(ANALOG_RIGHT_Y));
    arm_r.move(master.get_analog(ANALOG_RIGHT_Y));

    //point turn algo
    // if (master.get_digital(DIGITAL_R1)) {
    //   dr_l.move_velocity(200);
    //   dr_r.move_velocity(-200);
    // } else if (master.get_digital(DIGITAL_L1)) {
    //   dr_l.move_velocity(-200);
    //   dr_r.move_velocity(200);
    // }

    //pushing mechanism
    if (master.get_digital(DIGITAL_L1)) {
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

    if(master.get_digital(DIGITAL_DOWN)){
      pros::lcd::set_text(2, std::to_string(push.get_position()));
    }

    pros::delay(20);
  }
}
