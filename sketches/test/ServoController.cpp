#include "ServoController.h"
#include "Servo.h"


ServoController::ServoController()
{
    servos_size = 0;
}


bool ServoController::addServo(uint8_t port)
{
    if(servos_size + 1 > MAX_SERVOS)
    {
        return false;
    }
    else
    {
        servos[servos_size] = Servo(port);
        servos_size++;
        return true;
    }
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