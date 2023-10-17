# Laboratory Work in Mechatronics
-----
- Project folder for the source code of two Arduino projects.<br>
- Arduino uno + Crowtail deluxe kit
-----
### Project folder structure
```
.
├── .editorconfig
├── .git
├── .gitattributes
├── .gitignore
├── Climbing_Robot
│   └── Climbing_Robot.ino
├── Land_Vehicle
│   ├── BLDC_module.ino
│   ├── IR_reflective_module.ino
│   ├── Land_Vehicle.ino --> main program
│   ├── servo_modules.ino
│   └── ultrasonic_module.ino
├── README.md
├── build-example
│   └── Land_Vehicle.ino.cpp --> compiler output from Land_Vehicle.ino
├── libraries
│   ├── Servo
│   └── Ultrasonic
├── test
    ├── IRCalibration_test --> calibrate IR sensors
    ├── brakeCalibration_test --> calibrate brakes
    ├── brake_test --> test brakes
    ├── lineFollower_test --> test linefollower
    ├── power_test --> test power
    ├── s-pattern_test --> test movement
    └── ultrasonic_test --> test ultrasonic sensor

```
- Climbing_Robot/: sketch + tabs
- Land Vecicle/: sketch + tabs
- libraries/: used libraries
- test/: arduino module testing 
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
- Select editor and verify
- Check settings: COM port, board type
- Compile and upload to Arduino uno
-----
### Workflow (contributors)
- Make development branch ```<dev-name>```.
- Don't merge a branch, before it is accepted as a module by the development team. 
-----
#### Project 1 - Land vehicle
- Land_Vehicle.ino - Main sketch
-----
#### Project 2 - Climbing robot
-----
