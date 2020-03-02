#include "motors.hpp"



pros::Motor push(PUSH);
pros::Motor dr_l(abs(L_DR), /* reversed */ true);
pros::Motor dr_r(R_DR);
pros::Motor roller_left(L_ROLL);
pros::Motor roller_right(abs(R_ROLL), /* reversed */ true);
pros::Motor arm_l(L_ARM, /* reversed*/ true);
pros::Motor arm_r(R_ARM);
