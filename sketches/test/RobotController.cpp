#include "RobotController.h"
// readd ps3 controlelr here
RobotController::RobotController() : servo_controller()
{

}


void RobotController::addServo(uint8_t port)
{
    servo_controller.addServo(port);
}


void RobotController::doStuff()
{
    servo_controller.driveServos();
}


void RobotController::setServoTargets()
{
    // not finished
    servo_controller.setTargetByPercent(0, input_values[0]);
}


void RobotController::getPS3Inputs()
{
    //input_values = ps3_controller.getControllerState();
}

