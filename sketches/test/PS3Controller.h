#include <PS3BT.h>

#define STATE_ARRAY_SIZE 3

#ifndef PS3CONTROLLER_H
#define PS3CONTROLLER_H


class PS3Controller {
    private:
    bool connected;
    uint8_t controller_state[STATE_ARRAY_SIZE];

    USB Usb;
    BTD Btd;
    PS3BT PS3;
    
    public:
    PS3Controller();

    bool isConnected();

    void updateControllerState();
    uint8_t* getControllerState();

    bool setupTask();
    void loopTask();
};

#endif // PS3CONTROLLER_H
