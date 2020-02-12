#include "main.hpp"
#include "motors.hpp"
#include "sensors.hpp"

pros::Controller master(CONTROLLER_MASTER);

bool slower = false;

void opcontrol(){
  while (true) {
      //driving
      if(abs(master.get_analog(ANALOG_LEFT_Y)) > 10){
        dr_l.move(master.get_analog(ANALOG_LEFT_Y) * 5);
        dr_r.move(master.get_analog(ANALOG_LEFT_Y) * 5);
      } else if(master.get_digital(DIGITAL_L1)){
        dr_r.move_voltage(MAX_MOTOR_VOLTAGE);
        dr_l.move_voltage(-MAX_MOTOR_VOLTAGE);
      } else if (master.get_digital(DIGITAL_R1)){
        dr_l.move_voltage(MAX_MOTOR_VOLTAGE);
        dr_r.move_voltage(-MAX_MOTOR_VOLTAGE);
      } else {
        dr_r.move(0);
        dr_l.move(0);
      }

      //arms
      arm_l.move((master.get_analog(ANALOG_RIGHT_Y) * 8)/10);
      arm_r.move((master.get_analog(ANALOG_RIGHT_Y) * 8)/10);

      //pushing mechanism
      if (master.get_digital(DIGITAL_R2)) { //down
        push.move_voltage(MAX_MOTOR_VOLTAGE);
      } else if (master.get_digital(DIGITAL_L2)) { //up
        push.move(-MAX_MOTOR_VOLTAGE);
      } else {
        push.move_velocity(0);
      }

      //rollers
      if(master.get_digital(DIGITAL_A)){// spin in
        roller_left.move(MAX_MOTOR_POWER);
        roller_right.move(MAX_MOTOR_POWER);
      } else if(master.get_digital(DIGITAL_B)){ // spin out
        roller_left.move((3 * -MAX_MOTOR_POWER)/4);
        roller_right.move((3 * -MAX_MOTOR_POWER)/4);
      } else { // STOP! in the name of the law!
        roller_right.move(0);
        roller_left.move(0);
      }
    }
    pros::delay(20);
  }
