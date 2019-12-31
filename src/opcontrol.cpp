#include "main.hpp"
#include "motors.hpp"
#include "sensors.hpp"
#include <tr1/math.h>

void opcontrol() {
  pros::Controller master(CONTROLLER_MASTER);

  while (true) {

    //driving
    dr_l.move(master.get_analog(ANALOG_LEFT_Y) * 5);
    dr_r.move(master.get_analog(ANALOG_LEFT_Y) * 5);

    //arms
    arm_l.move((master.get_analog(ANALOG_RIGHT_Y) * 8)/10);
    arm_r.move((master.get_analog(ANALOG_RIGHT_Y) * 8)/10);

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
      push.move_velocity(100);
    } else if (master.get_digital(DIGITAL_L2)) {
      push.move_velocity(-100);
    } else {
      push.move_velocity(0);
    }

    //rollers
    if(master.get_digital(DIGITAL_A)){// spin in
      roller_left.move_velocity(200);
      roller_right.move_velocity(200);
    } else if(master.get_digital(DIGITAL_B)){ // spin out
      roller_left.move((3 * -127)/4);
      roller_right.move((3 * -127)/4);
    } else { // STOP! in the name of the law!
      roller_right.move(0);
      roller_left.move(0);
    }
  //run rollers
    roller_left.move_velocity(600);
    roller_right.move_velocity(600);
  //moving
    dt.moveDistanceAsync(46_in);
    dt.waitUntilSettled();
    pros::delay(400);
  //stop rollers
    roller_left.move(0);
    roller_right.move(0);
  //move back and speed up
    dt.setMaxVelocity(180);
    dt.moveDistanceAsync(-20_in);
    dt.waitUntilSettled();
  //turn
    dt.turnAngleAsync(-103_deg);
    dt.waitUntilSettled();
  //move forward to goal
    dt.moveDistance(22_in);
    dt.waitUntilSettled();
  //push up
    push.move(127);
    pros::delay(2725);
    push.move(0);
  //roll out and pull arms back
    roller_left.move(-127);
    roller_right.move(127);
    arm_r.move(-127);
    arm_l.move(-127);
    pros::delay(800);
    roller_left.move(0);
    roller_right.move(0);
    arm_r.move(0);
    arm_l.move(0);
  //move back
    dt.moveDistance(-3_in);
}
