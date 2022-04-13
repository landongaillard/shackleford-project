#include "RobotController.h"
#include <PS3BT.h>

RobotController bot;

USB Usb;
BTD Btd(&Usb);
PS3BT PS3(&Btd);

uint8_t arr[3];

void setup() {
    Serial.begin(115200);

    // check if usb opened
    if (Usb.Init() == -1)
    {
        Serial.println("OSC did not start");
        // halt program
        while (1);
    }
    Serial.println("PS3 Bluetooth Library Started");

    bot.addServo(0);
    bot.addServo(1);
    bot.addServo(2);

    bot.setup();
}


void loop() {
    //Serial.println("test");

    Usb.Task();
    if(PS3.PS3Connected)
    {
        //Serial.println(PS3.getAnalogButton(R2));
        arr[0] = PS3.getAnalogButton(R2);
        arr[1] = PS3.getAnalogHat(LeftHatX);
        arr[2] = PS3.getAnalogHat(RightHatX);
        bot.setServoTargets(arr);
        bot.loopTask();
    }
}
