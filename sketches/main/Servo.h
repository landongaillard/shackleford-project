#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>

#ifndef SERVO_H
#define SERVO_H


class Servo {
    private:
    // port of servo
    uint8_t port;
    // current servo target as a 8 bit (0-255) integer
    uint8_t target;
    // pwm driver
    Adafruit_PWMServoDriver pwm;

    public:
    Servo();
    Servo(uint8_t port);

    void setup();
    // set target by 8 bit integer, 0-255
    void setTarget(uint8_t target);
    // set target by percent, 0-100
    void setTargetByPercent(uint8_t target);

    void moveToTarget();
};


#endif // SERVO_H
