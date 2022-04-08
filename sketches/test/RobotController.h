#include "ServoController.h"
#include "PS3Controller.h"

#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H


class RobotController {
    private:
    // can be changed for each bot
    uint8_t* input_values;
    ServoController servo_controller;
    //PS3Controller ps3_controller;

    public:
    RobotController();

    // todo: fix this shit
    void setServoTargets();
    void getPS3Inputs();
    void addServo(uint8_t port);
    void doStuff();
};


#endif // ROBOTCONTROLLER_H
