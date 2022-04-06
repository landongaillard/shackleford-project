#include "ServoController.h"
#include "Servo.h"

ServoController::ServoController()
{

}

void ServoController::addServo(int port)
{
    servo_arr[0] = Servo(port)
}

void ServoController::driveServos()
{
    int arr_size = 1;
    for(int i = 0; i < arr_size; i++)
    {
        servo_arr[i].moveToTarget();
    }
}