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
│   ├── IR_Reflective_module.ino
│   ├── Land_Vehicle.ino --> main program (linefollower with a goal)
│   ├── servo_modules.ino
│   └── ultrasonic_module.ino
├── README.md
├── build-example
│   └── Land_Vehicle.ino.cpp --> how the compiler builds the program
├── libraries
│   ├── Servo
│   └── Ultrasonic
├── test --> module testing
    ├── IRCalibration_test
    ├── brakeCalibration_test
    ├── brake_test
    ├── power_test
    └── ultrasonic_test

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
