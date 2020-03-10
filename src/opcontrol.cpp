#include "main.hpp"
#include "motors.hpp"
#include "sensors.hpp"

pros::Controller master(CONTROLLER_MASTER);

void opcontrol()
{

  while (true)
  {
    //driving
    if (abs(master.get_analog(ANALOG_LEFT_Y)) > 10)
    {
      dr_l.move(master.get_analog(ANALOG_LEFT_Y));
      dr_r.move(master.get_analog(ANALOG_LEFT_Y));
    }
    else if (master.get_digital(DIGITAL_L1))
    {
      dr_r.move_voltage(MAX_MOTOR_VOLTAGE);
      dr_l.move_voltage(-MAX_MOTOR_VOLTAGE);
    }
    else if (master.get_digital(DIGITAL_R1))
    {
      dr_l.move_voltage(MAX_MOTOR_VOLTAGE);
      dr_r.move_voltage(-MAX_MOTOR_VOLTAGE);
    }
    else
    {
      dr_r.move(0);
      dr_l.move(0);
    } 

    arm_r.move(master.get_analog(ANALOG_RIGHT_Y));
    arm_l.move(master.get_analog(ANALOG_RIGHT_Y));

    if (master.get_digital(DIGITAL_R2))
    { //down
      push.move_voltage(MAX_MOTOR_VOLTAGE);
    }
    else if (master.get_digital(DIGITAL_L2))
    { //up
      push.move_voltage((-MAX_MOTOR_VOLTAGE * 8) / 10);
    }
    else
    {
      push.move(0);
    }

    //rollers

    if (master.get_digital(DIGITAL_A))
    { // spin in
      roller_left.move(MAX_MOTOR_POWER);
      roller_right.move(MAX_MOTOR_POWER);
    }
    else if (master.get_digital(DIGITAL_B))
    { // spin out
      roller_left.move((3 * -MAX_MOTOR_POWER) / 4);
      roller_right.move((3 * -MAX_MOTOR_POWER) / 4);
    }
    else if (master.get_digital(DIGITAL_X)){
      // spin in
      roller_left.move((3*MAX_MOTOR_POWER) / 5);
      roller_right.move((3*MAX_MOTOR_POWER) / 5);
    }
    else if (master.get_digital(DIGITAL_Y))
    { // spin out
      roller_left.move((9 * -MAX_MOTOR_POWER) / 16);
      roller_right.move((9 * -MAX_MOTOR_POWER) / 16);
    }
    else
    {
      roller_right.move(0);
      roller_left.move(0);
    }

    if (master.get_digital(DIGITAL_DOWN))
    {
      std::cout << "Motor Position: " << arm_l.get_position();
    }
  }
  pros::delay(20);
}
