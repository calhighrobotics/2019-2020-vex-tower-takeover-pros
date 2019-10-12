#ifndef MOTORS_H
#define MOTORS_H
#include "main.h"

#define L_DR 13
#define R_DR 20
#define BELT 11
#define L_ROLL 14
#define R_ROLL 21
#define L_DROP 1
#define R_DROP 18
#define PUSH 17

extern pros::Motor dr_l;
extern pros::Motor dr_r;
extern pros::Motor belt;
extern pros::Motor roll_l;
extern pros::Motor roll_r;
extern pros::Motor drop_l;
extern pros::Motor drop_r;
extern pros::Motor push;

#endif // MOTORS_H
