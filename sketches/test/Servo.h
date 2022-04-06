#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>

#ifndef SERVO_H
#define SERVO_H


class Servo{
    private:
    // port of servo
    int port;
    // current servo target, in percent (e.g 100%, 50%)
    int target;
    // pwm driver
    Adafruit_PWMServoDriver pwm;

    public:
    Servo(int port);

    void setTarget(int target);

    void moveToTarget();
};

#endif // SERVO_H
