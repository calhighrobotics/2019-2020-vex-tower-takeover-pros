#ifndef MOTORS_HPP
#define MOTORS_HPP
#include "main.hpp"

#define PUSH 18
#define L_DR 13
#define R_DR 20
#define R_ROLL 8
#define L_ARM 11
#define R_ARM 19
#define L_ROLL 3

extern pros::Motor push;
extern pros::Motor dr_l;
extern pros::Motor dr_r;
extern pros::Motor roller_left;
extern pros::Motor roller_right;
extern pros::Motor arm_l;
extern pros::Motor arm_r;

#endif // MOTORS_HPP
