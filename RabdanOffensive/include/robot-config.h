using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor R1;
extern motor R2;
extern motor R3;
extern motor L1;
extern motor L2;
extern motor L3;
extern motor intake;
extern inertial INERT;
extern controller Controller1;
extern digital_out rightwing;
extern motor catapult;
extern digital_out leftwing;
extern digital_out BackWingLeft;
extern motor Catapult5W;
extern pot CataSensor;
extern digital_out Hang;
extern digital_out BackWingRight;
extern digital_out HangGUp;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );