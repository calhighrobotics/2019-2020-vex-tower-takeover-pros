#include "motors.hpp"

pros::Motor push(PUSH);
pros::Motor dr_l(L_DR, /* reversed */ true);
pros::Motor dr_r(R_DR);
pros::Motor left_roll(L_ROLL);
pros::Motor right_roll(R_ROLL, /* reversed */ true);
pros::Motor arm_l(L_ARM);
pros::Motor arm_r(R_ARM, /* reversed */ true);
