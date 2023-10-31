# Laboratory Work in Mechatronics
-----
- Project folder for the source code of two Arduino projects.<br>
- Hardware: Arduino uno + Crowtail deluxe kit
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
│   └── Land_Vehicle.ino.cpp --> how the compiler merges the tabs
├── libraries
│   ├── Servo
│   └── Ultrasonic
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
