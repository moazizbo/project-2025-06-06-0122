# README.md


# STM32 GPIO Fuzz Tester for Sensor Fault Injection

## Overview

The STM32 GPIO Fuzz Tester is a real-world embedded systems project designed to inject faults into sensors by manipulating GPIO pins. The project aims to identify how sensors behave under unexpected conditions, enhancing robustness and validation of sensor-driven systems in various applications, including automotive, industrial, and consumer electronics.

## Features

- Configurable GPIO pin manipulation
- Fault injection patterns: toggling, pulsing, and random
- Adjustable timing and duration for fault injection
- Simple user interface via serial communication

## Components

- STM32F4 Discovery Board
- Sensors (e.g., temperature, pressure, etc.) connected via GPIO
- USB-to-Serial interface

## Setup

1. Connect the STM32 Discovery Board to your PC using a USB interface.
2. Connect the target sensor to the designed GPIO pins for fault injection.
3. Open a terminal application (e.g., PuTTY, minicom) and connect to the appropriate COM port.
4. Build and upload the firmware to the STM32 board using an IDE like STM32CubeIDE or PlatformIO.
5. Use the terminal interface to configure and start the fault injection process.

## Example Commands

```sh
inject toggle PA5 1000 5000
inject random PB0 2000 10000
stop


