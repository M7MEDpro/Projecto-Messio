# Projecto-Messio

A comprehensive IoT and mobile application project developed for **Programming 1** and **Digital Design (Logic Design)** courses at university. This project integrates embedded systems, backend servers, and a mobile application to create a complete full-stack solution.

## 📋 Project Overview

Projecto-Messio is a scientific prototype project that demonstrates the integration of embedded systems with modern software development practices. The project showcases a multi-component system combining hardware programming, server-side development, and mobile application design.

## 🏗️ Architecture

```
┌─────────────────────────────────────────────────────────────────┐
│                     PROJECTO-MESSIO ARCHITECTURE                 │
└─────────────────────────────────────────────────────────────────┘

    ┌──────────────┐         ┌──────────────┐
    │    ESP 1     │         │    ESP 2     │
    │  (Primary)   │         │  (Primary)   │
    └──────┬───────┘         └──────┬───────┘
           │                        │
           │   Sensor Data / IoT    │
           │                        │
           └────────┬───────────────┘
                    │ REST API
                    ▼
         ┌──────────────────────┐
         │   C++ Backend Server │
         │  (Core Processing &  │
         │   Business Logic)    │
         └──────────┬───────────┘
                    │
                    │ REST API
                    │
                    ▼
         ┌──────────────────────┐
         │   Dart Backend Layer │
         │    (Middleware for   │
         │    Mobile App Logic) │
         └──────────┬───────────┘
                    │
                    │ API Calls
                    │
                    ▼
         ┌──────────────────────┐
         │  Flutter Mobile App  │
         │   (Frontend / UI)    │
         └──────────────────────┘
```

The project consists of four main components:

### 1. **ESP32 Microcontrollers**
- **ESP 1**: Primary microcontroller unit
- **ESP 2**: Primary microcontroller unit
- Programmed using PlatformIO
- Handles hardware interfacing and sensor data collection
- Communicates with backend servers for data processing

### 2. **C++ Backend Server**
- High-performance server written in C++
- Handles real-time data processing
- Manages communication between ESP32 devices and mobile application
- Implements core business logic and data management

### 3. **Dart Backend Layer**
- Middleware layer between Flutter frontend and C++ backend
- Handles mobile app business logic
- Manages API communication
- Data transformation and state management

### 4. **Flutter Mobile Application**
- Cross-platform mobile app (iOS & Android)
- Modern, responsive UI built with Flutter
- Real-time data visualization
- User authentication and profile management
- Direct communication with backend through Dart layer

## 🛠️ Technologies Used

### Hardware & Embedded Systems
- **ESP32** microcontrollers (x2)
- **PlatformIO** for embedded development
- C/C++ for firmware development

### Backend Development
- **C++** for primary backend server
- **Dart** for mobile backend layer
- RESTful API architecture

### Mobile Development
- **Flutter** framework
- **Dart** programming language
- **Android Studio** as primary IDE
- Cross-platform compatibility

### Version Control
- **Git** for source control
- **GitHub** for repository hosting

## 📁 Project Structure

```
Projecto-Messio/
├── C++ Backend/          # C++ backend server implementation
├── MobileApp/            # Flutter mobile application
├── ESP1/                 # ESP32 Unit 1 firmware
├── ESP2/                 # ESP32 Unit 2 firmware
├── docs/                 # Documentation and project resources
│   ├── images/          
│   │   └── home.jpg     # Physical home setup
│   └── videos/          
│       └── demo.mp4     # Application demo
└── README.md            # Project documentation
```

## 📸 Media & Documentation

![Physical Home Setup](docs/images/home.jpg)

[Watch Demo Video](docs/videos/demo.mp4)

## 🚀 Getting Started

### Prerequisites

#### For ESP32 Development:
- PlatformIO IDE or PlatformIO Core
- ESP32 board support package
- USB drivers for ESP32

#### For C++ Backend:
- C++ compiler (GCC/Clang/MSVC)
- CMake (version 3.10+)
- Required C++ libraries (see C++ Backend folder)

#### For Dart Backend:
- Dart SDK (version 2.x or 3.x)
- Dart dependencies (see pubspec.yaml)

#### For Flutter Mobile App:
- Flutter SDK (version 3.x+)
- Android Studio
- Dart SDK (included with Flutter)

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/M7MEDpro/Projecto-Messio.git
   cd Projecto-Messio
   ```

2. **Set up ESP32 Units**
   ```bash
   platformio run --target upload
   ```

3. **Build C++ Backend**
   ```bash
   cd "C++ Backend"
   mkdir build
   cd build
   cmake ..
   make
   ```

4. **Run Dart Backend**
   ```bash
   cd dart-backend
   dart pub get
   dart run bin/server.dart
   ```

5. **Run Flutter Mobile App**
   ```bash
   cd MobileApp
   flutter pub get
   flutter run
   ```

## 👥 Team & Contributors

This project was developed by a dedicated team of university students:

- **[Mohamed Badawy](https://github.com/M7MEDpro)**
- **[Khaled Karam](https://github.com/khaledkaram688)**
- **Omar Mustafa**
- **[Mariam Mohamed](https://github.com/Mariam-Rashed)**
- **Abdelrahman Waleed**

## 📚 Course Information

- **Programming 1**: C++ fundamentals and backend development
- **Digital Design (Logic Design)**: Digital circuits, logic gates, and hardware design principles

## 🔬 Project Type

This is a **scientific prototype** project developed for educational and research purposes, demonstrating the practical application of theoretical concepts learned in university coursework.

## 🤝 Contributing

This is an academic project, but suggestions and feedback are welcome! Feel free to:
1. Fork the repository
2. Create a feature branch
3. Submit a pull request

## 📄 License

This project is developed for educational purposes as part of university coursework.

## 📧 Contact

For questions or collaboration opportunities, please reach out to the project contributors through their GitHub profiles.

---

**Note**: This project demonstrates the integration of embedded systems (ESP32), backend servers (C++ and Dart), and mobile development (Flutter) in a unified full-stack application prototype.
