
#ifndef PS3CONTROLLER_H
#define PS3CONTROLLER_H


class PS3Controller {
    private:
    uint8_t controllerState[3];
    
    public:
    PS3Controller();

    uint8_t* getControllerState();

    void updateControllerState();
    
};

#endif // PS3CONTROLLER_H
