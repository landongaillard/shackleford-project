/**
 * @file RobotController.h
 * @brief Controls robot systems.
 */
#include "ServoController.h"

#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H


class RobotController {
    private:
    //! Controller for robot's servos.
    ServoController servo_controller;

    public:
    //! Constructs a new RobotController object.
    RobotController();

    //! Setup task for robot. Should run in setup().
    void setupRobotController();

    /**
     * @brief Performs loop tasks for RobotController. Should run every loop().
     * 
     * Performs tasks that need to run every loop, such as driving servos or
     * motors. Should be placed after the input has been updated and after
     * the controlByArray() function.
     * 
     */
    void loopTask();

    /**
     * @brief Adds a servo to the servo controller.
     * @param port Port of servo.
     */
    void addServo(uint8_t port);

    /**
     * @brief Controls the robot via an array of inputs.
     * @param arr 
     * @param arr_size 
     */
    void controlByArray(uint8_t *arr, uint8_t arr_size);
};


#endif // ROBOTCONTROLLER_H
