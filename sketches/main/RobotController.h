#include "ServoController.h"
#include "PS3Controller.h"

#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H


class RobotController {
    private:
    ServoController servo_controller;

    public:
    RobotController();

    void setupTask();
    void loopTask();

    // could make setServoTargets private and use a "useInputs" function
    void setServoTargets(uint8_t* arr, uint8_t arr_size);
    void addServo(uint8_t port);
};


#endif // ROBOTCONTROLLER_H
