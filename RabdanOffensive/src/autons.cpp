#include "vex.h"
int AngleOffset = 180;

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(12, 1.5, 0, 5, 0);
  chassis.set_heading_constants(12, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .025, 3.9, 15);
  //chassis.set_turn_constants(12, .4, .025, 3, 15);
  
  chassis.set_swing_constants(12, .3, .002, 2, 15);
  //chassis.set_swing_constants(12, .3, .002, 2, 15);
  // Each exit condition set is in the form (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 2000);
  chassis.set_swing_exit_conditions(1, 100, 2000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 11;
  chassis.drive_settle_error = 3;
}

void Offensive5Point(){
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

    //start
    intake.spin(reverse);
    BackWingLeft.set(true);
    BackWingRight.set(true);
    wait(.1, seconds);


    //flick ball
    chassis.DriveL.setVelocity(60, percent);
    chassis.DriveL.spin(reverse); //old forward
    wait(.7, seconds); //0.6
    chassis.DriveL.setVelocity(100, percent);
    BackWingLeft.set(false);
    BackWingRight.set(false);
    chassis.DriveR.stop(vex::brakeType::brake);
    chassis.DriveL.stop(vex::brakeType::brake);
    chassis.turn_to_angle(-75); //old -80
    intake.spin(reverse);
    //wait(1, seconds);//.25
    chassis.DriveR.spin(reverse,12,volt);
    chassis.DriveL.spin(reverse,12,volt);
    wait(.75, seconds);
    chassis.DriveR.stop(vex::brakeType::coast);
    chassis.DriveL.stop(vex::brakeType::coast);
    intake.stop();
    //Wings.set(false);

    chassis.drive_distance(15); //old -15

    //drive to ball to B3
    chassis.turn_to_angle(19); //old -157.5//21 //20
    intake.spin(forward);
    chassis.drive_distance(51); //old 49 //50
    

    //go back
    chassis.drive_distance(-5);
    intake.stop();
    //intake.stop();
    
    //throw ball B3
    //chassis.turn_to_angle(float angle, float turn_max_voltage, float turn_settle_error, float turn_settle_time, float turn_timeout)
    chassis.turn_to_angle(-40 + AngleOffset, 12, 10, 200, 1350); //1500 last constant //-48 degrees
    intake.setVelocity(75,percent);
    intake.spin(reverse);
    chassis.drive_distance(5);
    chassis.drive_distance(-10);
    //wait(0.75, seconds);
    intake.setVelocity(100,percent);

    //chassis.drive_distance(-5); replaced with -10 from before
    
    chassis.turn_to_angle(-110 + AngleOffset);  //old -100
    intake.spin(forward);
    chassis.drive_distance(27); //old 29 //27
    //chassis.left_swing_to_angle(0); //old -5

    //(float angle, float swing_max_voltage, float swing_settle_error, float swing_settle_time, float swing_timeout, float swing_kp, float swing_ki, float swing_kd, float swing_starti);
    //chassis.left_swing_to_angle(10, 12, 10, 300, 1500, .3, 0, 2, 15);
    //chassis.left_swing_to_angle(90, 8, 2, 0, 1000, 2, 0, 7, 0);

    chassis.turn_to_angle(-177, 12, 1, 300, 2000); //175 //176.5


    intake.spin(reverse);
    rightwing.set(true);
    leftwing.set(true);
    

    //intake.spin(reverse);
    chassis.DriveR.spin(fwd,12,volt);
    chassis.DriveL.spin(fwd,12,volt);
    wait(1, seconds);
    intake.stop();
    chassis.DriveR.spin(fwd,0,volt);
    chassis.DriveL.spin(fwd,0,volt);

    //go to the auton win point bar
    //chassis.turn_to_angle(float angle, float turn_max_voltage, float turn_settle_error, float turn_settle_time, float turn_timeout)
    rightwing.set(false);
    leftwing.set(false);
    chassis.turn_to_angle(-47.5,12,2,300, 3000); //-45
    chassis.DriveR.spin(fwd, 12,volt);
    chassis.DriveL.spin(fwd,12,volt);
    wait(1.35, seconds);
    chassis.DriveR.stop(vex::brakeType::hold);
    chassis.DriveR.stop(vex::brakeType::hold);
    chassis.DriveR.stop();
    chassis.DriveL.stop();
}

void Offensive6Point(){
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

    //start
    intake.spin(reverse);
    wait(.25, seconds);
    
    //get 6 point ball!!!
    intake.spin(forward);
    chassis.drive_distance(11);

    //go back to match load
    //chassis.drive_distance(-40);//old-38
    chassis.DriveR.spin(reverse,6,volt);
    chassis.DriveL.spin(reverse,6,volt);
    wait(1.55, seconds); //1.25
    chassis.DriveR.stop(vex::brakeType::coast);
    chassis.DriveL.stop(vex::brakeType::coast);
    //chassis.turn_to_angle(-35, 12, 10, 200, 1350); //-45
    //wait(0.1, sec);
    BackWingLeft.set(true);
    BackWingRight.set(true);
    wait(0.25, sec);
    //chassis.drive_distance(-15); 

    //flick ball
    chassis.DriveL.setVelocity(60, percent);
    chassis.DriveL.spin(reverse); //old forward
    wait(.75, seconds); //1
    chassis.DriveL.setVelocity(100, percent);
    //BackWings.set(false);
    chassis.DriveR.stop(vex::brakeType::brake);
    chassis.DriveL.stop(vex::brakeType::brake);
    /*
    intake.spin(forward);
    chassis.DriveR.spin(reverse,12,volt);
    chassis.DriveL.spin(reverse,12,volt);
    wait(.75, seconds); //old .75 //.55
    chassis.DriveR.stop(vex::brakeType::coast);
    chassis.DriveL.stop(vex::brakeType::coast);
    

    //go back to flip over and score ball in intake
    chassis.drive_distance(10);
    */
    chassis.turn_to_angle(-70, 12, 10, 200, 1350); //old -60
    //chassis.drive_distance(-5); //maibe
    BackWingLeft.set(false);
    BackWingRight.set(false);
    chassis.turn_to_angle(110, 12, 10, 200, 1350);  
    intake.spin(reverse);
    chassis.DriveR.spin(forward,12,volt);
    chassis.DriveL.spin(forward,12,volt);
    wait(.6, seconds); //old .75
    chassis.DriveR.stop(vex::brakeType::coast);
    chassis.DriveL.stop(vex::brakeType::coast);
    chassis.drive_distance(-17);//old -20

    //chassis.drive_distance(15); //go back

    //drive to ball to B3
    intake.setVelocity(100, percent);
    intake.setMaxTorque(100, percent);
    chassis.turn_to_angle(-159 + AngleOffset); //old -157
    intake.spin(forward);
    chassis.drive_distance(49); //old 46
    

    //go back
    chassis.drive_distance(-5);
    intake.stop();
    
    //throw ball B3
    //chassis.turn_to_angle(float angle, float turn_max_voltage, float turn_settle_error, float turn_settle_time, float turn_timeout)
    chassis.turn_to_angle(-38 + AngleOffset, 12, 10, 200, 1350); //1500 last constant //-48 degrees //-42
    //wait(0.25, seconds);
    intake.setVelocity(80,percent); //60
    intake.spin(reverse);

    wait(0.6, seconds);
    intake.setVelocity(100,percent);

    intake.spin(forward);
    chassis.turn_to_angle(-110 + AngleOffset); //old -115 /-105

    chassis.drive_distance(23); //old 21
    //chassis.left_swing_to_angle(0); //old -5

    //(float angle, float swing_max_voltage, float swing_settle_error, float swing_settle_time, float swing_timeout, float swing_kp, float swing_ki, float swing_kd, float swing_starti);
    //chassis.left_swing_to_angle(10, 12, 10, 300, 1500, .3, 0, 2, 15);
    chassis.turn_to_angle(175, 12, 2.5, 300, 2000);
    //chassis.left_swing_to_angle(90, 8, 2, 0, 1000, 2, 0, 7, 0);



    intake.spin(reverse);
    rightwing.set(true);
    leftwing.set(true);
    

    //intake.spin(reverse);
    chassis.DriveR.spin(fwd,12,volt);
    chassis.DriveL.spin(fwd,12,volt);
    wait(1, seconds);
    intake.stop();
    chassis.DriveR.spin(fwd,0,volt);
    chassis.DriveL.spin(fwd,0,volt);
    rightwing.set(false);
    leftwing.set(false);
}

void DefensiveRush(){
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

    //start
    intake.spin(reverse);
    BackWingLeft.set(false);
    BackWingRight.set(false);
    leftwing.set(true);
    rightwing.set(false);
    wait(.25, seconds);
    
    chassis.turn_to_angle(15, 12, 2, 500,2000);
    leftwing.set(false);
    rightwing.set(false);
    intake.spin(forward);
    chassis.drive_distance(54.5); //55
    wait(0.1, sec);
    chassis.drive_distance(-2);
    chassis.turn_to_angle(15);
    chassis.drive_distance(-55); //-58
    intake.stop();
    chassis.turn_to_angle(90);
    //chassis.right_swing_to_angle(80);
    intake.spin(reverse);
    chassis.drive_distance(5);
    chassis.drive_distance(-5);
    //wait(0.75, sec);
    intake.stop();
    chassis.turn_to_angle(-45);
    chassis.drive_distance(31.5);
    chassis.left_swing_to_angle(0);
    //independent motor
    intake.spin(reverse);
    chassis.DriveR.spin(forward);
    chassis.DriveL.spin(forward);
    wait(0.75, sec);
    chassis.DriveR.stop();
    chassis.DriveL.stop();
    intake.stop();

    wait(0.15, sec);
    chassis.drive_distance(-12);
    
    chassis.turn_to_angle(-25); //-35
    BackWingLeft.set(true);
    BackWingRight.set(true);
    chassis.drive_distance(-17);
    
    //independant flicking
    chassis.DriveL.spin(reverse);
    wait(0.5, sec);
    chassis.DriveL.stop();
    chassis.turn_to_angle(-80);

    //chassis.turn_to_angle(-95);
    BackWingLeft.set(false);
    BackWingRight.set(false);
    chassis.turn_to_angle(100);
}

void DefensiveMatchPoint(){
  L1.setVelocity(100,percent);
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
    intake.setMaxTorque(100, percent);
    //start
    chassis.turn_to_angle(45);
    chassis.drive_distance(30);
    chassis.turn_to_angle(85);
    intake.spin(reverse);
    chassis.DriveL.spin(forward,12,volt);
    chassis.DriveR.spin(forward,12,volt);
    wait(0.75, seconds);
    intake.stop();
    chassis.DriveL.stop();
    chassis.DriveR.stop();
    chassis.drive_distance(-15);
    chassis.turn_to_angle(55);
    BackWingLeft.set(true);
    BackWingRight.set(true);
    wait(0.5, seconds);
    chassis.drive_distance(-15);
    chassis.turn_to_angle(20);
    BackWingLeft.set(false);
    BackWingRight.set(false);
    chassis.drive_distance(-10);
    chassis.turn_to_angle(-179,9);

    //go to underbarrier ball
    intake.spin(reverse);
    chassis.drive_distance(41);
    wait(0.25, sec);
    intake.stop();

}

void DefensiveMatchLoad(){
  L1.setVelocity(100,percent);
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

    //start
    chassis.turn_to_angle(45);
    chassis.drive_distance(30);
    chassis.turn_to_angle(85);
    intake.spin(reverse);
    chassis.DriveL.spin(forward,12,volt);
    chassis.DriveR.spin(forward,12,volt);
    wait(0.75, seconds);
    intake.stop();
    chassis.DriveL.stop();
    chassis.DriveR.stop();
    chassis.drive_distance(-15);
    chassis.turn_to_angle(55);
    BackWingLeft.set(true);
    BackWingRight.set(true);
    wait(0.5, seconds);
    chassis.drive_distance(-15);
    chassis.turn_to_angle(20);
    BackWingLeft.set(false);
    BackWingRight.set(false);
    chassis.drive_distance(-10);
    chassis.turn_to_angle(-179,9);

    //go to underbarrier ball
    intake.spin(reverse);
    chassis.drive_distance(40);

    //go to match load zonee
    chassis.drive_distance(-45);
    intake.stop();
}

void Skills(){

    int AngleOffset = 180;

    catapult.setVelocity(100,percent);
    Catapult5W.setVelocity(100,percent);

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

    //start
    intake.spin(reverse);
    wait(.25, seconds);
    intake.stop();
    

    //go to match load bar
    chassis.drive_distance(-2);
    chassis.turn_to_angle(-30,12,3,100,600); //old 30
    rightwing.set(false);
    leftwing.set(false);
    chassis.drive_distance(17,-30,12,12,1,100,600);
    chassis.turn_to_angle(-160,12,1,100,600);
    chassis.drive_distance(-1);
    BackWingLeft.set(true);
    BackWingRight.set(true);
    chassis.DriveL.stop(vex::brakeType::brake);
    chassis.DriveR.stop(vex::brakeType::brake);

    //catapultt
    catapult.spin(forward);
    Catapult5W.spin(forward);
    wait(30, sec);
    catapult.stop();
    Catapult5W.stop();

    catapult.spin(forward);
    Catapult5W.spin(forward);
    wait(.1, sec);
    catapult.stop();
    Catapult5W.stop();
    BackWingLeft.set(false);
    BackWingRight.set(false);
    //go to left from the goal
    chassis.drive_distance(4);
    chassis.turn_to_angle(135,12,2,100,1000);
    chassis.drive_distance(25);//29
    chassis.turn_to_angle(180,12,3,300,2000);
    chassis.drive_distance(73);
    rightwing.set(true);
    leftwing.set(false);
    wait(.2, sec);
    chassis.left_swing_to_angle(-135,10,3,100,750,.3, .001, 2, 15);
    intake.spin(reverse);
    chassis.drive_distance(23,-135,12,12,2,300,1000);
    chassis.left_swing_to_angle(-90,12,3,100,750,.3, .001, 2, 15); //old -90
    chassis.drive_distance(-5,-90,12,12,3,100,750);
    //rightwing.set(false);
    //leftwing.set(false);
  

    chassis.DriveR.spin(forward,12,volt);
    chassis.DriveL.spin(forward,12,volt);
    wait(0.75, seconds);
    chassis.DriveR.stop();
    chassis.DriveL.stop();
    rightwing.set(false);
    leftwing.set(false);
    
    //go away from goal
    chassis.drive_distance(-20,-90,12,12,3,100,750);

    chassis.DriveR.spin(forward,12,volt);
    chassis.DriveL.spin(forward,12,volt);
    wait(0.75, seconds);
    chassis.DriveR.stop();
    chassis.DriveL.stop();

    chassis.drive_distance(-10);
    rightwing.set(false);
    leftwing.set(false);
    wait(0.3, sec);

   chassis.turn_to_angle(170,12,100,2000,300);
   chassis.drive_distance(-37,170,12,12,2,300,1500);
   BackWingLeft.set(true);
    BackWingRight.set(true);
   chassis.left_swing_to_angle(70,12,5,50,600,.3, .001, 2,15);
   chassis.drive_distance(-20,70,12,12,3,100,1000);
   chassis.left_swing_to_angle(0,12,5,50,500,.3, .001, 2, 15);
   
   
   chassis.DriveR.spin(reverse,12,volt);
    chassis.DriveL.spin(reverse,12,volt);
    wait(0.75, seconds);
    chassis.DriveR.stop();
    chassis.DriveL.stop();
    chassis.drive_distance(20,0,12,12,2,100,750);
   
    BackWingLeft.set(false);
    BackWingRight.set(false);
    rightwing.set(true);
    leftwing.set(true);
    chassis.right_swing_to_angle(-119,12,2,150,750,.3, .001, 2, 15);
    chassis.drive_distance(50,-119,12,12,2,150,1250);
    chassis.right_swing_to_angle(95,12,5,50,2000,.3, .001, 2, 15);
    
     chassis.DriveR.spin(forward,12,volt);
    chassis.DriveL.spin(forward,12,volt);
    wait(0.75, seconds);
    chassis.DriveR.stop();
    chassis.DriveL.stop();
    //chassis.drive_distance(20);
    chassis.drive_distance(-10);

    chassis.DriveR.spin(forward,12,volt);
    chassis.DriveL.spin(forward,12,volt);
    wait(0.75, seconds);
    chassis.DriveR.stop();
    chassis.DriveL.stop();
   


    chassis.drive_distance(-5);
    chassis.turn_to_angle(-1,12,1,100,2000);
    rightwing.set(false);
    leftwing.set(false);
    BackWingLeft.set(true);
    BackWingRight.set(true);
    //chassis.drive_distance(5);
    //chassis.turn_to_angle(-10);
    chassis.drive_distance(53);

    chassis.DriveR.spin(forward,12,volt);
    chassis.DriveL.spin(forward,12,volt);
    wait(.9, seconds);
    chassis.DriveR.stop();
    chassis.DriveL.stop();
}


void NoAuton(){
  
}

void FinalRush(){
  rightwing.set(true);
  chassis.drive_distance(8,0,12,12,1,51500,1000);
  chassis.turn_to_angle(-30,12,1,150,1000); //-29
  rightwing.set(false);
  intake.spin(forward,12,volt);
  chassis.drive_distance(60,-30,12,12,1,100,2500);//63
  chassis.turn_to_angle(90,12,5,100,1000);
  intake.stop();
  
  rightwing.set(true);
  leftwing.set(true);
  intake.spin(reverse);
  chassis.DriveR.spin(forward);
  chassis.DriveL.spin(forward);
  wait(1, sec);
  chassis.DriveR.stop();
  chassis.DriveL.stop();
  rightwing.set(false);
  leftwing.set(false);

  chassis.DriveL.spin(reverse);
  chassis.DriveR.spin(reverse);
  wait(.75, sec);
  chassis.DriveL.stop();
  chassis.DriveR.stop();
  wait(0.25, sec);
  chassis.turn_to_angle(-160,12,3,100,1000);
  intake.spin(forward);
  chassis.drive_distance(41,-160,12,12,2,100,2000);//39
  intake.stop();


  //after hitting bar to recalculate
  chassis.drive_distance(-10,-180,12,12,1,100,500);
  chassis.right_swing_to_angle(90,12,3,10,1000,.3, .001, 2, 15);
  //chassis.turn_to_angle(95,12,3,150,1000);
  intake.spin(reverse);
  chassis.drive_distance(25,95,12,12,2,100,1500);

  chassis.left_swing_to_angle(-125,12,3,100,1500,.3, .001, 2, 15); //-145

  chassis.drive_distance(18,-125,12,12,1,100,2000); //heading -130
  chassis.turn_to_angle(-90,12,2,100,1000);

  //pick up triball under bar
  intake.spin(forward);
  chassis.drive_distance(30,-90,12,12,2,100,1500); //18 ///35
  chassis.drive_distance(-40,-90,12,12,2,100,2000); //-35
  intake.stop();

  //deload
  chassis.left_swing_to_angle(-135,12,3,100,1000,.3, .001, 2, 15);
  BackWingLeft.set(true);
    BackWingRight.set(true);
  chassis.drive_distance(-7,-135,12,12,1,100,1000);
  chassis.left_swing_to_angle(-170,12,3,100,1500,.3, .001, 2, 15);
  
  //first back score side
  chassis.DriveR.spin(reverse);
  chassis.DriveL.spin(reverse);
  wait(.75,sec);
  chassis.DriveR.stop();
  chassis.DriveL.stop();

  chassis.drive_distance(20,-170,12,12,3,100,1000);

  rightwing.set(false);
  leftwing.set(false);

  chassis.turn_to_angle(30,12,3,100,1000);
  intake.spin(reverse);

  //second back score side
  chassis.DriveR.spin(forward);
  chassis.DriveL.spin(forward);
  wait(.75,sec);
  chassis.DriveR.stop();
  chassis.DriveL.stop();

  chassis.drive_distance(-10,30,12,12,2,50,1000);
  
  chassis.DriveR.spin(forward);
  chassis.DriveL.spin(forward);
  wait(.75,sec);
  chassis.DriveR.stop();
  chassis.DriveL.stop();
}

void DefensiveFarSide(){
  intake.setBrake(hold);
  intake.setVelocity(100, percent);
  intake.setMaxTorque(100, percent);
  leftwing.set(true);

  //chassis.left_swing_to_angle(20,12,1,150,1500,.3, .002, 2, 15);
  //chassis.turn_to_angle(20);
  intake.spin(forward);
  chassis.drive_distance(45,8,12,9,2,650,2000); //7 degree
  leftwing.set(false);
  chassis.drive_distance(-25,25,12,9,2,150,2000);
  chassis.drive_distance(-33,0,12,9,2,150,2000);
  intake.stop();
  chassis.turn_to_angle(90,12,3,150,2000);
  intake.spin(reverse);
  chassis.drive_distance(5,90,12,12,1,150,1000);
  chassis.drive_distance(-10,90,12,12,1,150,1000);
  chassis.turn_to_angle(-60,12,3,150,1500); //-50
  chassis.drive_distance(28,-45,12,12,2,150,1500); //30

  //chassis.drive_distance(-15);
  chassis.left_swing_to_angle(-10,12,3,150,1500,.3, .001, 2, 15);
  //independant
  chassis.drive_distance(-5,-10,12,12,1,150,1500);
  intake.spin(reverse);
  chassis.DriveL.spin(forward);
  chassis.DriveR.spin(forward);
  wait(1, sec);
  chassis.DriveR.stop();
  chassis.DriveL.stop();
  intake.stop();

  chassis.drive_distance(-15,0,12,12,1,50,1500); //-20
  BackWingLeft.set(true);
  chassis.left_swing_to_angle(-45,12,5,50,1500,.3, .001, 2, 15);
  chassis.drive_distance(-12,-45,12,12,1,50,1500);
  chassis.left_swing_to_angle(-90,12,3,50,1500,.3, .001, 2, 15);
  chassis.drive_distance(-10,-90,12,12,1,50,1500);
  chassis.turn_to_angle(125,12,3,50,1500);
  BackWingLeft.set(false);
  intake.spin(reverse,6,volt);
  chassis.drive_distance(37.5,90,12,9,1,150,2500);
  intake.stop(brakeType::coast);
  /*chassis.drive_distance(-55.2,5,12,9,2,250,2500);
  chassis.drive_distance(-12,90,12,9,2,250,2000);
  
  intake.spin(reverse);
  chassis.drive_distance(10,90,12,12,1,50,1000);
  chassis.drive_distance(-10,90,12,12,1,50,1000);
  intake.stop();

  chassis.turn_to_angle(-40,12,2,100,1000);
  chassis.drive_distance(20,-40,12,12,5,100,1000);
  chassis.drive_distance(30,0,12,12,5,100,1000);
  chassis.drive_distance(-10,0,12,12,1,100,1000);

  BackWingLeft.set(true);
  chassis.left_swing_to_angle(-40,12,3,100,1500,.3, .002, 2, 15);
  chassis.drive_distance(-25,-45,12,12,3,100,2000);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(-10,-90,12,12,3,50,1000);
  chassis.drive_distance(10,-90,12,12,3,50,1000);
  chassis.turn_to_angle(90,12,3,50,1500);
  chassis.drive_distance(40);
  */
}

void AWPOffensiveFarSide(){
  intake.setBrake(hold);
  intake.setVelocity(100, percent);
  intake.setMaxTorque(100, percent);

  intake.spin(forward);
  rightwing.set(true);

  chassis.drive_distance(44,-10,12,12,2,300,2000); //150mm  settle time
  rightwing.set(false);
  chassis.drive_distance(-50,-20,12,10,2,150,2000);

  chassis.right_swing_to_angle(90,12,3,50,1500,.3, .001, 2, 15);
  intake.spin(reverse,9,volt);
  chassis.turn_to_angle(-90,12,1,75,1500);

  intake.spin(forward);
  chassis.drive_distance(32,-90,12,12,2,350,2000);

  chassis.drive_distance(-43,-100,12,12,2,50,2500); //-43,angle -100


  BackWingLeft.set(true);
  /*chassis.left_swing_to_angle(-140,12,3,150,1500,.3, .001, 2, 15);
  
  chassis.drive_distance(-10,-140,12,12,2,50,1500);*/
  //chassis.turn_to_angle(-170,12,3,50,750);


  chassis.left_swing_to_angle(-160,12,3,50,1500,.3, .001, 2, 15); //-170
  BackWingLeft.set(false);
  BackWingRight.set(true);
  //chassis.drive_distance(-30,-160,12,12,3,50,750);

  chassis.DriveR.spin(reverse);
  chassis.DriveL.spin(reverse);
  wait(.75, sec);
  chassis.DriveR.stop();
  chassis.DriveL.stop();

  BackWingRight.set(false);
  chassis.drive_distance(10,180,12,12,3,50,750);
  chassis.turn_to_angle(17.5,12,3,50,1500);
  leftwing.set(true);
  intake.spin(reverse);
  chassis.DriveR.spin(forward);
  chassis.DriveL.spin(forward);
  wait(.8, sec);
  chassis.DriveR.stop();
  chassis.DriveL.stop();
  leftwing.set(false);

  chassis.drive_distance(-10,0,12,12,1,150,1000);
  chassis.turn_to_angle(-90,12,1,150,1000);
  intake.spin(forward);
  chassis.drive_distance(47,-75,12,12,2,75,2000);


  chassis.turn_to_angle(25,12,3,50,1000);
  intake.spin(reverse);
  chassis.drive_distance(40,75,12,12,3,50,1500);

  chassis.turn_to_angle(-70,12,3,50,1000);

  intake.spin(forward);
  chassis.drive_distance(20,-90,12,12,2,50,1000);
  chassis.turn_to_angle(90,12,3,50,1000);
  intake.spin(reverse,7,volt);
  chassis.drive_distance(25,90,12,12,3,50,1500);
  



}

void AutonTest(){
    chassis.drive_distance(30);
    chassis.drive_distance(-30);
    chassis.right_swing_to_angle(-90);
    chassis.left_swing_to_angle(90);
    chassis.right_swing_to_angle(-45);
    chassis.left_swing_to_angle(45);
  }
