#include "Servo.h"

#define MAX_SERVOS 4

#ifndef SERVOCONTROLLER_H
#define SERVOCONTROLLER_H


class ServoController {
    private:
    /**
     * @brief Size of the servos array
     */
    uint8_t servos_size;
    /**
     * @brief Stores every servo object managed
     */
    Servo servos[MAX_SERVOS];

    public:
    /**
     * @brief Constructs a new ServoController object
     */
    ServoController();

    /**
     * @brief Setup function
     */
    void setup();

    /**
     * @brief Create a new servo
     * @param port Port of new servo
     */
    void addServo(uint8_t port);

    /**
     * @brief Drives every managed servo
     */
    void driveServos();

    /**
     * @brief Set the target of a specific servo by 8-bit integer
     * @param servo_index Servo to set
     * @param target Target to set, 8-bit integer
     */
    void setTarget(uint8_t servo_index, uint8_t target);
    /**
     * @brief Set the target of a specific servo by percent
     * @param servo_index Servo to set
     * @param target Target to set, 0-100 
     */
    void setTargetByPercent(uint8_t servo_index, uint8_t target);

    /**
     * @brief Set the servo targets given an array of 8-bit integers
     * @param arr 8-bit integer array
     * @param arr_size Size of arr
     */
    void setTargetsByArray(uint8_t* arr, uint8_t arr_size);
};


#endif // SERVOCONTROLLER_H
