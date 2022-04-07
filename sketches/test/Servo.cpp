#include "Servo.h"

#define MIN_PULSE_WIDTH       650
#define MAX_PULSE_WIDTH       2100
#define FREQUENCY             50


Servo::Servo()
{
    port = -1;
    target = 0;

    pwm = Adafruit_PWMServoDriver();

    pwm.begin();
    pwm.setPWMFreq(FREQUENCY);
}


Servo::Servo(uint8_t port)
{
    this->port = port;
    this->target = 0;

    pwm = Adafruit_PWMServoDriver();

    pwm.begin();
    pwm.setPWMFreq(FREQUENCY);
}


void Servo::setTarget(uint8_t target)
{
    this->target = target;
}


void Servo::setTargetByPercent(uint8_t target)
{
    this->setTarget(map(target, 0, 100, 0, 255));
}


void Servo::moveToTarget()
{
    // todo: not use int
    int pulse_wide = map(target, 0, 255, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
    int pulse_width = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);

    pwm.setPWM(port, 0, pulse_width);
}


