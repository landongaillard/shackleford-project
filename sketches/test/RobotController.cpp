#include "RobotController.h"
// readd ps3 controlelr here
RobotController::RobotController()
{
    //input_values = nullptr;
}


void RobotController::setup()
{
    servo_controller.setup();
}


void RobotController::addServo(uint8_t port)
{
    servo_controller.addServo(port);
}


void RobotController::doStuff()
{
    servo_controller.driveServos();
}


void RobotController::setServoTargets(uint8_t* arr)
{
    // not finished
    servo_controller.setTarget(0, arr[0]);
    servo_controller.setTarget(1, arr[1]);
    servo_controller.setTarget(2, arr[2]);
    //Serial.println(arr[0]);
}


void RobotController::getPS3Inputs()
{
    //input_values = ps3_controller.getControllerState();
}

