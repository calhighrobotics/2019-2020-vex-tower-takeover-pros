#include "main.hpp"
// #include "motors.hpp"
#include <tr1/math.h>

#define PUSH 18
#define L_DR 13
#define R_DR 20
#define L_ROLL 1
#define R_ROLL 8
#define L_ARM 11
#define R_ARM 19

extern pros::Motor push;
extern pros::Motor dr_l;
extern pros::Motor dr_r;
extern pros::Motor roller_left;
extern pros::Motor roller_right;
extern pros::Motor arm_l;
extern pros::Motor arm_r;

void opcontrol() {
  pros::Controller master(CONTROLLER_MASTER);

  pros::Motor push(PUSH);
  pros::Motor dr_l(L_DR, /* reversed */ true);
  pros::Motor dr_r(R_DR);
  pros::Motor roller_left(L_ROLL);
  pros::Motor roller_right(R_ROLL, /* reversed */ true);
  pros::Motor arm_l(L_ARM);
  pros::Motor arm_r(R_ARM, /* reversed */ true);

  while (true) {

    //driving
    dr_l.move(master.get_analog(ANALOG_LEFT_Y) * 5);
    dr_r.move(master.get_analog(ANALOG_LEFT_Y) * 5);

    //armsn
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
      roller_right.move(127);
      roller_left.move(127);
    } else if(master.get_digital(DIGITAL_B)){
      roller_left.move(-127);
      roller_right.move(-127);
    } else {
      roller_left.move_velocity(0);
      roller_right.move_velocity(0);
    }

    pros::delay(20);
  }
}
