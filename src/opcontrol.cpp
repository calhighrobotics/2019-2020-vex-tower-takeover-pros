#include "main.hpp"
#include "motors.hpp"
#include "sensors.hpp"

pros::Controller master(CONTROLLER_MASTER);

void opcontrol(){
  bool slower = false;

  while (true) {

    if(master.get_digital(DIGITAL_RIGHT)){
      slower = !slower;
    }

    if(slower){
      //driving
      if(abs(master.get_analog(ANALOG_LEFT_Y)) > 10){
        dr_l.move(master.get_analog(ANALOG_LEFT_Y) * 5 * 0.5);
        dr_r.move(master.get_analog(ANALOG_LEFT_Y) * 5 * 0.5);
      } else if(master.get_digital(DIGITAL_L1)){
        dr_r.move_voltage(MAX_MOTOR_VOLTAGE * 0.5);
        dr_l.move(-MAX_MOTOR_VOLTAGE * 0.5);
      } else if (master.get_digital(DIGITAL_R1)){
        dr_l.move(127 * 0.5);
        dr_r.move(-127 * 0.5);
      } else {
        dr_r.move(0);
        dr_l.move(0);
      }

      //arms
      arm_l.move((master.get_analog(ANALOG_RIGHT_Y) * 8)/10 * 0.5);
      arm_r.move((master.get_analog(ANALOG_RIGHT_Y) * 8)/10 * 0.5);

      //pushing mechanism
      if (master.get_digital(DIGITAL_R2)) {
        push.move(80 * 0.5);
      } else if (master.get_digital(DIGITAL_L2)) {
        push.move(-100 * 0.5);
      } else {
        push.move_velocity(0);
      }

      //rollers
      if(master.get_digital(DIGITAL_A)){// spin in
        roller_left.move(127 * 0.5);
        roller_right.move(127 * 0.5);
      } else if(master.get_digital(DIGITAL_B)){ // spin out
        roller_left.move((3 * -127)/4 * 0.5);
        roller_right.move((3 * -127)/4 * 0.5);
      } else { // STOP! in the name of the law!
        roller_right.move(0);
        roller_left.move(0);
      }

// ----------------------------------------------------------------------------------

    } else {
      //driving
      if(abs(master.get_analog(ANALOG_LEFT_Y)) > 10){
        dr_l.move(master.get_analog(ANALOG_LEFT_Y) * 5);
        dr_r.move(master.get_analog(ANALOG_LEFT_Y) * 5);
      } else if(master.get_digital(DIGITAL_L1)){
        dr_r.move_voltage(MAX_MOTOR_VOLTAGE);
        dr_l.move(-MAX_MOTOR_VOLTAGE);
      } else if (master.get_digital(DIGITAL_R1)){
        dr_l.move(127);
        dr_r.move(-127);
      } else {
        dr_r.move(0);
        dr_l.move(0);
      }

      //arms
      arm_l.move((master.get_analog(ANALOG_RIGHT_Y) * 8)/10);
      arm_r.move((master.get_analog(ANALOG_RIGHT_Y) * 8)/10);

      //pushing mechanism
      if (master.get_digital(DIGITAL_R2)) {
        push.move(80);
      } else if (master.get_digital(DIGITAL_L2)) {
        push.move(-100);
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
    pros::delay(20);
  }
}
