#ifndef MOTORS_H
#define MOTORS_H
#include "main.hpp"

#define PUSH 18
#define L_DR 13
#define R_DR 20
#define L_ROLL 1
#define R_ROLL 10
#define L_ARM 11
#define R_ARM 19

extern pros::Motor push;
extern pros::Motor dr_l;
extern pros::Motor dr_r;
extern pros::Motor left_roll;
extern pros::Motor right_roll;
extern pros::Motor arm_l;
extern pros::Motor arm_r;

#endif // MOTORS_H
