# SmartDustbin
Smart dustbin, a combination of Microcontroller and Microprocessor to smartify daily life essential 

Description: 
The Smart Dustbin using a proximity sensor uses object detection, where the Proximity sensor is placed on top of the dustbin
and when the sensor detects any object like a human hand, it will trigger the Micro Servo to open the lid.

Features:
Automated Lid.
LCD to display the level of trash.
Alert notifications when filled to full capacity.
Gps Based location of the Dustbin. note: GPS module only runs under the direct sky.

Requirements:
Hardware Requirements: 
Arduino UNO/Mega or MSP 430 Launchpad
Micro Servo Motor
HC-SR04 x2 Ultrasonic Distance Sensor
RaspberryPi 3/4B
NEO-6M GPS module

Software Requirement:
Arduino IDE
Python
Android app: Pushbullet

Process:
Connect Arduino to Raspberry Pi using a USB cable.
Install the .ino file to the microcontroller and run the python file on Raspberry pi GUI

A few changes may be required based on trials.
