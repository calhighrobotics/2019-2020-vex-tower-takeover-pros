#include "main.hpp"
#include "motors.hpp"

void initialize() {
  pros::delay(20);
  pros::lcd::initialize();
  pros::lcd::set_text(0, "TEAM 1516B TEAM 1516B TEAM 1516B TEAM 1516B");
  pros::lcd::set_text(1, "TEAM 1516B TEAM 1516B TEAM 1516B TEAM 1516B");
  pros::lcd::set_text(2, "TEAM 1516B TEAM 1516B TEAM 1516B TEAM 1516B ");
  pros::lcd::set_text(3, "TEAM 1516B TEAM 1516B TEAM 1516B TEAM 1516B ");
  pros::lcd::set_text(4, "TEAM 1516B TEAM 1516B TEAM 1516B TEAM 1516B ");
  pros::lcd::set_text(5, "TEAM 1516B TEAM 1516B TEAM 1516B TEAM 1516B ");
  pros::lcd::set_text(6, "TEAM 1516B TEAM 1516B TEAM 1516B TEAM 1516B");
  pros::lcd::set_text(7, "TEAM 1516B TEAM 1516B TEAM 1516B TEAM 1516B");

}

void disabled() {}

void competition_initialize() {}
