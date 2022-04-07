//#include "RobotController.h"
#include "Servo.h"
#include "PS3Controller.h"

//RobotController robot;

PS3Controller cont;
Servo servo(0);

void setup() {
    Serial.begin(9600);

    cont.waitForConnection();
    //robot.addServo(0);
}


void loop() {
    cont.updateControllerState();
    Serial.print(cont.getControllerState()[0]);
}
