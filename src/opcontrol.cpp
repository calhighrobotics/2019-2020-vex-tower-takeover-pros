#include "main.hpp"
#include "motors.hpp"
#include "sensors.hpp"
#include "okapi/api.hpp"

using namespace okapi;

pros::Controller master(CONTROLLER_MASTER);

void opcontrol(){
  while (true) {
      //driving
      if(abs(master.get_analog(ANALOG_LEFT_Y)) > 10){
        dr_l.move_voltage(master.get_analog(ANALOG_LEFT_Y));
        dr_r.move_voltage(master.get_analog(ANALOG_LEFT_Y));
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

      push.move(master.get_analog(ANALOG_RIGHT_Y));

      if (master.get_digital(DIGITAL_R2)) { //down
        arm_l.move_voltage(MAX_MOTOR_VOLTAGE);
        arm_r.move_voltage(MAX_MOTOR_VOLTAGE);
      } else if (master.get_digital(DIGITAL_L2)) { //up
        arm_l.move_voltage((-MAX_MOTOR_VOLTAGE * 8) / 10);
        arm_r.move_voltage((-MAX_MOTOR_VOLTAGE * 8) / 10);
      } else {
        push.move(0);
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

      if(master.get_digital(DIGITAL_DOWN)){
          std::cout << "Motor Position: " << arm_l.get_position();
      }

    }
    pros::delay(20);
  }
