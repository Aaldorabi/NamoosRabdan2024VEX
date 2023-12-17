#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor R1 = motor(PORT1, ratio6_1, false);
motor R2 = motor(PORT2, ratio6_1, false);
motor R3 = motor(PORT3, ratio6_1, false);
motor L1 = motor(PORT8, ratio6_1, true);
motor L2 = motor(PORT9, ratio6_1, true);
motor L3 = motor(PORT10, ratio6_1, true);
motor intake = motor(PORT4, ratio6_1, true);
digital_out intakeout = digital_out(Brain.ThreeWirePort.A);
inertial INERT = inertial(PORT11);
controller Controller1 = controller(primary);
digital_out Wings = digital_out(Brain.ThreeWirePort.D);
motor catapult = motor(PORT7, ratio36_1, true);
limit cataswich = limit(Brain.ThreeWirePort.C);
digital_out EndGame = digital_out(Brain.ThreeWirePort.E);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller1RightShoulderControlMotorsStopped = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // check the ButtonR1/ButtonR2 status to control intake
      if (Controller1.ButtonR1.pressing()) {
        intake.spin(forward);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonR2.pressing()) {
        intake.spin(reverse);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (!Controller1RightShoulderControlMotorsStopped) {
        intake.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1RightShoulderControlMotorsStopped = true;
      }
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}