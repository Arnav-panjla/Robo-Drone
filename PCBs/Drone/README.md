# 🚁 Drone Driver Circuit

<img src="..\..\public\asssets\DroneDriver.jpg" alt="Motor Driver" width="400"/>

## 📚 Table of Contents
1. [Introduction](#introduction)
2. [Necessity of Creating the Motor Driver](#necessity-of-creating-the-motor-driver)
3. [Testing Video](#testing-video)
4. [Circuit Overview](#circuit-overview)
   - [Motor Driver Circuit](#motor-driver-circuit)
   - [Complete Circuit with ESP32](#complete-circuit-with-esp32)
5. [Components List](#components-list)
6. [Schematic Diagrams](#schematic-diagrams)
   - [Motor Driver Circuit Schematic](#motor-driver-circuit-schematic)
   - [Complete Circuit Schematic](#complete-circuit-schematic)
7. [Connections and Pinouts](#connections-and-pinouts)
8. [Operation and Safety Precautions](#operation-and-safety-precautions)
9. [Future Improvements](#future-improvements)
10. [References](#references)

---

## 1. 📝 Introduction

This README provides detailed information about the motor driver circuit designed for controlling four propellers of a drone using an ESP32 microcontroller. The motor driver circuit can handle up to 3.3A at maximum load and operates a 3.7V motor in a single direction.

---

## 2. 🛠️ Necessity of Creating the Motor Driver

The development of this motor driver circuit is essential for several reasons:

- **High Current Handling**: This motor driver can handle up to 3.3A, which is unmatched by other drivers in the market within this price range, making it an economical yet powerful solution for drone applications.

- **Optimization for Drones**: The design is fully optimized for drone operations, ensuring efficient control of the motors under varying loads and conditions.



- **Signal Amplification**:
  <br>
  <br>
  <img src="..\..\public\asssets\DriverSignal.jpg" alt="Motor Driver" width="400"/>
  <br>
 The 3.3V output from the ESP32 was insufficient to drive the MOSFETs directly. To address this, we incorporated an operational amplifier (op-amp) with a non-inverting gain of 1.5. This setup amplifies the 3.3V signal to approximately 5V, effectively driving the MOSFETs and consequently powering the drone motors.



---

## 3. 🎥 Testing Video

To see the motor driver in action, check out the video of our testing process:

[Watch the Testing Video](..\..\public\asssets\DriverTestingVideo.mp4")

In this video, we demonstrate the operation of the motor driver, showcasing its performance and the control of the drone motors.

---

## 4. ⚙️ Circuit Overview

### Motor Driver Circuit: [Motor Driver Schematics PDF](./MotorDriverSchematics.pdf)

The motor driver circuit interfaces with the ESP32 to control the speed and operation of a 3.7V motor. The circuit utilizes MOSFETs or a dedicated motor driver IC for efficient power management.

- **Voltage**: 3.7V and 7.4V for powering op-amps
- **Current**: Up to 3.3A

### Complete Circuit with ESP32 [Motor Driver Schematics PDF](./DroneDriverSchematics.pdf)

The complete circuit integrates the ESP32S# microcontroller, controlling the four motor driver circuits with PWM signals.

---

## 5. 🔧 Components List

| Component           | Quantity | Description                     |
|---------------------|----------|---------------------------------|
| ESP32S3             | 1        | Microcontroller                 |
| op-AMP              | 4        | Part of motor driver circuit    |
| N-channel MOSFET    | 4        | For motor control               |
| Resistors           | Various  | Pull-down and for op-amps      |
| Capacitors          | 4        | Decoupling and filtering        |
| Diodes              | 4        | Flyback diodes for protection   |
| Connectors          | Various  | For connecting motors and power |
| Power Supply        | 2        | 3.7V batteries                  |
| PCB                 | 1        | Custom PCB designed in EasyEDA  |

---

## 6. 📐 Schematic Diagrams

### Motor Driver Circuit Schematic
<img src="..\..\public\asssets\MotorDriver.jpg" alt="Motor Driver" width="600"/>

### Complete Circuit Schematic
<img src="..\..\public\asssets\DroneSchemstics.jpg" alt="Drone Schematics" width="600"/>

---

## 7. 🔌 Connections and Pinouts

### ESP32 Pinouts

- **GPIO Pins**: Used for PWM control of the motor drivers.
- **Power Supply**: Connect to the appropriate power source (3.7V).

### Motor Driver Connections

- **Input Pins**: Connect to the corresponding GPIO pins of the ESP32.
- **Motor Terminals**: Connect to the propellers.
- **Power Connections**: Ensure correct voltage and current ratings are followed.

---

## 8. ⚡ Operation and Safety Precautions

- The ESP32 sends PWM signals to the motor drivers to control the speed and operation of each motor.
- Ensure that the code is properly uploaded to the ESP32 to manage motor functions as desired.

### Safety Precautions
- Ensure all connections are secure to prevent shorts.
- Use appropriate heat sinks for MOSFETs if necessary to avoid overheating.
- Double-check component ratings to avoid damage.

---

## 9. 🚀 Future Improvements

- Consider adding a speed feedback mechanism for better control.
- Explore options for direction control (e.g., H-bridge configuration).
- Implement wireless control features using ESP32 capabilities.

---

## 10. 📖 References

- Check out resources repository.
