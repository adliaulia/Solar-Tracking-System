# Solar-Tracking-System Desc
Solar Tracking System is a system that is commonly used to position an object for example photovoltaic at an angle relative to the sun. The application of this instrument aims to position the photovoltaic so that it remains perpendicular to the sun's rays. This system can increase efficiency by keeping the solar panels perpendicular to the sun. Thus, more sunlight is absorbed so that more electrical energy can be generated and reduces the reflected light due to the tilt angle that is not in accordance with the direction of sunlight. The design of this instrument consists of an Arduino Nano and ESP 32 microcontroller, a photoresistor (Light Dependent Resistor), a DC voltage sensor, a servo motor, and a display screen (LCD). This tool works with the Arduino Nano to capture the light input that is read by the photoresistor. Next, the data read will be processed by the Arduino Nano microcontroller and generate a command to the servo motor. The voltage data read by the voltage sensor will be sent by the Arduino Nano microcontroller to the ESP 32 microcontroller via serial communication. Then, the data will be displayed in the display layer (LCD) and sent and saved into a google spreadsheet. Data that
stored in a google spreadsheet can then be reviewed for experimental results and used as a model in machine learning (Machine Learning).

## Video Explanation
Link video: https://www.youtube.com/watch?v=6wsiYkFikSg

## Features
* External interfacing: digital IO
* Analog to Digital Input
* PWM Signal
* Data Logging
