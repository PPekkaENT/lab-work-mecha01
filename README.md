# Laboratory Work in Mechatronics
-----
- Project folder for the source code of two Arduino projects.<br>
- Main hardware/components: Arduino Uno + Crowtail-Deluxe kit for Arduino
-----
### Project folder structure
```
.
├── build-example --> cpp-files after compiler has merged the tabs
│   ├── Land_Vehicle.ino.cpp
│   └── Pipe_Robot.ino.cpp
├── .editorconfig
├── .git
├── .gitattributes
├── .gitignore
├── Land_Vehicle --> project 1
│   ├── BLDC_module.ino
│   ├── IR_Reflective_module.ino
│   ├── Land_Vehicle.ino --> main sketch
│   ├── servo_modules.ino
│   └── Ultrasonic_module.ino
├── libraries --> required libraries
│   ├── IRSendRev
│   ├── Servo
│   └── Ultrasonic
├── Pipe_Robot --> project 2
│   └── Pipe_Robot.ino --> main sketch
├── README.md

```
- Project 1: Land_Vehicle
- Project 2: Pipe_Robot
- libraries/: used libraries
- build-example/: cpp-files after compiler has merged the tabs
-----
### How to run
- Clone repository:
```
git clone git@github.com:PPekkaENT/lab-work-mecha01.git
```
OR
```
git clone https://github.com/PPekkaENT/lab-work-mecha01.git
```
- Select editor (Arduino IDE or Visual Studio Code)
- Check settings: COM port, board type
- Verify, compile and upload to Arduino uno
-----
#### Project 1 - Land vehicle
<h5>The Land_Vehicle robot is a small-sized 4-wheeled robot that can complete a specific test track. The mechanical structure of the robot is built from LEGO parts. The robot only uses thrust for power. An ESC (Electronic Speed Controller) connected to a compact BLDC motor controls the applied thrust and thus controls the power production. The robot uses an ultrasonic sensor to detect and avoid obstacles on the test track. The motion control system is implemented with infrared sensors and a servo motor. Three IR sensors are used to detect a black line that goes through the test track from the starting point to the final destination. The servo motor is connected to the front wheels and its angle is determined based on the feedback from the IR sensors. The robot has a braking system that is connected to the rear wheels. The braking system uses a servomotor to create torque. The braking system is an open loop system used to hit the target more accurately. As a final note, with some modifications, the robot may have usability outside of the test track.</h5>

-------------
#### Project 2 - Pipe_Robot
<h5>The Pipe_Robot is a robot that is completely built to travel along a specific aluminum pipe with a diameter of 25 mm. The robot uses 2 DC motors as a power source. </h5>

-----
