#include "Servo.h"

#define MAX_SERVOS 4

#ifndef SERVOCONTROLLER_H
#define SERVOCONTROLLER_H


class ServoController {
    private:
    uint8_t servos_size;
    Servo servos[MAX_SERVOS];

    public:
    ServoController();

    bool addServo(uint8_t port);

    void driveServos();
    void setTarget(uint8_t servo_index, uint8_t target);
    void setTargetByPercent(uint8_t servo_index, uint8_t target);
};


#endif // SERVOCONTROLLER_H
