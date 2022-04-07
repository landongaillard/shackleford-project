#include <PS3BT.h>


#ifndef PS3CONTROLLER_H
#define PS3CONTROLLER_H


class PS3Controller {
    private:
    uint8_t controller_state[3] = {0, 0, 0};

    USB Usb;
    BTD Btd;
    PS3BT PS3;
    
    public:
    PS3Controller();

    uint8_t* getControllerState();

    void waitForConnection();
    void updateControllerState();
    
};

#endif // PS3CONTROLLER_H
