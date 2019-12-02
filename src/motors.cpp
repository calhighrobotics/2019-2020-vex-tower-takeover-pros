#include "motors.hpp"

pros::Motor push(PUSH);
pros::Motor dr_l(abs(L_DR), /* reversed */ true); //for okapi to work, I need to set a negative port number. however v5 smart doesn't like negative port numbers therefore absolute value needed here.
pros::Motor dr_r(R_DR);
pros::Motor roller_left(L_ROLL);
pros::Motor roller_right(abs(R_ROLL), /* reversed */ true);
pros::Motor arm_l(L_ARM);
pros::Motor arm_r(abs(R_ARM), /* reversed */ true);
