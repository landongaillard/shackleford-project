#include "ServoController.h"
#include "Servo.h"


ServoController::ServoController()
{
    servos_size = 0;
}


void ServoController::setupServoController()
{
    // setup every servo
    for(uint8_t i = 0; i < servos_size; i++)
    {
        servos[i].setupServo();
    }
}


void ServoController::addServo(uint8_t port)
{
    Servo new_servo(port);
    servos[servos_size] = new_servo;
    servos_size++;
}


void ServoController::driveServos()
{
    // drive every servo
    for(uint8_t i = 0; i < servos_size; i++)
    {
        servos[i].moveToTarget();
    }
}


void ServoController::setTarget(uint8_t servo_index, uint8_t target)
{
    servos[servo_index].setTarget(target);
}


void ServoController::setTargetsByArray(uint8_t* arr, uint8_t arr_size)
{
    // set target of every servo by index
    for(uint8_t i = 0; i < arr_size; i++)
    {
        servos[i].setTarget(arr[i]);
    }
}