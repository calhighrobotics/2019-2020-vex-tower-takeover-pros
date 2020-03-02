#include "main.hpp"
#include "motors.hpp"

void initialize() {
  pros::delay(20);
  pros::lcd::initialize();
  pros::lcd::set_text(0, "Good Show Beta");
  pros::lcd::set_text(1, "Good Show Beta");
  pros::lcd::set_text(2, "Good Show Beta");
  pros::lcd::set_text(3, "Good Show Beta");
  pros::lcd::set_text(4, "Good Show Beta");
  pros::lcd::set_text(5, "Good Show Beta");
  pros::lcd::set_text(6, "Good Show Beta");
}

void disabled() {}

void competition_initialize() {}
