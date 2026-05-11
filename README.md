# Smart Shopping Cart using IoT and RFID

An IoT-enabled Smart Shopping Cart designed to automate the retail checkout process using RFID technology and Arduino Nano. The system detects products automatically, updates the total bill in real time, and improves shopping efficiency by reducing manual billing delays.

---

## Overview

Traditional shopping systems often involve long billing queues and manual scanning processes, leading to customer frustration and increased checkout time. This project introduces a Smart Shopping Cart capable of automatically detecting products using RFID tags and displaying real-time billing information on an LCD screen.

The system integrates embedded hardware components with Arduino-based automation to create a low-cost and efficient smart retail solution.

---

## Features

- Automatic product detection using RFID
- Real-time price and quantity updates
- LCD-based billing display
- Automated cart interaction using Arduino Nano
- Servo motor integration for cart control/lock mechanism
- Low-cost and modular IoT architecture
- Real-time shopping assistance

---

## Technologies Used

### Hardware Components
- Arduino Nano
- RFID Reader
- RFID Tags
- LCD Display with I2C Interface
- Servo Motor
- Breadboard
- Jumper Wires
- Push Button

### Software
- Arduino IDE
- Embedded C / Arduino C++

---

## System Architecture

```text
RFID Tags → RFID Reader → Arduino Nano → LCD Display


The RFID reader scans product tags and sends data to the Arduino Nano. The Arduino processes the item information, updates the total bill, and displays the results on the LCD screen.

Working Principle
Each product is attached with an RFID tag.
The RFID reader scans the product when placed into the cart.
Arduino Nano processes the scanned tag information.
Product name, quantity, and total price are displayed on the LCD screen.
The total bill updates dynamically in real time.
Servo motor can be used for lock/unlock or checkout indication.
Project Objectives
Reduce checkout waiting time
Automate retail billing process
Improve shopping experience
Provide real-time cart monitoring
Minimize manual billing errors
Project Structure
Smart-Shopping-Cart/
│
├── Code.ino
├── README.md
├── circuit_diagram/
├── images/
├── documentation/
└── components/
Hardware Setup
Circuit Components
Arduino Nano connected to RFID Reader
LCD Display connected via I2C module
Servo Motor connected for control mechanism
Push Button for cart interaction

Applications
Supermarkets
Retail Stores
Smart Retail Systems
Automated Billing Systems
IoT-based Shopping Solutions
Advantages
Faster checkout process
Improved customer experience
Reduced manpower requirements
Real-time billing updates
Cost-effective implementation
Future Enhancements
Mobile app integration
QR/UPI payment support
Cloud database integration
Wi-Fi/Bluetooth connectivity
Inventory management dashboard
AI-based product recommendation system


                           
