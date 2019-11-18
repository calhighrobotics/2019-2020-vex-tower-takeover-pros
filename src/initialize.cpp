#include "main.hpp"
#include "motors.hpp"

static void on_center_button() {
  static bool pressed = false;
  pressed = !pressed;
  if (pressed) {
    pros::lcd::set_text(2, "I was pressed!");
  } else {
    pros::lcd::clear_line(2);
  }
}

void initialize() {
  push.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
  arm_l.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
  arm_r.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);

  pros::lcd::initialize();
  pros::lcd::set_text(1, "Hello PROS User!");

  pros::lcd::register_btn1_cb(on_center_button);
}

void disabled() {}

void competition_initialize() {}
