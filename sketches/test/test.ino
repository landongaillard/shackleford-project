#include "ServoController.h"

ServoController *servos;


void setup() {
    Serial.begin(9600);

    // todo: see if can do this out setup
    servos = new ServoController();
    servos->addServo(0);
    servos->setTargetByPercent(0, 100);
}


void loop() {
    servos->driveServos();
}
