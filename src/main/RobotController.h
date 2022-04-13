/**
 * @file RobotController.h
 * @brief Controls robot systems
 */
#include "ServoController.h"
#include "PS3Controller.h"

#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H


class RobotController {
    private:
    /**
     * @brief Controller for robot's servos
     */
    ServoController servo_controller;

    public:
    /**
     * @brief Constructs a new RobotController object
     */
    RobotController();

    /**
     * @brief Setup task for robot. Should run in setup().
     */
    void setupTask();

    /**
     * @brief Loop task for robot. Should run in loop().
     */
    void loopTask();

    // could make setServoTargets private and use a "useInputs" function
    /**
     * @brief Set servo targets using an 8-bit integer array
     * @param arr 8-bit integer array
     * @param arr_size Size of arr
     */
    void setServoTargets(uint8_t* arr, uint8_t arr_size);
    
    /**
     * @brief Adds a servo to the servo controller
     * @param port Port of servo
     */
    void addServo(uint8_t port);
};


#endif // ROBOTCONTROLLER_H
