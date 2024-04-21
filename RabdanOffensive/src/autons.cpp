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
    wait(.15, seconds);
    
    //get 6 point ball!!!
    intake.spin(forward);
    chassis.drive_distance(11);

    //go back to match load
    chassis.drive_distance(-49,-10,12,12,2,25,3500);//old-38
    //chassis.DriveR.spin(reverse,6,volt);
    //chassis.DriveL.spin(reverse,6,volt);
    //wait(1.55, seconds); //1.25
    //chassis.DriveR.stop(vex::brakeType::coast);
    //chassis.DriveL.stop(vex::brakeType::coast);
    //chassis.turn_to_angle(-35, 12, 10, 200, 1350); //-45
    //wait(0.1, sec);
    BackWingRight.set(true);
    BackWingLeft.set(false);
    //chassis.drive_distance(-15); 

    //flick ball
    chassis.DriveL.spin(reverse); //old forward
    wait(.5, seconds); //1
    //BackWings.set(false);
    BackWingLeft.set(true);
    chassis.DriveR.stop();
    chassis.DriveL.stop();
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
    chassis.turn_to_angle(-50, 12, 10, 200, 1350); //old -60
    BackWingLeft.set(false);
    BackWingRight.set(true);
    chassis.DriveL.spin(reverse);
    chassis.DriveR.spin(reverse);
    wait(0.75, sec);
    chassis.DriveL.stop();
    chassis.DriveR.stop();
    chassis.drive_distance(10);

    //chassis.drive_distance(-5); //maibe
    BackWingLeft.set(false);
    BackWingRight.set(false);
    chassis.turn_to_angle(110, 12, 10, 200, 1350);  
    intake.spin(reverse,12,volt);
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
    intake.spin(forward,12,volt);
    chassis.drive_distance(49); //old 46
    

    //go back
    chassis.drive_distance(-5);
    intake.stop();
    
    //throw ball B3
    //chassis.turn_to_angle(float angle, float turn_max_voltage, float turn_settle_error, float turn_settle_time, float turn_timeout)
    chassis.turn_to_angle(-38 + AngleOffset, 12, 10, 200, 1350); //1500 last constant //-48 degrees //-42
    //wait(0.25, seconds);
    intake.spin(reverse,10,volt);
    chassis.drive_distance(5,-38 + AngleOffset,12,12,1,15,1000);
    chassis.drive_distance(-5,-38 + AngleOffset,12,12,1,15,1000);

    intake.spin(forward);
    chassis.turn_to_angle(-110 + AngleOffset); //old -115 /-105

    chassis.drive_distance(23,-110 + AngleOffset,8,12,1,25,2500); //old 21
    //chassis.left_swing_to_angle(0); //old -5

    //(float angle, float swing_max_voltage, float swing_settle_error, float swing_settle_time, float swing_timeout, float swing_kp, float swing_ki, float swing_kd, float swing_starti);
    //chassis.left_swing_to_angle(10, 12, 10, 300, 1500, .3, 0, 2, 15);
    chassis.turn_to_angle(180, 12, 2.5, 50, 2500);
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

void Defensive_MatchLoad(){
    intake.setBrake(hold);
  intake.setVelocity(100, percent);
  intake.setMaxTorque(100, percent);
  leftwing.set(true);

  //chassis.left_swing_to_angle(20,12,1,150,1500,.3, .002, 2, 15);
  //chassis.turn_to_angle(20);
  intake.spin(forward);
  chassis.drive_distance(44,8,12,9,2,250,3500); //7 degree //45in
  leftwing.set(false);
  chassis.drive_distance(-25,25,8,9,2,25,3500);
  chassis.drive_distance(-32,0,8,9,2,25,3500);
  //intake.stop();
  chassis.turn_to_angle(90,12,3,150,2000);
  intake.spin(reverse,12,volt);
  chassis.drive_distance(5,90,12,12,1,5,1000);
  chassis.drive_distance(-10,90,12,12,1,25,1000);
  chassis.turn_to_angle(-60,12,3,25,1500); //-50
  chassis.drive_distance(28,-45,12,12,2,50,1500); //30

  //chassis.drive_distance(-15);
  chassis.left_swing_to_angle(-10,12,3,25,1500,.3, .001, 2, 15);
  //independant
  chassis.drive_distance(-5,-10,12,12,1,25,1500);
  intake.spin(reverse);
  chassis.DriveL.spin(forward);
  chassis.DriveR.spin(forward);
  wait(.6, sec);
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
  rightwing.set(true);
  chassis.drive_distance(38,105,12,9,1,150,2000); //90dg //95dg //105dg //37.5in//38in
  intake.stop(brakeType::coast);
  rightwing.set(false);
  chassis.drive_distance(-40,100,12,12,2,25,2000);
  //BackWingRight.set(true);
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

void DefensiveMatchLoad(){
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
    catapult.setVelocity(100, percent);
    Catapult5W.setVelocity(100, percent);
    catapult.setMaxTorque(100, percent);
    Catapult5W.setMaxTorque(100, percent);
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
    //wait(.05, seconds);
    

    //go to match load bar
    chassis.drive_distance(-2,0,12,12,1,25,500);
    chassis.turn_to_angle(-30,12,1,50,600); //old 30
    rightwing.set(false);
    leftwing.set(false);
    chassis.drive_distance(17,-30,12,12,1,50,600);
    chassis.turn_to_angle(-170,12,1,50,600);
    chassis.drive_distance(-1,-155,12,12,1,25,500);
    BackWingLeft.set(true);
    BackWingRight.set(true);
    chassis.DriveL.stop(vex::brakeType::brake);
    chassis.DriveR.stop(vex::brakeType::brake);

    //catapultt
    intake.stop();
    catapult.spin(forward,12,volt);
    Catapult5W.spin(forward,12,volt);
    wait(29, sec);
    catapult.stop(brakeType::coast);
    Catapult5W.stop(brakeType::coast);
    BackWingLeft.set(false);
    BackWingRight.set(false);
    intake.spin(reverse);
    //go to left from the goal
    chassis.drive_distance(4,-155,12,12,1,25,1000);
    chassis.turn_to_angle(-55,12,2,100,1000); //135 //-45
    chassis.drive_distance(-25,-45,12,12,1,25,2000);//29
    chassis.turn_to_angle(-0.5,12,1,300,3000);//179
    intake.spin(forward);
    chassis.drive_distance(-78,0,12,12,1,250,5000);
    intake.spin(reverse);
    rightwing.set(false);
    leftwing.set(false);
    BackWingLeft.set(true);
    wait(.2, sec);
    chassis.right_swing_to_angle(55,10,3,100,750,.3, .001, 2, 15); //-135 //45
    intake.spin(reverse);

    chassis.DriveR.spin(reverse,12,volt);
    chassis.DriveL.spin(reverse,12,volt);
    wait(1, seconds);
    chassis.DriveR.stop(brakeType::coast);
    chassis.DriveL.stop(brakeType::coast);
    chassis.drive_distance(10,85,12,12,2,24,1000);

    //chassis.drive_distance(-20,45,12,12,2,300,1000);
    chassis.right_swing_to_angle(75,12,3,100,750,.3, .001, 2, 15); //old -90
    //chassis.drive_distance(5,80,12,12,2,5,750);
    //chassis.drive_distance(-10);//-100,12,12,3,100,750
    //rightwing.set(false);
    //leftwing.set(false);
  

    chassis.DriveR.spin(reverse,12,volt);
    chassis.DriveL.spin(reverse,12,volt);
    wait(.75, seconds);
    chassis.DriveR.stop(brakeType::coast);
    chassis.DriveL.stop(brakeType::coast);
    rightwing.set(false);
    leftwing.set(false);
    
    //go away from goal
    
    chassis.drive_distance(10); //,-100,12,12,3,100,750

    chassis.DriveR.spin(reverse,12,volt);
    chassis.DriveL.spin(reverse,12,volt);
    wait(0.75, seconds);
    chassis.DriveR.stop(brakeType::coast);
    chassis.DriveL.stop(brakeType::coast);

    rightwing.set(false);
    leftwing.set(false);
    chassis.drive_distance(8,90,12,12,1,25,1000);
    wait(0.15, sec);


   chassis.turn_to_angle(170,12,2,100,3000);
   chassis.drive_distance(-12,175,12,12,2,25,1000);
   BackWingLeft.set(true);
   BackWingRight.set(true);
   chassis.drive_distance(-25,180,12,12,2,300,1500); //-34 //175 degree
   BackWingLeft.set(true);
    BackWingRight.set(true);
   chassis.left_swing_to_angle(45,12,2,50,600,.3, .001, 2,15); //-70 //45
   BackWingLeft.set(true);
   chassis.drive_distance(-40,45,9,6,3,100,1000); //-48 
   chassis.left_swing_to_angle(0,12,5,50,500,.3, .001, 2, 15);
   
   
    chassis.DriveR.spin(reverse,12,volt);
    chassis.DriveL.spin(reverse,12,volt);
    wait(.5, seconds);
    chassis.DriveR.stop(brakeType::coast);
    chassis.DriveL.stop(brakeType::coast);
    chassis.drive_distance(10,0,9,12,1,25,2000);
    chassis.DriveR.spin(reverse,12,volt);
    chassis.DriveL.spin(reverse,12,volt);
    wait(.75, seconds);
    chassis.DriveR.stop(brakeType::coast);
    chassis.DriveL.stop(brakeType::coast);

    chassis.drive_distance(20,0,6,6,2,25,2000);
    chassis.drive_distance(10,-45,12,12,2,100,750);

    chassis.left_swing_to_angle(-1,12,3,25,1000,.3, .001, 2, 15);
    BackWingLeft.set(true);
    BackWingRight.set(true);
    leftwing.set(false);
    chassis.DriveR.spin(reverse,12,volt);
    chassis.DriveL.spin(reverse,12,volt);
    wait(1, seconds);
    chassis.DriveR.stop(brakeType::coast);
    chassis.DriveL.stop(brakeType::coast);
    leftwing.set(false);
    rightwing.set(false);
    chassis.drive_distance(25,0,12,12,2,150,2000); //-15
    wait(0.1, sec);

    BackWingLeft.set(false);
    BackWingRight.set(false);
    leftwing.set(false);
    rightwing.set(false);
    BackWingLeft.set(true);
    chassis.right_swing_to_angle(50,12,2,150,750,.3, .001, 2, 15); //-115
    chassis.drive_distance(-44,50,12,12,2,150,2000);  //-50
    chassis.left_swing_to_angle(-60,12,2,50,1500,.3, .001, 2, 15); //130 //-50 degree
    //chassis.drive_distance(-10);
    BackWingLeft.set(false);
    BackWingRight.set(true);
    //chassis.drive_distance(-30,-75,12,12,2,50,1500); //15
    chassis.drive_distance(-5,-75,12,12,2,50,1500);
    chassis.left_swing_to_angle(-55,12,5,50,750,.3, .001, 2, 15);
    
     chassis.DriveR.spin(reverse,12,volt);
    chassis.DriveL.spin(reverse,12,volt);
    wait(0.75, seconds);
    chassis.DriveR.stop();
    chassis.DriveL.stop();
    chassis.drive_distance(10,-90,12,12,3,25,1000);
    //chassis.drive_distance(20);
    //chassis.drive_distance(5,-85,12,12,3,25,500); //15

    chassis.DriveR.spin(reverse,12,volt);
    chassis.DriveL.spin(reverse,12,volt);
    wait(.75, seconds);
    chassis.DriveR.stop(brakeType::coast);
    chassis.DriveL.stop(brakeType::coast);

    chassis.drive_distance(10,-80,12,12,2,25,1000);
    chassis.DriveR.spin(reverse,12,volt);
    chassis.DriveL.spin(reverse,12,volt);
    wait(.5, seconds);
    chassis.DriveR.stop(brakeType::coast);
    chassis.DriveL.stop(brakeType::coast);
    chassis.drive_distance(15,-80,12,12,2,25,750);
}


void NoAuton(){
  chassis.drive_distance(24);
  chassis.drive_distance(-24);
  chassis.turn_to_angle(-90);
  chassis.turn_to_angle(90);
}

void Offensive_5_Point_Rush(){
  L1.setBrake(coast);
  L2.setBrake(coast);
  L3.setBrake(coast);
  R1.setBrake(coast);
  R2.setBrake(coast);
  R3.setBrake(coast);
  intake.setBrake(hold);
  intake.setVelocity(100, percent);
  intake.setMaxTorque(100, percent);
  intake.spin(forward,12,volt);
  rightwing.set(true);

  chassis.drive_distance(45,-10,12,10,2,350,5000); //150mm  settle time
  rightwing.set(false);
  chassis.drive_distance(-44,-20,10,10,2,50,5000); //-50 //-49 //-43



  //intake.spin(reverse,5,volt);
  
  intake.spin(forward,12,volt);
  chassis.left_swing_to_angle(-100,9,3,25,525,.3, .001, 2, 15); //725ms
  BackWingLeft.set(true);
  //garbagenumbersniq
  chassis.drive_distance(-5.75,-110,12,12,1,25,500); //-45,angle -100 //-47 angle //-16 //-11 in


  /*BackWingLeft.set(true);
  chassis.left_swing_to_angle(-90,12,3,150,1500,.3, .001, 2, 15);*/
  //BackWingLeft.set(true);
  //chassis.drive_distance(-6,-140,12,12,2,50,1500);
  //chassis.turn_to_angle(-170,12,3,50,750);
  
  //flick ball out
  BackWingRight.set(true);
  chassis.DriveL.spin(reverse,12,volt);
  wait(0.2,sec);
  chassis.DriveL.stop(brakeType::brake);
  wait(0.015, seconds);
  chassis.left_swing_to_angle(-152.5,12,3,25,350,.3, .001, 2, 15); //-145
  intake.spin(forward,12,volt);
  BackWingLeft.set(false);
  BackWingRight.set(true);
  chassis.drive_distance(-7,-152.5,12,12,2,25,1000);
  //chassis.drive_distance(-30,-155,12,12,5,5,550);
  //chassis.drive_distance(-2.5,-145,12,12,1,25,250);
  //chassis.drive_distance(-5,-155,12,12,2,25,250); //-145 degree
  //chassis.drive_distance(-30,-160,12,12,5,25,450); //1000ms
  
  chassis.DriveR.spin(reverse);
  chassis.DriveL.spin(reverse);
  wait(.55, sec);
  chassis.DriveR.stop();
  chassis.DriveL.stop();
  

  BackWingRight.set(false);
  chassis.drive_distance(5,-177.5,12,12,3,25,750);
  chassis.turn_to_angle(40,12,3,25,1500);//30degree

  leftwing.set(false);
  intake.spin(reverse,12,volt);
  //chassis.drive_distance(5,27.5,12,12,2,25,350);
  chassis.drive_distance(30,10,12,12,5,10,550); //1000

  /*
  chassis.DriveR.spin(forward);
  chassis.DriveL.spin(forward);
  wait(.65, sec);
  chassis.DriveR.stop();
  chassis.DriveL.stop();
  */
  
  leftwing.set(false);
  chassis.drive_distance(-10,0,12,12,1,25,1000);


  chassis.turn_to_angle(-72,10,1,50,1000); //12volts loooooooooooooooool //-72.5degree //-70
  //pickupandthrowtriballandgetotherone
  intake.spin(forward,12,volt);
  chassis.drive_distance(49,-73.5,12,12,2,200,2000); //100ms timeout //46in

  chassis.turn_to_angle(45,12,3,50,1000); //70 //45dg
  leftwing.set(true);
  intake.spin(reverse,6,volt); //8volt
  intake.setBrake(coast);
  //chassis.drive_distance(35,70,12,12,3,25,1000);
  chassis.drive_distance(15,65,12,12,2,25,1000);
  chassis.DriveR.spin(forward,12,volt);
  chassis.DriveL.spin(forward,12,volt);
  wait(.6, sec);
  chassis.DriveR.stop(brakeType::coast);
  chassis.DriveL.stop(brakeType::coast);
  //chassis.drive_distance(-20,45,12,12,2,50,1250);
  leftwing.set(false);
  chassis.turn_to_angle(-67,10,2,100,2000);
  /*
  chassis.drive_distance(7.5,70,12,12,2,25,1000); //87.5 degree
  */
  //otherone
  //chassis.turn_to_angle(-34,12,2,50,1000); //-37.5
  intake.spin(forward,12,volt);
  chassis.drive_distance(25,-67,12,12,2,100,1000); //-35 //23in //-70 heading
  chassis.turn_to_angle(90,12,2,15,1500);
  rightwing.set(true);
  leftwing.set(true);
  intake.spin(reverse,12,volt);


  ////independent motor
    intake.stop(brakeType::coast);
    chassis.DriveR.spin(forward,12,volt);
    chassis.DriveL.spin(forward,12,volt);
    wait(0.7, sec); //.75
    chassis.DriveR.stop();
    chassis.DriveL.stop();
    BackWingLeft.set(false);
    leftwing.set(false);
    rightwing.set(false);
  //chassis.drive_distance(40,90,12,12,3,50,1000);

  
  chassis.turn_to_angle(-145,12,1,50,1000); //-142.5
  L1.setBrake(hold);
  L2.setBrake(hold);
  L3.setBrake(hold);
  R1.setBrake(hold);
  R2.setBrake(hold);
  R3.setBrake(hold);
  chassis.DriveR.spin(forward,12,volt);
  chassis.DriveL.spin(forward,12,volt);
  wait(3, sec);
  chassis.DriveR.stop(brakeType::hold);
  chassis.DriveL.stop(brakeType::hold);

  //chassis.drive_distance(-110,25,12,12,5,50,1000);
  rightwing.set(false);
  leftwing.set(false);
  
}

void Defensive_AWP(){
  intake.setBrake(hold);
  intake.setVelocity(100, percent);
  intake.setMaxTorque(100, percent);
  leftwing.set(true);

  //chassis.left_swing_to_angle(20,12,1,150,1500,.3, .002, 2, 15);
  //chassis.turn_to_angle(20);
  intake.spin(forward);
  chassis.drive_distance(44,8,12,9,2,650,3500); //7 degree //45in
  leftwing.set(false);
  chassis.drive_distance(-25,25,8,9,2,150,3500);
  chassis.drive_distance(-32,0,8,9,2,150,3500);
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
  chassis.drive_distance(38,90,12,9,1,150,2500); //37.5
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

void Offensive6PointRush(){
  L1.setBrake(coast);
  L2.setBrake(coast);
  L3.setBrake(coast);
  R1.setBrake(coast);
  R2.setBrake(coast);
  R3.setBrake(coast);
  intake.setBrake(hold);
  intake.setVelocity(100, percent);
  intake.setMaxTorque(100, percent);
  intake.spin(forward,12,volt);
  rightwing.set(true);

  chassis.drive_distance(44,-10,12,12,2,250,2000); //150mm  settle time
  rightwing.set(false);
  chassis.drive_distance(-47,-20,11,10,2,50,2000); //-50 //-49


  //intake.spin(reverse,5,volt);
  intake.spin(reverse,6,volt);
  chassis.right_swing_to_angle(90,12,3,25,525,.3, .001, 2, 15); //725ms
  intake.spin(reverse,12,volt);
  chassis.turn_to_angle(-90,8,1,50,3000); //12voltfunnnnn

  intake.spin(forward,12,volt);
  chassis.drive_distance(32,-90,8,12,2,250,35000);

  chassis.drive_distance(-44,-100,12,12,1,50,3500); //-45,angle -100 //-47 angle


  BackWingLeft.set(true);
  /*chassis.left_swing_to_angle(-140,12,3,150,1500,.3, .001, 2, 15);
  
  chassis.drive_distance(-10,-140,12,12,2,50,1500);*/
  //chassis.turn_to_angle(-170,12,3,50,750);

  //flick ball out
  BackWingRight.set(true);
  chassis.DriveL.spin(reverse,12,volt);
  wait(0.4,sec);
  chassis.DriveL.stop(brakeType::brake);
  wait(0.015, seconds);
  chassis.left_swing_to_angle(-152.5,12,3,25,350,.3, .001, 2, 15); //-145
  intake.spin(forward,12,volt);

  //chassis.left_swing_to_angle(-145,12,3,15,400,.3, .001, 2, 15); //-160
  intake.spin(forward,12,volt);
  BackWingLeft.set(false);
  BackWingRight.set(true);
  chassis.drive_distance(-10,-147,12,12,2,25,250); //-145 degree
  //chassis.drive_distance(-30,-160,12,12,5,25,450); //1000ms
  
  chassis.DriveR.spin(reverse);
  chassis.DriveL.spin(reverse);
  wait(.5, sec);
  chassis.DriveR.stop();
  chassis.DriveL.stop();
  BackWingRight.set(false);
  chassis.drive_distance(10,180,12,12,3,25,750);
  chassis.turn_to_angle(40,12,3,25,2000);//30degree

  leftwing.set(false);
  intake.spin(reverse,12,volt);
  chassis.drive_distance(5,27.5,12,12,2,10,350);
  chassis.drive_distance(25,5,12,12,5,10,550); //1000

  /*
  chassis.DriveR.spin(forward);
  chassis.DriveL.spin(forward);
  wait(.65, sec);
  chassis.DriveR.stop();
  chassis.DriveL.stop();
  */
  leftwing.set(false);
  chassis.drive_distance(-10,0,12,12,1,25,1000);


  chassis.turn_to_angle(-70,10,1,50,1000); //12volts loooooooooooooooool //-72.5degree
  //pickupandthrowtriballandgetotherone
  intake.spin(forward);
  chassis.drive_distance(45,-72.5,12,12,2,50,2000); //100ms timeout //46in
  chassis.turn_to_angle(67.5,12,3,50,1000); //70
  intake.spin(reverse,12,volt);
  chassis.drive_distance(7.5,70,12,12,2,25,1000); //87.5 degree
  //otherone
  intake.spin(forward,12,volt);
  chassis.turn_to_angle(-37.5,12,2,50,1000); //-37.5
  chassis.drive_distance(22,-36.5,12,12,2,50,1000); //-35 //23in
  chassis.turn_to_angle(90,12,3,50,1000);
  rightwing.set(true);
  leftwing.set(true);
  intake.spin(reverse);


  ////independent motor
    intake.spin(reverse,12,volt);
    chassis.DriveR.spin(forward,12,volt);
    chassis.DriveL.spin(forward,12,volt);
    wait(0.75, sec);
    chassis.DriveR.stop(brakeType::coast);
    chassis.DriveL.stop(brakeType::coast);
  //chassis.drive_distance(40,90,12,12,3,50,1000);
  //chassis.drive_distance(-30,90,12,12,5,50,1000);
  rightwing.set(false);
  leftwing.set(false);

  intake.stop(brakeType::coast);
  chassis.DriveR.spin(reverse,12,volt);
  chassis.DriveL.spin(reverse,12,volt);
  wait(0.75, sec);
  chassis.DriveR.stop(brakeType::coast);
  chassis.DriveL.stop(brakeType::coast);


  /*
  leftwing.set(true);
  chassis.drive_distance(40,60,12,12,3,50,1500);
  

  chassis.turn_to_angle(-75,12,3,50,1000);
  leftwing.set(false);
  intake.spin(forward);
  chassis.drive_distance(23,-75,12,12,2,50,1000);//20in
  chassis.turn_to_angle(90,12,3,50,1000);
  intake.spin(reverse,7,volt);

  //independent motor
  chassis.DriveR.spin(forward);
  chassis.DriveL.spin(forward);
  wait(0.75, sec);
  chassis.DriveR.stop();
  chassis.DriveL.stop();
  //chassis.drive_distance(25,90,12,12,3,50,1500);
  */



}

void AutonTest(){
    chassis.drive_distance(30);
    chassis.drive_distance(-30);
    chassis.right_swing_to_angle(-90);
    chassis.left_swing_to_angle(90);
    chassis.right_swing_to_angle(-45);
    chassis.left_swing_to_angle(45);
  }
