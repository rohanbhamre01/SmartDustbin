# SmartDustbin
Smart dustbin, a combination of Microcontroller and Microprocessor to smartify daily life essential 

Description: 
The Smart Dustbin using a proximity sensor uses object detection, where the Proximity sensor is placed on top of the dustbin
and when the sensor detects any object like a human hand, it will trigger the Micro Servo to open the lid.

Features:
Automated Lid
LEDs to denote the level of trash
Alert notifications when filled to full capacity

Requirements:
Hardware Requirements: 
Arduino UNO/Mega or Esp(32/8266) or MSP 430 Launchpad
TowerPro SG 90 Micro Servo Motor
HC-SR04 x2 Ultrasonic Distance Sensor
RaspberryPi 4B
NEO-6M GPS module

Software Requirement:
Arduino IDE
Python
Android app : Pushbullet

Process:
Connect Arduino to Raspberrypi using usb cable.
Install .ino file to microcontroller and run the python file on Raspberrypi

few changes required based on trials.
