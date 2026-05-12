# 🛒 Smart Shopping Cart using IoT & RFID

An intelligent IoT-based shopping cart system designed to automate billing and enhance the shopping experience using RFID technology and Arduino Nano.

# Overview

The Smart Shopping Cart is an embedded IoT project that eliminates traditional billing queues in supermarkets and retail stores. The system uses RFID tags, an RFID reader, and an Arduino Nano to automatically detect products placed inside the cart and display real-time billing information on an LCD screen.

This project improves customer convenience, reduces checkout time, and minimizes manual billing errors through automation and real-time processing.

# Features
🛒 Automatic item detection using RFID
📟 Real-time product name & price display
💰 Automatic total bill calculation
⚡ Faster checkout process
🔐 Reduced billing errors
📊 Real-time cart monitoring
🧠 Arduino Nano based automation
📦 Low-cost and energy-efficient system
🧾 Interactive LCD display interface
🧠 Problem Statement

Traditional shopping systems rely heavily on manual billing processes, resulting in:

Long waiting queues
Time wastage
Billing inaccuracies
Poor shopping experience
Difficulty tracking total expenses during shopping

The proposed Smart Shopping Cart system solves these problems using RFID-enabled automation.

# Proposed Solution

In this system:

Every product contains an RFID tag
The cart contains an RFID reader
Arduino Nano processes scanned data
LCD screen displays:
Product name
Price
Quantity
Total bill

As products are added or removed, the system updates billing information in real time without requiring manual checkout.

# Tech Stack
🖥️ Hardware Components
Arduino Nano
RFID Reader
RFID Tags
LCD Display (16x2 / 20x4)
I2C Interface
Servo Motor
Push Button
Breadboard
Jumper Wires
USB Cable

Component details and quantities are documented in the project report.

💻 Software Requirements
Arduino IDE
Embedded C / Arduino C++
🏗️ System Architecture
🔄 Working Flow
User scans product using RFID reader
RFID tag data is sent to Arduino Nano
Arduino processes item information
LCD displays:
Item name
Price
Running total
Push button confirms/removes item
Servo motor can trigger lock/alert mechanism
Final bill is generated automatically

The architecture and flowchart are described in the project documentation.

# 📂 Project Structure
Smart Shopping Cart/
│
├── Code/
│   └── smart_cart.ino
│
├── Documentation/
│   ├── RTP Document.pdf
│   ├── Abstract.docx
│   └── PPT.ppt
│
├── Images/
│   └── project_setup.jpg
│
└── README.md

# Installation & Setup
Step 1: Install Arduino IDE

Download and install Arduino IDE from:

https://www.arduino.cc/en/software

Arduino installation steps are detailed in the project report.

Step 2: Connect Hardware Components

Connect:

RFID Reader
LCD Display
Push Button
Servo Motor
Arduino Nano

using jumper wires and breadboard.

Step 3: Upload Code

Open .ino file in Arduino IDE and upload code to Arduino Nano.

Tools → Board → Arduino Nano
Tools → Port → Select COM Port
Upload

# Project Workflow
START
   ↓
Initialize RFID + LCD + Arduino
   ↓
Scan Product RFID Tag
   ↓
Validate Tag
   ↓
Display Product Info
   ↓
Update Total Price
   ↓
Add/Remove Item
   ↓
Update LCD Display
   ↓
END

# ARCHITECTURE 

<img width="1536" height="1024" alt="image" src="https://github.com/user-attachments/assets/cb753533-fb99-4e57-be37-6c888d520544" />

# OUTPUT



https://github.com/user-attachments/assets/6425c1be-5280-44e2-84e5-f940148ca709

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/eee6a5bf-5401-489e-9f87-03d471656caf" />



# 📈 Advantages
Faster shopping experience
Reduced billing queues
Real-time expense tracking
Reduced human errors
Cost-effective implementation
Scalable for smart retail systems
Better inventory monitoring
# ⚠️ Limitations
Limited processing capability of Arduino Nano
Requires RFID tags on all products
No built-in wireless connectivity
Limited I/O pins
Requires external modules for cloud integration

These limitations are discussed in the report.

# 🔮 Future Enhancements

Future upgrades may include:

# 📱 Mobile App Integration
☁️ Cloud Database Sync
💳 Automatic Digital Payments
📡 Wi-Fi / Bluetooth Support
🔍 QR / Barcode Scanning
📦 Inventory Management
🛰️ GPS Tracking
🧠 AI-based Product Recommendation

Future enhancement ideas are mentioned in the project report.

# 📸 Results

The system successfully:

Detects RFID-tagged products
Updates billing automatically
Displays total amount in real time
Reduces dependency on manual billing

The working prototype and results are shown in the project documentation.

# 🧪 Applications
Supermarkets
Grocery Stores
Retail Shops
Smart Retail Systems
Automated Billing Systems

# 📜 Conclusion

The Smart Shopping Cart project demonstrates how IoT and embedded systems can modernize the retail shopping experience using affordable hardware and real-time automation. It provides a scalable foundation for future smart retail innovations.
