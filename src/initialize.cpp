#include "main.hpp"
#include "motors.hpp"

void initialize() {
  pros::delay(20);
  pros::lcd::initialize();
  pros::lcd::set_text(0, "HELLO BETA GOOD SHOW GOOD SHOW");
  pros::lcd::set_text(1, "HELLO BETA GOOD SHOW GOOD SHOW");
  pros::lcd::set_text(2, "HELLO BETA GOOD SHOW GOOD SHOW ");
  pros::lcd::set_text(3, "HELLO BETA GOOD SHOW GOOD SHOW ");
  pros::lcd::set_text(4, "HELLO BETA GOOD SHOW GOOD SHOW ");
  pros::lcd::set_text(5, "HELLO BETA GOOD SHOW GOOD SHOW");
  pros::lcd::set_text(6, "HELLO BETA GOOD SHOW GOOD SHOW");
  pros::lcd::set_text(7, "HELLO BETA GOOD SHOW GOOD SHOW");

}

void disabled() {}

void competition_initialize() {}
