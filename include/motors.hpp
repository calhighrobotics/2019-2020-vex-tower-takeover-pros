#ifndef MOTORS_HPP
#define MOTORS_HPP
#include "main.hpp"

#define PUSH 18
#define L_DR 13
#define R_DR 20
#define L_ROLL 3
#define R_ROLL 8
#define L_ARM 12
#define R_ARM 19

#define MAX_MOTOR_VOLTAGE 12000
#define MAX_MOTOR_POWER 127

extern pros::Motor push;
extern pros::Motor dr_l;
extern pros::Motor dr_r;
extern pros::Motor roller_left;
extern pros::Motor roller_right;
extern pros::Motor arm_l;
extern pros::Motor arm_r;

#endif // MOTORS_HPP
