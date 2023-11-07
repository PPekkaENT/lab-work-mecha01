# Laboratory Work in Mechatronics
-----
- Project folder for the source code of two Arduino projects.<br>
- Hardware: Arduino uno + Crowtail deluxe kit
-----
### Project folder structure
```
.
├── build-example
│   └── Land_Vehicle.ino.cpp --> how the compiler merges the tabs
├── .editorconfig
├── .git
├── .gitattributes
├── .gitignore
├── Land_Vehicle
│   ├── BLDC_module.ino
│   ├── IR_Reflective_module.ino
│   ├── Land_Vehicle.ino --> main program (linefollower with a goal)
│   ├── servo_modules.ino
│   └── Ultrasonic_module.ino
├── libraries
│   ├── Servo
│   └── Ultrasonic
├── Pipe_Robot
│   ├── BLDC_module.ino
│   ├── hall_sensor_module.ino
│   ├── IR_reflective_module.ino
│   ├── Pipe_Robot.ino --> main program
│   └── servo_modules.ino
├── README.md
├── test --> module testing

```
- (Project 1) Land_Vehicle/: main sketch + tabs
- (Project 2) Climbing_Robot/: main sketch + tabs
- libraries/: used libraries
- test/: sketches for module testing 
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
- Select editor
- Check settings: COM port, board type
- Verify, compile and upload to Arduino uno
-----
#### Project 1 - Land vehicle
- Add description here
-----
#### Project 2 - Climbing robot
- Add description here
-----
