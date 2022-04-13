#include "RobotController.h"
#include <PS3BT.h>
#include "PS3Controller.h"

RobotController robot;
PS3Controller ps3;

uint8_t default_arr[3] = {0, 0, 0};


void setup() {
    Serial.begin(115200);

    robot.addServo(0);
    robot.addServo(1);
    robot.addServo(2);

    robot.setupTask();
    ps3.setupTask();
}


void loop() {
    ps3.loopTask();

    if(ps3.isConnected())
    {
        robot.setServoTargets(ps3.getControllerState(), STATE_ARRAY_SIZE);
    }
    else
    {
        robot.setServoTargets(default_arr, STATE_ARRAY_SIZE);
    }

    robot.loopTask();
}
