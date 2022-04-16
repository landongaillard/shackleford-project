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

PS3Controller ps3;
RobotController robot;

void setup() {
    Serial.begin(115200);

    robot.addServo(0);
    robot.addServo(1);
    robot.addServo(2);

    robot.setupRobotController();
    ps3.setupPS3Controller();
}


void loop() {
    ps3.loopTask();

    robot.controlByArray(ps3.getControllerState(),
                         ps3.getControllerStateSize());

    robot.loopTask();
}
