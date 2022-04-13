/**
 * @file PS3Controller.h
 * @author Landon Gaillard (landon.gaillard@gmail.com)
 * @brief Class for PS3 controller usage.
 * 
 */

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
    /**
     * @brief Construct a new PS3Controller object
     * 
     */
    PS3Controller();

    /**
     * @brief Returns controller connection state
     * 
     * @return true Controller is connected
     * @return false Controller is disconnected
     */
    bool isConnected();

    void updateControllerState();
    uint8_t* getControllerState();

    bool setupTask();
    void loopTask();
};

#endif // PS3CONTROLLER_H
