#ifndef MOTORS_H
#define MOTORS_H
#include "main.h"

#define PUSH 18
#define L_DR 13
#define R_DR 20
#define L_ROLL 12
#define R_ROLL 21
#define L_ARM 11
#define R_ARM 19

extern pros::Motor push;
extern pros::Motor dr_l;
extern pros::Motor dr_r;
extern pros::Motor roll_l;
extern pros::Motor roll_r;
extern pros::Motor arm_l;
extern pros::Motor arm_r;

#endif // MOTORS_H
