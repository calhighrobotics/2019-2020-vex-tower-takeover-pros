#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
 #define L_DR 11
 #define R_DR 12
 #define BELT 13
 #define L_ROLL 14
 #define R_ROLL 15
 #define L_DROP 16
 #define R_DROP 17
 #define PUSH 18

 void opcontrol() {
 	pros::Motor dr_l (L_DR);
   pros::Motor dr_r (R_DR, true); //REVERSED
   pros::Controller master (CONTROLLER_MASTER);

 	while (true) {

 		dr_l.move(master.get_analog(ANALOG_LEFT_Y));
 		dr_r.move(master.get_analog(ANALOG_LEFT_Y));

 		if(master.get_digital(DIGITAL_R1)){
 			dr_l.move_velocity(100);
 			dr_r.move_velocity(-100);
 		} else {
 			dr_l.move_velocity(0);
 			dr_l.move_velocity(0);
 		}
 		if(master.get_digital(DIGITAL_L2)){
 			dr_l.move_velocity(-100);
 			dr_r.move_velocity(100);
 		} else{
 			dr_l.move_velocity(0);
 			dr_r.move_velocity(0);
 		}
 	}
 }
