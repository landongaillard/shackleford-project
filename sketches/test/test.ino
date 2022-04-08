#include "RobotController.h"
#include "PS3Controller.h"

RobotController* robot;
PS3Controller* cont;


void setup() {
    Serial.begin(115200);
    Serial.println("test");
    robot = new RobotController;
    Serial.println("test2");
    cont = new PS3Controller;
    Serial.println("test3");
    //robot->addServo(0);
    Serial.println("test4");
    robot->addServo(0);
}


void loop() {
    cont->waitForConnection();
    //cont->updateControllerState();

    //robot->doStuff();
    //cont.updateControllerState();
    //Serial.print(cont.getControllerState()[0]);
}
