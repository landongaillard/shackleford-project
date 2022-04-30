#include "RobotController.h"

RobotController::RobotController()
{
    // pass
}


void RobotController::setupRobotController()
{
    servo_controller.setupServoController();
}


void RobotController::addServo(uint8_t port)
{
    servo_controller.addServo(port);
}


void RobotController::loopTask()
{
    servo_controller.driveServos();
}

// todo: make sure this passes the array like its supposed to
// god i hate c++ arrays
void RobotController::controlByArray(uint8_t *arr, uint8_t arr_size)
{
    servo_controller.setTargetsByArray(arr, arr_size);
}