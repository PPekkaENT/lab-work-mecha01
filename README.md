# Laboratory Work in Mechatronics
-----
- Project folder for the source code of two Arduino projects.<br>
- Main hardware/components: Arduino Uno + Crowtail-Deluxe kit for Arduino
-----
### Project folder structure
```
.
├── build-example
│   ├── Land_Vehicle.ino.cpp
│   └── Pipe_Robot.ino.cpp
├── .editorconfig
├── .git
├── .gitattributes
├── .gitignore
├── Land_Vehicle
│   ├── BLDC_module.ino
│   ├── IR_Reflective_module.ino
│   ├── Land_Vehicle.ino
│   ├── servo_modules.ino
│   └── Ultrasonic_module.ino
├── libraries
│   ├── IRSendRev
│   ├── Servo
│   └── Ultrasonic
├── Pipe_Robot
│   └── Pipe_Robot.ino
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
<h5>The Land_Vehicle robot is a small-sized 4-wheeled robot that can complete a specific test track. The robot only uses thrust for power. A compact BLDC motor connected to the ESC controls the power. The robot uses an ultrasonic sensor to detect obstacles and avoid touching the edges of the test track. The movement direction control is implemented with 3 IR sensors and 2 servomotors. The IR sensors are used to detect a black line in the middle of the test track, one servomotor controls the angle of the front wheels and the other servo motor implements the brake, which is connected to the rear wheels. The mechanical structure of the robot is  built mainly with Lego parts. With the modifications, the robot may have usability outside the test track.</h5>

-------------
#### Project 2 - Pipe_Robot
<h5>The Pipe_Robot is a robot that is completely built to travel along a specific aluminum pipe with a diameter of 25 mm. The robot uses 2 DC motors as a power source. </h5>

-----
