#include "ServoController.h"
#include "Servo.h"


ServoController::ServoController()
{
    servos_size = 0;
}


void ServoController::setup()
{
    for(uint8_t i = 0; i < servos_size; i++)
    {
        servos[i].setup();
    }
}


bool ServoController::addServo(uint8_t port)
{
    Servo new_servo(port);
    servos[servos_size] = new_servo;
    servos_size++;
}


void ServoController::driveServos()
{
    for(uint8_t i = 0; i < servos_size; i++)
    {
        servos[i].moveToTarget();
    }
}


void ServoController::setTarget(uint8_t servo_index, uint8_t target)
{
    servos[servo_index].setTarget(target);
}

void ServoController::setTargetByPercent(uint8_t servo_index, uint8_t target)
{
    servos[servo_index].setTargetByPercent(target);
}