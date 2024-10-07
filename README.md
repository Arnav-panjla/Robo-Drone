# Drone Project 🚀

Welcome to the Drone Project, developed by the Robotics Club at IIT Delhi. This project showcases a fully custom drone built from scratch, featuring 3D-printed chassis, custom motor drivers, and a custom remote controller.

## Table of Contents 📚
- [Introduction](https://github.com/Arnav-panjla/Robo-Drone/blob/main/README.md#introduction-)
- [Components](https://github.com/Arnav-panjla/Robo-Drone/blob/main/README.md#components-%EF%B8%8F)
- [Design and Architecture](https://github.com/Arnav-panjla/Robo-Drone/blob/main/README.md#design-and-architecture-%EF%B8%8F)
- [Functionality](https://github.com/Arnav-panjla/Robo-Drone/blob/main/README.md#functionality-%EF%B8%8F)
- [Usage](https://github.com/Arnav-panjla/Robo-Drone/blob/main/README.md#usage-)
- [Contributions](https://github.com/Arnav-panjla/Robo-Drone/blob/main/README.md#contributions-)
- [License](https://github.com/Arnav-panjla/Robo-Drone/blob/main/README.md#license-)
- [Acknowledgements](https://github.com/Arnav-panjla/Robo-Drone/blob/main/README.md#acknowledgements-)

## Introduction 🌟

The drone is designed to be a versatile platform for exploring robotics, remote control, and sensor integration. At its core, the drone utilizes an ESP32-C3 module for communication and control, enabling advanced features such as PID control and integration with a BMX160 sensor for enhanced stability and performance.

## Components 🛠️

- **Chassis**: 3D-printed design for a lightweight and durable structure.
- **Microcontroller**: Xiao ESP32-C3 for receiving signals and controlling motors.
- **Motor Drivers**: Custom-built motor drivers using operational amplifiers (op-amps) and N-channel MOSFETs.
- **Remote Controller**: Built with an ESP32, joystick module, and switches for intuitive control.
- **Sensors**: PID controller and BMX160 sensor for improved stability and performance.

## Design and Architecture 🖥️

<img src=".\public\asssets\CADimage.jpg" alt="CADimage" width="600"/>

- **Communication**: The drone and remote controller communicate via Wi-Fi, utilizing the ESP32’s capabilities.
- **Motor Control**: PWM signals generated by the ESP32 are amplified by op-amps and used to drive the motors through N-channel MOSFETs.
- **Control Logic**: Implemented PID control for precise maneuvering and stability.
- **posotion calibration**: Done by BMX160 measurment and subsequently using kalman filter.

## Functionality ✈️

- **Remote Control**: Control the drone using a joystick and switches on the remote controller.
- **Stability and Responsiveness**: Utilizes PID control and BMX160 sensor feedback filtered thruogh kalman filter to maintain stable flight.
- **Customizability**: Fully customizable components for future modifications and enhancements.

## Usage 📡

1. Power on the drone and remote controller.
2. Connect the remote controller to the drone's Wi-Fi network.
3. Use the joystick remote to control the drone's movements.

## Contributions 🤝

We welcome contributions from anyone interested in enhancing this project! To contribute:


## License 📜

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Acknowledgements 🙏

- Special thanks to the Robotics Club at IIT Delhi for their support and collaboration.
- I would like to thank the following friends for their invaluable help in building this repository:
    - [Lakshay Bhatnagar](https://github.com/Lakshya-bh) 
    - [Rishima Chaturvedi](https://github.com/friendusername)
- Inspired by various open-source projects in the robotics community.

---

Feel free to reach out if you have any questions or need assistance! 😊
