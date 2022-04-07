#include "PS3Controller.h"

PS3Controller::PS3Controller() : Btd(&Usb), PS3(&Btd)
{
    return;
}

uint8_t* PS3Controller::getControllerState()
{
    return controller_state;
}


void PS3Controller::waitForConnection()
{
    do
    {
        Usb.Task();
    }
    while (!PS3.PS3Connected);
}

void PS3Controller::updateControllerState()
{
    uint8_t val = PS3.getAnalogButton(L2);
    Serial.print(val);
    controller_state[0] = val;
}