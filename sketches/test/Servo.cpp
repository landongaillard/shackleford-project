#include "Servo.h"

#define MIN_PULSE_WIDTH       650
#define MAX_PULSE_WIDTH       2100
#define FREQUENCY             50


Servo::Servo(int port)
{
    this->port = port;
    this->target = 0;

    pwm = Adafruit_PWMServoDriver();

    pwm.begin();
    pwm.setPWMFreq(FREQUENCY);
}


void Servo::setTarget(int target)
{
    this->target = target;
}


void Servo::moveToTarget()
{
    int pulse_wide = map(target, 0, 100, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
    int pulse_width = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);

    pwm.setPWM(port, 0, pulse_width);
}