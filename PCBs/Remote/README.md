# Remote PCB for Drone Control 🚀

## Overview

This repository contains the design and documentation for a remote PCB used to control a self-made drone. The remote features an ESP32 microcontroller, two joysticks, two potentiometers, two buttons, and onboard LEDs to indicate the success or failure of signal transmission. The system is powered by a 2S battery, with voltage regulation to ensure stable operation.

## Components 🛠️

- **Microcontroller**: ESP32
- **Input Devices**: 
  - 2 Joysticks
  - 2 Potentiometers
  - 2 Buttons
- **LED Indicators**: For success/failure of signal transmission
- **Power Supply**: 
  - 2S LiPo Battery
  - Voltage regulator: LM7806 (step down to 6V) and onboard voltage converter to 3.3V

## Features 🌟

- **Real-time Control**: The joysticks allow for precise control of the drone's movements.
- **Adjustable Parameters**: Potentiometers can be used to adjust flight parameters such as speed and altitude.
- **Status Indication**: Onboard LEDs provide visual feedback on signal status.
- **Compact Design**: Optimized for integration with a drone.

## Schematic 🖼️

![Schematic Diagram](link-to-your-schematic)  
*Attach your schematic diagram here.*

## Wiring Diagram 🖼️

![Wiring Diagram](link-to-your-wiring)  
*Attach your wiring diagram here.*

## Setup Instructions ⚙️

1. **Power Connection**:
   - Connect a 2S LiPo battery to the power input of the PCB.
   - The LM7806 will step down the voltage to 6V, and the onboard converter will provide 3.3V for the ESP32.

2. **Input Device Connections**:
   - Connect the joysticks and potentiometers to the designated analog input pins on the ESP32.
   - Connect the buttons to digital input pins.

3. **LED Connections**:
   - Connect the LEDs to appropriate GPIO pins for status indication.

4. **Programming the ESP32**:
   - Use the Arduino IDE or PlatformIO to upload the control code to the ESP32.
   - Ensure the necessary libraries for the ESP32 and input devices are installed.

## Usage 🎮

1. Power on the remote by connecting the 2S battery.
2. The onboard LEDs will indicate the power status and signal transmission status.
3. Use the joysticks to control the drone's movements and the potentiometers to adjust flight settings.
4. Press the buttons for additional functionalities (e.g., takeoff, landing).

## Troubleshooting 🔧

- **LEDs Not Lighting Up**: Check power connections and ensure the battery is charged.
- **Signal Transmission Issues**: Verify the connections to the ESP32 and the antennas if used.
- **Unresponsive Inputs**: Ensure that the joysticks and potentiometers are connected properly.
