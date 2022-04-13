#include "RobotController.h"

RobotController::RobotController()
{

}


void RobotController::setupTask()
{
    servo_controller.setup();
}


void RobotController::addServo(uint8_t port)
{
    servo_controller.addServo(port);
}


void RobotController::loopTask()
{
    servo_controller.driveServos();
}


void RobotController::setServoTargets(uint8_t* arr, uint8_t arr_size)
{
    servo_controller.setTargetsByArray(arr, arr_size);
}

