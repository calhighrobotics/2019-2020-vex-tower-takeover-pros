#define L_DR 11
#define R_DR 12
#define BELT 13
#define L_ROLL 14
#define R_ROLL 15
#define L_DROP 16
#define R_DROP 17
#define PUSH 18

pros::Motor dr_l (L_DR);
pros::Motor dr_r (R_DR, true); //REVERSED
pros::Motor belt(BELT);
pros::Motor roll_l (R_ROLL);
pros::Motor roll_r (L_ROLL);
pros::Motor drop_l (L_DROP);
pros::Motor drop_r (R_DROP);
pros::Motor push (PUSH);
