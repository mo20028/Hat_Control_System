# Temperature Control System using Atmega32


## Overview

This project is a Temperature Control System implemented using the Atmega32 microcontroller. The system comprises two microcontrollers (MCU1 and MCU2) that work together to monitor and control temperature within a predefined range. This README provides an overview of the project, its components, and how to set it up.

## Table of Contents

- [Project Description](#project-description)
- [Components Used](#components-used)
- [Software Drivers](#sowtware-drivers)
- [System Architecture](#system-architecture)
- [Getting Started](#getting-started)
- [Usage](#usage)


## Project Description

The Temperature Control System consists of two main components:

1. **MCU1 (Microcontroller 1):**
   - Responsible for reading temperature data from a sensor.
   - Controls the speed of a fan (DC motor) based on temperature.
   - Communicates with MCU2 using UART to exchange control commands.
   - Implements various safety measures based on temperature and user input.

2. **MCU2 (Microcontroller 2):**
   - Listens for control commands from MCU1 over UART communication.
   - Controls LEDs to indicate system status.
   - Controls a servo motor for specific actions.
   - Reads temperature-related data from an ADC sensor.
   - Implements safety measures and responses based on received commands.

## Components Used

- Atmega32 Microcontrollers (MCU1 and MCU2)
- Temperature Sensor
- DC Motor (used as a fan)
- Push Button for user input
- EEPROM for state storage
- LEDs for status indication
- Servo Motor for specific actions
- ADC for reading temperature-related data
- UART communication for command exchange between MCU1 and MCU2


## Software Drivers
- Port_Driver      
- Dio_Driver       
- GIE_Driver       
- Exti_Driver      
- ADC_Driver       
- Timer_Driver     
- UASRT_Driver     
- internal_EEPROM  
- Watch_Dog
- Servo_Driver
- DC_Motor_Driver     
                   
## System Architecture

The Temperature Control System operates in different states based on temperature readings and user input:

1. **Normal State:** Maintains temperature control within safe limits.
2. **Emergency State:** Activated when the temperature exceeds a critical threshold.
3. **Abnormal State:** Indicates an issue with temperature control.

Detailed descriptions of each state and their behaviors can be found in the code and documentation.

## Getting Started

To set up and run the Temperature Control System on your own hardware, follow these steps:

1. **Hardware Setup:** Connect the components (MCU1, MCU2, sensors, motors, etc.) as per the hardware schematic and pin configurations in the code.

2. **Software Setup:** Flash the MCU1 and MCU2 with their respective firmware.

3. **Power On:** Apply power to both MCU1 and MCU2.

## Usage

Once the system is set up and powered on, it will automatically start monitoring and controlling temperature. MCU1 communicates with MCU2 to ensure safe temperature control. Use the provided push button and LEDs for user interactions.



---

