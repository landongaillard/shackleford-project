#include "PS3Controller.h"
//#include <SPI.h>

PS3Controller::PS3Controller() : Btd(&Usb), PS3(&Btd)
{
    if (Usb.Init() == -1)
    {
        Serial.print(F("\r\nOSC did not start"));
        while (1); //halt
    }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));
}

uint8_t* PS3Controller::getControllerState()
{
    return controller_state;
}


void PS3Controller::waitForConnection()
{
    Usb.Task();

    if (PS3.PS3Connected)
    {
        Serial.println(map(PS3.getAnalogHat(RightHatX), 0, 255, 0, 100));
    }

    if (PS3.getButtonClick(UP)) {
        Serial.print(F("\r\nUp"));

        if (PS3.PS3Connected) {
            PS3.setLedOff();
            PS3.setLedOn(LED1);
        }

  }
}

void PS3Controller::updateControllerState()
{
    uint8_t val = PS3.getAnalogButton(L2);
    Serial.println(val);
    controller_state[0] = val;
}