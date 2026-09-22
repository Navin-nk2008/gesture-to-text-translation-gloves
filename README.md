# 🤟 Gesture-to-Text Translation Glove

<p align="center">
  <img src="assets/circuit-diagram.png" alt="Gesture-to-Text Translation Glove" width="850">
</p>

<h3 align="center">
  🧤 A Smart Wearable Glove for Real-Time Hand Gesture Recognition and Text Translation
</h3>

<p align="center">
  <b>Embedded Systems • Machine Learning • Bluetooth • Wearable Technology</b>
</p>

<p align="center">

![Arduino](https://img.shields.io/badge/Arduino-UNO-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![Python](https://img.shields.io/badge/Python-3.x-3776AB?style=for-the-badge&logo=python&logoColor=white)
![TensorFlow](https://img.shields.io/badge/TensorFlow-Lite-FF6F00?style=for-the-badge&logo=tensorflow&logoColor=white)
![Bluetooth](https://img.shields.io/badge/Bluetooth-HC--05-0082FC?style=for-the-badge&logo=bluetooth&logoColor=white)
![Embedded](https://img.shields.io/badge/Embedded-Systems-8A2BE2?style=for-the-badge)
![ML](https://img.shields.io/badge/Machine-Learning-FF6F00?style=for-the-badge)

</p>

---

## 📌 Table of Contents

- [📖 Overview](#-overview)
- [🎯 Objectives](#-objectives)
- [✨ Features](#-features)
- [🏗️ System Architecture](#️-system-architecture)
- [🔌 Circuit Diagram](#-circuit-diagram)
- [🛠️ Hardware Components](#️-hardware-components)
- [💻 Software & Technologies](#-software--technologies)
- [⚙️ Working Principle](#️-working-principle)
- [🧠 Machine Learning Pipeline](#-machine-learning-pipeline)
- [📊 Sensor Data](#-sensor-data)
- [📁 Project Structure](#-project-structure)
- [🚀 Installation](#-installation)
- [▶️ Running the Project](#️-running-the-project)
- [📈 Example Output](#-example-output)
- [🎯 Applications](#-applications)
- [🔮 Future Improvements](#-future-improvements)
- [📚 Learning Outcomes](#-learning-outcomes)
- [🤝 Contributing](#-contributing)
- [👨‍💻 Author](#-author)
- [⭐ Support](#-support)
- [📜 License](#-license)

---

# 📖 Overview

The **Gesture-to-Text Translation Glove** is a wearable embedded system designed to recognize predefined hand gestures and convert them into meaningful text in real time.

The glove combines **flex sensors** and an **MPU6050 Inertial Measurement Unit (IMU)** to capture finger movements, hand orientation, acceleration, and rotational motion.

An **Arduino UNO** collects the sensor data and communicates wirelessly with a computer using an **HC-05 Bluetooth module**.

The received sensor data is processed using a **Python-based pipeline**, and a **TensorFlow Lite machine learning model** is used to classify the gesture.

The recognized gesture is then displayed as text.

### 💡 Core Concept

```text
             🖐️ HAND GESTURE
                    │
                    ▼
             🧤 SENSOR GLOVE
                    │
          ┌─────────┴─────────┐
          │                   │
     🖐️ Flex Sensors       📐 MPU6050
          │                   │
          └─────────┬─────────┘
                    │
                    ▼
              🔌 Arduino UNO
                    │
                    ▼
              📡 HC-05 Bluetooth
                    │
                    ▼
              🐍 Python Pipeline
                    │
                    ▼
             🧠 ML Classification
                    │
                    ▼
             ⚡ TensorFlow Lite
                    │
                    ▼
                📝 TEXT
