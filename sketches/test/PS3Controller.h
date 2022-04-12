#include <PS3BT.h>


#ifndef PS3CONTROLLER_H
#define PS3CONTROLLER_H


class PS3Controller {
    private:
    extern uint8_t controller_state[3];
    USB Usb;
    BTD Btd;
    PS3BT PS3;
    
    void updateControllerState();

    public:
    PS3Controller();

    uint8_t* getControllerState();

    bool setupTask();
    void loopTask();
};

#endif // PS3CONTROLLER_H
