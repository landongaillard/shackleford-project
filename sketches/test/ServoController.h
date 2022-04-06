#include "Servo.h"

#ifndef SERVOCONTROLLER_H
#define SERVOCONTROLLER_H


class ServoController {
    private:
    Servo servo_arr[1];
    public:
    ServoController();

    void addServo(int port);

    void driveServos();
};

#endif // SERVOCONTROLLER_H
