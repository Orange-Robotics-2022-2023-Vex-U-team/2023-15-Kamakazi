/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Orangebot                                        */
/*    Created:      Wed Feb 08 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// ChassisLF            motor         16              
// ChassisLR            motor         6               
// ChassisRF            motor         15              
// ChassisRR            motor         5               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

void usercontrol() {
  while (true) {
    ChassisLF.spin(directionType::fwd,Controller1.Axis3.value()-Controller1.Axis4.value()+Controller1.Axis1.value()
  , velocityUnits::pct);
    ChassisRR.spin(directionType::fwd,Controller1.Axis3.value()-Controller1.Axis4.value()-Controller1.Axis1.value()
    , velocityUnits::pct);
    ChassisRF.spin(directionType::fwd,Controller1.Axis3.value()+Controller1.Axis4.value()-Controller1.Axis1.value()
    , velocityUnits::pct);
    ChassisLR.spin(directionType::fwd,Controller1.Axis3.value()+Controller1.Axis4.value()+Controller1.Axis1.value()
    , velocityUnits::pct);

    wait(20, msec);
  }
}

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
