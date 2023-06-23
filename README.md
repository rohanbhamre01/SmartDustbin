# SmartDustbin
Smart dustbin, a combination of Microcontroller and Microprocessor to smartify daily life essential 

## Description: 
The Smart Dustbin using a proximity sensor uses object detection, where the Proximity sensor is placed on top of the dustbin
and when the sensor detects any object like a human hand, it will trigger the Micro Servo to open the lid.

## Features:
1. Automated Lid.
2. LCD to display the level of trash.
3. Alert notifications when filled to full capacity.
4. Gps Based location of the Dustbin. note: GPS module only runs under the direct sky.

## Requirements:
### Hardware Requirements: 
1. Arduino UNO/Mega or MSP 430 Launchpad
2. Micro Servo Motor
3. HC-SR04 x2 Ultrasonic Distance Sensor
4. RaspberryPi 3/4B with wifi connected
5. NEO-6M GPS module

### Software Requirement:
1. Arduino IDE
2. Python
3. Android app: Pushbullet

## Process:
Connect Arduino to Raspberry Pi using a USB cable.
Install the .ino file to the microcontroller and run the python file on Raspberry pi GUI

A few changes may be required based on trials.
