/**
 * @file Servo.h
 * @brief Controls individual servo
 */

#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>

#ifndef SERVO_H
#define SERVO_H


class Servo {
    private:
    /**
     * @brief Stores the port of the servo
     */
    uint8_t port;

    /**
     * @brief Servo's current target
     */
    uint8_t target;

    /**
     * @brief PWM driver object
     */
    Adafruit_PWMServoDriver pwm;

    public:
    /**
     * @brief Construct a new Servo object
     */
    Servo();

    /**
     * @brief Construct a new Servo object
     * @param port Port of the servo
     */
    Servo(uint8_t port);

    /**
     * @brief Setup function. Should always run in setup().
     */
    void setup();

    /**
     * @brief Set the servo's target as an 8-bit integer
     * @param target 8-bit integer target
     */
    void setTarget(uint8_t target);

    /**
     * @brief Set the servo's target with a 0-100 value
     * @param target 0-100 integer target
     */
    void setTargetByPercent(uint8_t target);

    /**
     * @brief Drives servo to target
     */
    void moveToTarget();
};


#endif // SERVO_H
