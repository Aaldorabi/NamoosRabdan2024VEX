#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// R1                   motor         1               
// R2                   motor         2               
// R3                   motor         3               
// L1                   motor         8               
// L2                   motor         9               
// L3                   motor         10              
// intake               motor         4               
// intakeout            digital_out   A               
// INERT                inertial      12              
// Controller1          controller                    
// Wings                digital_out   D               
// catapult             motor         7               
// cataswich            limit         C               
// EndGame              digital_out   E               
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors using the V5 port icon in the top right of the screen. Doing     */
/*  so will update robot-config.cpp and robot-config.h automatically, so     */
/*  you don't have to. Ensure that your motors are reversed properly. For    */
/*  the drive, spinning all motors forward should drive the robot forward.   */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your robot manually with the sidebar configurer. */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Specify your drive setup below. There are eight options:
//ZERO_TRACKER_NO_ODOM, ZERO_TRACKER_ODOM, TANK_ONE_ENCODER, TANK_ONE_ROTATION, TANK_TWO_ENCODER, TANK_TWO_ROTATION, HOLONOMIC_TWO_ENCODER, and HOLONOMIC_TWO_ROTATION
//For example, if you are not using odometry, put ZERO_TRACKER_NO_ODOM below:
ZERO_TRACKER_NO_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(L1,L2,L3),

//Right Motors:
motor_group(R1,R2,R3),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT12,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3.25,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.6,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
3,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
-2,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

int current_auton_selection = 0;
bool auto_started = false;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();

  
}

void autonomous(void) {

    intakeout.set(true);


    L1.setVelocity(100, percent);
    L2.setVelocity(100, percent);
    L3.setVelocity(100, percent);
    R1.setVelocity(100, percent);
    R2.setVelocity(100, percent);
    R3.setVelocity(100, percent);
    L1.setMaxTorque(100, percent);
    L2.setMaxTorque(100, percent);
    L3.setMaxTorque(100, percent);
    R1.setMaxTorque(100, percent);
    R2.setMaxTorque(100, percent);
    R3.setMaxTorque(100, percent);
    intake.setBrake(hold);
    intake.setVelocity(100, percent);
    Wings.set(true);
    wait(1, seconds);
    //chassis.drive_distance(10);
    //wait(5, seconds);
    //chassis.drive_distance(15);
    //independent motor control

    chassis.DriveR.spin(fwd,12,volt);
    wait(.7, seconds);
    chassis.DriveR.stop();
    chassis.DriveL.stop();
    Wings.set(false);
    //wait(.1, seconds);
    //chassis.turn_to_angle(-65, 12);
    chassis.turn_to_angle(-60, 11); //old -60
    intake.spin(reverse);
    chassis.DriveR.spin(fwd,12,volt);
    chassis.DriveL.spin(fwd,12,volt);
    wait(.9, seconds);
    chassis.DriveR.stop();
    chassis.DriveL.stop();
    intake.stop();
    //Wings.set(false);

    chassis.drive_distance(-15);

    //drive to ball to B3
    chassis.turn_to_angle(-150); //old -115
    intake.spin(forward);
    chassis.drive_distance(52);

    //go back
    chassis.drive_distance(-5);
    
    //throw ball B3
    chassis.turn_to_angle(-45);
    //wait(0.25, seconds);
    intake.spin(reverse);
    wait(.1, seconds);

    chassis.turn_to_angle(-135); //old -105
    //intake.stop();

    intake.spin(forward);
    chassis.drive_distance(19); //old 15
    intake.spin(reverse);
    chassis.left_swing_to_angle(0); //old -5
    Wings.set(true);
    

    //intake.spin(reverse);
    chassis.DriveR.spin(fwd,12,volt);
    chassis.DriveL.spin(fwd,12,volt);
    wait(1, seconds);
    intake.stop();
    chassis.DriveR.spin(fwd,0,volt);
    chassis.DriveL.spin(fwd,0,volt);

    //chassis.drive_distance(-10);
    //chassis.turn_to_angle(-130, 8);
    //intake.spin(forward);
    //chassis.drive_distance(27);
    //chassis.turn_to_angle(45);
    intake.stop();

    intake.spin(reverse);
    Wings.set(true);

    chassis.DriveR.spin(fwd,12,volt);
    chassis.DriveL.spin(fwd,12,volt);
    wait(1.5, seconds);
    chassis.DriveR.spin(fwd,0,volt);
    chassis.DriveL.spin(fwd,0,volt);
    intake.stop();

    Wings.set(false);

}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  intake.setVelocity(100.0, percent);
  catapult.setVelocity(70.0, percent);
  L1.setBrake(hold);
  L2.setBrake(hold);
  L3.setBrake(hold);
  R1.setBrake(hold);
  R2.setBrake(hold);
  R3.setBrake(hold);
  Wings.set(false);

  
  
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................

    if(Controller1.ButtonX.pressing()){
      Wings.set(true);
    }
    else if(Controller1.ButtonB.pressing()){
      Wings.set(false);
    }
    if (Controller1.ButtonUp.pressing()) {
    intakeout.set(true);
    }
     else if (Controller1.ButtonDown.pressing()) {
    intakeout.set(false);
    }

    //catapult
    else if(Controller1.ButtonL1.pressing()){
      catapult.spin(forward);
    }
    else if(Controller1.ButtonL1.pressing() && cataswich.pressing()){
      catapult.spinFor(forward, 90, degrees);
      catapult.spin(forward);
    }
    else if(!Controller1.ButtonL1.pressing() && cataswich.pressing()){
      catapult.stop(vex::brakeType(coast));
    }
    



    else if(Controller1.ButtonA.pressing()){
        EndGame.set(true);
    }
    else if(Controller1.ButtonY.pressing()){
        EndGame.set(false);
    }
  
    chassis.control_tank();
    //or chassis.control_holonomic(); for holo drive.

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
