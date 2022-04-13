/*
          _ _,---._
       ,-','       `-.___
      /-;'               `._
     /\/          ._   _,'o \
    ( /\       _,--'\,','"`. )
     |\      ,'o     \'    //\
     |      \        /   ,--'""`-.
     :       \_    _/ ,-'         `-._
      \        `--'  /                )
       `.  \`._    ,'     ________,','
         .--`     ,'  ,--` __\___,;'
          \`.,-- ,' ,`_)--'  /`.,'
           \( ;  | | )      (`-/
             `--'| |)       |-/
               | | |        | |
               | | |,.,-.   | |_
               | `./ /   )---`  )
              _|  /    ,',   ,-'
     -hrr-   ,'|_(    /-<._,' |--,
             |    `--'---.     \/ \
             |          / \    /\  \
           ,-^---._     |  \  /  \  \
        ,-'        \----'   \/    \--`.
       /            \              \   \
*/

/**
 * @file main.ino
 * @author Landon Gaillard (landon.gaillard@gmail.com)
 * @brief Main Arduino code for the Shackleford Project.
 *        This sketch uses a PS3 controller for input.
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright GNU GPLv3
 * 
 */

#include "RobotController.h"
#include <PS3BT.h>
#include "PS3Controller.h"

RobotController robot;
PS3Controller ps3;

/**
 * @brief Array to use in case of controller disconnection.
 *        Temporary measure for testing.
 */
uint8_t default_arr[3] = {0, 0, 0};


void setup() {
    Serial.begin(115200);

    robot.addServo(0);
    robot.addServo(1);
    robot.addServo(2);

    robot.setupTask();
    ps3.setupTask();
}


void loop() {
    ps3.loopTask();

    if(ps3.isConnected())
    {
        robot.setServoTargets(ps3.getControllerState(), STATE_ARRAY_SIZE);
    }
    else
    {
        robot.setServoTargets(default_arr, STATE_ARRAY_SIZE);
    }

    robot.loopTask();
}
