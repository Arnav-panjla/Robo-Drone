# 🚁 Drone Motor Driver Circuit README

## 📚 Table of Contents
1. [Introduction](#introduction)
2. [Circuit Overview](#circuit-overview)
   - [Motor Driver Circuit](#motor-driver-circuit)
   - [Complete Circuit with ESP32](#complete-circuit-with-esp32)
3. [Components List](#components-list)
4. [Schematic Diagrams](#schematic-diagrams)
   - [Motor Driver Circuit Schematic](#motor-driver-circuit-schematic)
   - [Complete Circuit Schematic](#complete-circuit-schematic)
5. [Connections and Pinouts](#connections-and-pinouts)
6. [Operation](#operation)
7. [Safety Precautions](#safety-precautions)
8. [Future Improvements](#future-improvements)
9. [References](#references)

---

## 1. 📝 Introduction

This README provides detailed information about the motor driver circuit designed for controlling four propellers of a drone using an ESP32 microcontroller. The motor driver circuit is capable of handling up to 3.3A at maximum load and is designed to operate a 3.7V motor in a single direction.

---

## 2. ⚙️ Circuit Overview

### Motor Driver Circuit: [Motor Driver Schematics PDF](./MotorDriverSchematics.PDF)

The motor driver circuit is designed to interface with the ESP32 and control the speed and operation of a 3.7V motor. The circuit utilizes MOSFETs or a dedicated motor driver IC to manage the power to the motor efficiently.

- **Voltage**: 3.7V and 7.4 for powering opAMPs
- **Current**: Up to 3.3A

### Complete Circuit with ESP32

The complete circuit integrates the ESP32 microcontroller, which acts as the brain of the drone, controlling the four motor driver circuits. Each motor driver is controlled by a PWM signal from the ESP32.

---

## 3. 🔧 Components List

| Component           | Quantity | Description                     |
|---------------------|----------|---------------------------------|
| ESP32C3 Xia         | 1        | Microcontroller                 |
| opAMP               | 4        | Part of motor driver circuit    |
| N-channel MOSFET    | 4        | For motor control               |
| Resistors           | Various  | Pull-down and for opAMPs        |
| Capacitors          | 4        | Decoupling and filtering        |
| Diodes              | 4        | Flyback diodes for protection   |
| Connectors          | Various  | For connecting motors and power |
| Power Supply        | 2        | 3.7V batteries                  |
| PCB                 | 1        | Custom PCB designed in EasyEDA  |

---

## 4. 📐 Schematic Diagrams

### Motor Driver Circuit Schematic
  <br>
  <br>
  <img src="..\..\public\asssets\MotorDriver.jpg" alt="Motor Driver" width="800"/>
  <br>

### Complete Circuit Schematic
  <br>
  <br>
  <img src="..\..\public\asssets\MotorDriver.jpg" alt="Motor Driver" width="800"/>
  <br>

---

## 5. 🔌 Connections and Pinouts

### ESP32 Pinouts

- **GPIO Pins**: Used for PWM control of the motor drivers.
- **Power Supply**: Connect to the appropriate power source (3.7V).
  
### Motor Driver Connections

- **Input Pins**: Connect to the corresponding GPIO pins of the ESP32.
- **Motor Terminals**: Connect to the propellers.
- **Power Connections**: Ensure correct voltage and current ratings are followed.

---

## 6. ⚡ Operation

- The ESP32 sends PWM signals to the motor drivers to control the speed and operation of each motor.
- Ensure that the code is properly uploaded to the ESP32 to manage motor functions as desired.

---

## 7. ⚠️ Safety Precautions

- Ensure all connections are secure to prevent shorts.
- Use appropriate heat sinks for MOSFETs if necessary to avoid overheating.
- Double-check component ratings to avoid damage.

---

## 8. 🚀 Future Improvements

- Consider adding a speed feedback mechanism for better control.
- Explore options for direction control (e.g., H-bridge configuration).
- Implement wireless control features using ESP32 capabilities.

---

## 9. 📖 References

- Check out resources repo

---

*Please fill in the schematic diagrams and any additional explanations as necessary.*
