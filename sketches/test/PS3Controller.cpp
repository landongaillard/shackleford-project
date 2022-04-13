#include "PS3Controller.h"

// try : Usb() ...
PS3Controller::PS3Controller() : Btd(&Usb), PS3(&Btd)
{
    connected = false;
}


bool PS3Controller::isConnected()
{
    return connected;
}


void PS3Controller::updateControllerState()
{
    controller_state[0] = PS3.getAnalogButton(R2);
    controller_state[1] = PS3.getAnalogHat(LeftHatX);
    controller_state[2] = PS3.getAnalogHat(RightHatX);
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
    Serial.println("Bluetooth ready");
    return true;
}


void PS3Controller::loopTask()
{
    Usb.Task();
    if(PS3.PS3Connected)
    {
        connected = true;
        updateControllerState();
    }
    else
    {
        connected = false;
    }
}
