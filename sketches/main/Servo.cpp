#include "Servo.h"

#define MIN_PULSE_WIDTH       800
#define MAX_PULSE_WIDTH       2200
#define FREQUENCY             50


Servo::Servo() : pwm()
{
    port = 255;
    target = 0;
}


Servo::Servo(uint8_t port) : pwm()
{
    this->port = port;
    target = 0;
}


void Servo::setup()
{
    // start up pwm and set frequency
    pwm.begin();
    pwm.setPWMFreq(FREQUENCY);
}


void Servo::setTarget(uint8_t target)
{
    this->target = target;
}


void Servo::setTargetByPercent(uint8_t target)
{
    setTarget(map(target, 0, 100, 0, 255));
}


void Servo::moveToTarget()
{
    // does some fancy math magic to drive servo
    // todo: see if int is overkill?
    int pulse_wide = map(target, 0, 255, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
    int pulse_width = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);

    // drive servo
    pwm.setPWM(port, 0, pulse_width);
}


