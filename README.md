# Laboratory Work in Mechatronics
-----
- Project folder for the source code of two Arduino projects.<br>
- Arduino uno + Crowtail deluxe kit
-----
### Project folder structure
```
.
├── Climbing_Robot
│   └── Climbing_Robot.ino
├── .editorconfig
├── .git
├── .gitattributes
├── .gitignore
├── Land_Vehicle
│   ├── BLDC_module.ino
│   ├── Gyro_module.ino
│   ├── IR_Reflective_module.ino
│   ├── Land_Vehicle.ino
│   ├── Servo_module.ino
│   └── Ultrasonic_module.ino
├── libraries
│   ├── Servo
│   └── Ultrasonic
├── README.md
├── test
    ├── ESC-Calibration
    └── Gyro_Module

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
- Select editor and verify
- Check settings: COM port, board type
- Compile and upload to Arduino uno
-----
### Workflow (contributors)
- General settings are set in ```.gitattributes``` & ```.editorconfig``` files to maintain integrity.
- Make development branch ```<dev-name>```.
- Don't merge a branch, before it is accepted as a module by the development team. 
-----
#### Project 1 - Land vehicle
- Land_Vehicle.ino - Main sketch
- Gyro_module.ino - Gyro module tab
-----
#### Project 2 - Climbing robot
-----
