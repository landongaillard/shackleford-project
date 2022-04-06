#include "ServoController.h"

ServoController *servos;

void setup() {
    Serial.print("fml");
    // todo: see if can do this out setup
    servos = new ServoController();
}

void loop() {
    servos->driveServos();
}
