#include "main.hpp"
#include "motors.hpp"

int i = 0;

std::string auton[4] = { "Red Small", "Blue Small", "Red Big", "Blue Big" };

static void on_center_button() {
  static bool pressed = false;
  pressed = !pressed;
  if (pressed) {
    pros::lcd::set_text(2, auton[i]);
  } else {
    pros::lcd::clear_line(2);
  }
}

static void on_right_button() {
  static bool pressed = false;
  pressed = !pressed;
  if (pressed) {
    if(i + 1 == 4){
      i = 0;
    } else i++;

    pros::lcd::clear_line(2);
    pros::lcd::set_text(2, auton[i]);
  } else {
    pros::lcd::clear_line(2);
  }
}

static void on_left_button(){
  static bool pressed = false;
  pressed = !pressed;
  if (pressed) {
    if(i + 1 == 4){
      i = 0;
    } else i++;

    pros::lcd::clear_line(2);
    pros::lcd::set_text(2, auton[i]);
  } else {
    pros::lcd::clear_line(2);
  }
}

void initialize() {
  pros::lcd::initialize();
  pros::lcd::set_text(1, "Hello World!");

  pros::lcd::register_btn0_cb(on_right_button);
  pros::lcd::register_btn1_cb(on_center_button);
  pros::lcd::register_btn2_cb(on_left_button);
}

void disabled() {}

void competition_initialize() {}
