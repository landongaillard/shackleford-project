#include "PS3Controller.h"
//#include <SPI.h>

PS3Controller::PS3Controller() : Btd(&Usb), PS3(&Btd)
{

}


uint8_t* PS3Controller::getControllerState()
{
    return controller_state;
}


bool PS3Controller::setupTask()
{
    if (Usb.Init() == -1)
    {
        Serial.println("OSC did not start");
        return false;
    }

    return true;
}


void PS3Controller::loopTask()
{
    Usb.Task();

}

void PS3Controller::updateControllerState()
{
    uint8_t val = PS3.getAnalogButton(L2);
    Serial.println(val);
    controller_state[0] = val;
}