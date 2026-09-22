# 🤟 Gesture-to-Text Translation Glove

> **A wearable smart glove that recognizes hand gestures in real time and converts them into meaningful text using embedded sensors, Bluetooth communication, and Machine Learning.**

<p align="center">
  <img src="https://img.shields.io/badge/Embedded-Systems-blue?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Machine-Learning-orange?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Python-3.x-yellow?style=for-the-badge&logo=python" />
  <img src="https://img.shields.io/badge/Arduino-Uno-00979D?style=for-the-badge&logo=arduino" />
  <img src="https://img.shields.io/badge/TensorFlow-Lite-FF6F00?style=for-the-badge&logo=tensorflow" />
  <img src="https://img.shields.io/badge/Bluetooth-HC--05-blue?style=for-the-badge" />
</p>

---

## 📌 Overview

The **Gesture-to-Text Translation Glove** is a wearable embedded-system project designed to recognize predefined hand gestures and convert them into text in real time.

The glove combines **flex sensors** for detecting finger bending with an **MPU6050 accelerometer and gyroscope** for capturing hand movement and orientation.

The collected sensor data is transmitted wirelessly through **Bluetooth** to a computer, where a Python-based processing pipeline prepares the sensor data and uses a **TensorFlow Lite Machine Learning model** for gesture classification.

### 💡 The Core Idea

```text
Hand Gesture
     ↓
🧤 Sensor Glove
     ↓
Flex Sensors + MPU6050
     ↓
Arduino UNO
     ↓
📡 HC-05 Bluetooth
     ↓
🐍 Python Data Pipeline
     ↓
🧠 TensorFlow Lite Model
     ↓
📝 Recognized Text
```

---

## ✨ Key Features

* 🤟 **Real-time gesture recognition**
* 🧤 Wearable glove-based interaction
* 🖐️ **Flex sensors** for finger-bending detection
* 📐 **MPU6050 IMU** for hand motion and orientation
* 📡 **Wireless Bluetooth communication**
* 🧠 Machine Learning-based gesture classification
* ⚡ TensorFlow Lite inference
* 🐍 Python-based real-time processing
* 📊 Sensor-data collection and dataset generation
* 🔄 Real-time prediction pipeline
* 💻 Linux-compatible development environment

---

# 🏗️ System Architecture

```text
                 🖐️ HAND GESTURE
                       │
                       ▼
              ┌──────────────────┐
              │   🧤 GLOVE       │
              │                  │
              │  Flex Sensors    │
              │       +          │
              │     MPU6050      │
              └────────┬─────────┘
                       │
                       ▼
              ┌──────────────────┐
              │   Arduino UNO    │
              │                  │
              │ Sensor Acquisition│
              └────────┬─────────┘
                       │
                       ▼
              ┌──────────────────┐
              │     HC-05        │
              │    Bluetooth     │
              └────────┬─────────┘
                       │
                  📡 Wireless
                       │
                       ▼
              ┌──────────────────┐
              │      Python      │
              │  Data Pipeline   │
              └────────┬─────────┘
                       │
                       ▼
              ┌──────────────────┐
              │ TensorFlow Lite  │
              │  ML Inference    │
              └────────┬─────────┘
                       │
                       ▼
                📝 TEXT OUTPUT
```

---

# 🛠️ Hardware Components

| Component             | Purpose                                    |
| --------------------- | ------------------------------------------ |
| 🧤 Glove              | Wearable platform for the sensors          |
| 🔌 Arduino UNO        | Main microcontroller                       |
| 🖐️ Flex Sensors      | Detect finger bending                      |
| 📐 MPU6050            | Measures acceleration and angular velocity |
| 📡 HC-05 Bluetooth    | Wireless sensor-data transmission          |
| 🔋 Li-ion Battery     | Portable power supply                      |
| 🔘 DIP Switches       | Configuration / control                    |
| 💡 LEDs               | Status indication                          |
| 🔧 Resistors          | Circuit interfacing                        |
| 🔗 Breadboard & Wires | Prototyping and connections                |

---

# 💻 Software & Technologies

### Programming

* 🐍 **Python**
* ⚙️ **Embedded C / Arduino**
* 📊 CSV-based data processing

### Machine Learning

* 🧠 **TensorFlow**
* ⚡ **TensorFlow Lite**
* 📈 Sensor-data classification

### Communication

* 📡 Bluetooth
* 🔗 Serial / RFCOMM communication

### Development Environment

* 🐧 Linux / Fedora
* Arduino IDE
* Python development environment

---

# 🔬 How It Works

The system operates through multiple stages.

### 1️⃣ Gesture Input

The user performs a predefined hand gesture while wearing the glove.

### 2️⃣ Sensor Acquisition

The flex sensors measure the bending of the fingers, while the **MPU6050** captures:

* Acceleration → `ax, ay, az`
* Angular velocity → `gx, gy, gz`

### 3️⃣ Microcontroller Processing

The Arduino collects the sensor readings at a fixed sampling interval and prepares the data for transmission.

### 4️⃣ Wireless Transmission

The sensor data is transmitted from the Arduino to the computer through the **HC-05 Bluetooth module**.

### 5️⃣ Data Processing

A Python pipeline receives the incoming serial data and organizes the readings into a structured dataset.

Example feature vector:

```text
Flex1, Flex2, Flex3, Flex4,
Ax, Ay, Az,
Gx, Gy, Gz
```

### 6️⃣ Machine Learning Prediction

The processed sensor values are passed to the trained **TensorFlow Lite model**.

The model predicts the corresponding gesture.

### 7️⃣ Text Output

The predicted gesture is converted into its corresponding textual representation.

Example:

```text
Sensor Data
     ↓
ML Model
     ↓
"Hi"
```

---

# 📊 Data Collection

The project uses sensor readings to build a gesture dataset.

Each recorded sample contains sensor values representing the current state of the glove.

A typical sample contains:

```text
Flex1
Flex2
Flex3
Flex4
Ax
Ay
Az
Gx
Gy
Gz
Label
```

The Arduino samples sensor data at approximately **50 Hz**, using a **20 ms sampling interval**.

This allows the system to capture changes in finger position and hand movement with sufficient temporal resolution for the gesture-recognition pipeline.

---

# 🧠 Machine Learning Pipeline

The overall ML workflow is:

```text
Raw Sensor Data
       ↓
Data Collection
       ↓
Dataset Creation
       ↓
Data Preprocessing
       ↓
Model Training
       ↓
Model Conversion
       ↓
TensorFlow Lite
       ↓
Real-Time Inference
       ↓
Gesture Prediction
```

The TensorFlow Lite model enables lightweight inference suitable for a real-time sensor-processing application.

---

# 📂 Project Structure

```text
gesture-to-text-translation-gloves/
│
├── 📁 Arduino/
│   └── Arduino source code
│
├── 📁 Python/
│   ├── record.py
│   └── Real-time processing scripts
│
├── 📁 Dataset/
│   └── Sensor datasets
│
├── 📁 Model/
│   └── TensorFlow Lite model
│
├── 📁 Documentation/
│   └── Project documentation
│
└── 📄 README.md
```

> **Note:** Update the folder names above to exactly match the folders in the repository.

---

# 🚀 Getting Started

## 1️⃣ Clone the Repository

```bash
git clone https://github.com/Navin-nk2008/gesture-to-text-translation-gloves.git
cd gesture-to-text-translation-gloves
```

## 2️⃣ Hardware Setup

Connect the components according to the project circuit:

```text
Flex Sensors ──────┐
                   │
MPU6050 ───────────┼──► Arduino UNO
                   │
HC-05 ─────────────┘
                   │
                   ▼
              Bluetooth
```

Make sure the Bluetooth module is correctly paired with the computer.

---

## 3️⃣ Install Python Dependencies

Create a virtual environment if required:

```bash
python3 -m venv venv
source venv/bin/activate
```

Install the required packages:

```bash
pip install -r requirements.txt
```

If a `requirements.txt` file is not included, install the dependencies used by the Python scripts manually.

---

## 4️⃣ Connect the Bluetooth Device

After pairing the HC-05 module, identify the serial/RFCOMM device.

For example:

```text
/dev/rfcomm0
```

The Python data-collection script can then read sensor data from the Bluetooth serial interface.

---

# ▶️ Running the Project

Start the sensor-data pipeline:

```bash
python3 record.py
```

The pipeline receives sensor readings from the glove and stores/processes them for model inference.

Once the ML model is loaded, the system can produce predictions such as:

```text
🤟 Gesture Detected → Hi
```

or

```text
🤟 Gesture Detected → 1
```

The system can also return:

```text
NONE
```

when a known gesture is not detected.

---

# 📈 Example Output

```text
Reading sensor data...

Flex: 820 745 690 810
Accel: 0.21 -0.14 9.62
Gyro: 1.12 -0.42 0.87

Prediction:
-------------------------
Gesture : Hi
Confidence : 96.8%
-------------------------
```

---

# 🎯 Project Objectives

The main objectives of this project are:

* 🤝 Reduce communication barriers through assistive technology
* 🧤 Develop a low-cost wearable gesture-recognition system
* 📡 Enable wireless sensor-data transmission
* 🧠 Apply Machine Learning to real-world sensor data
* ⚡ Perform lightweight real-time inference
* 🔬 Explore the integration of embedded systems and AI

---

# 🌍 Applications

Potential applications include:

* 🧏 Assistive communication
* 🏥 Healthcare environments
* 🏫 Educational institutions
* 🏢 Public-service environments
* 🤝 Human-computer interaction
* ♿ Accessibility-focused technology
* 🤖 Wearable AI systems
* 🔬 Embedded Machine Learning research

---

# 🔮 Future Improvements

The current system can be extended in several directions:

### 🗣️ Text-to-Speech

Convert recognized gestures into speech for more natural communication.

### 🌐 Multi-Language Support

Translate recognized gestures into multiple spoken languages.

### 🧠 Advanced Deep Learning

Experiment with models such as:

* CNN
* LSTM
* BiLSTM
* Transformer-based architectures

### 📱 Mobile Application

Develop an Android/iOS application for displaying real-time translations.

### ☁️ Cloud Integration

Store gesture history and analytics using an IoT/cloud platform.

### 🧤 Improved Wearable Design

Move from a breadboard prototype to a compact custom PCB and integrated wearable enclosure.

### 🤟 Larger Gesture Vocabulary

Expand the number of supported gestures and enable continuous sentence formation.

---

# ⚡ Performance Highlights

| Parameter              | Implementation         |
| ---------------------- | ---------------------- |
| Gesture Input          | Flex Sensors + MPU6050 |
| Microcontroller        | Arduino UNO            |
| Wireless Communication | HC-05 Bluetooth        |
| Sampling Rate          | ~50 Hz                 |
| ML Framework           | TensorFlow             |
| Inference              | TensorFlow Lite        |
| Processing             | Python                 |
| Output                 | Real-time text         |

---

# 🧪 Experimental Results

The prototype successfully demonstrates real-time recognition of predefined gestures.

Example recognized outputs include:

```text
🤟 Hi
🔢 1
🔢 0
⚪ NONE
```

The system demonstrates the feasibility of combining **wearable sensing + Bluetooth communication + Machine Learning** for real-time gesture-to-text translation.

> **Important:** Add your measured accuracy, precision, recall, F1-score, latency, and confusion matrix here once you have the final experimental values.

---

# 🧩 Technologies Used

```text
        🤟 Gesture Recognition
                 │
        ┌────────┴────────┐
        │                 │
   🔌 Embedded         🧠 AI/ML
     Systems             │
        │                │
   Arduino UNO      TensorFlow
   MPU6050           TensorFlow Lite
   Flex Sensors      Python
   HC-05
        │
        └────────┬────────┘
                 │
                 ▼
          📝 Real-Time Text
```

---

# 👨‍💻 Author

### **Navin N K**

🎓 Electronics & Computer Engineering
🏫 VIT Chennai

**Interests:**
`Embedded Systems` • `Machine Learning` • `IoT` • `Computer Engineering`

---

# 🤝 Contributing

Contributions, suggestions, and improvements are welcome!

If you would like to contribute:

```bash
# Fork the repository

# Create a new branch
git checkout -b feature/new-feature

# Commit your changes
git commit -m "Add new feature"

# Push the branch
git push origin feature/new-feature
```

Then open a **Pull Request** 🚀

---

# ⭐ Support the Project

If you find this project interesting or useful:

⭐ **Star this repository**

🍴 **Fork it**

🐛 **Report issues**

💡 **Suggest improvements**

🤝 **Contribute**

Every contribution helps improve the project!

---

# 📜 License

This project is intended for **educational and research purposes**.

Add the appropriate license file to the repository if you intend to distribute the project publicly.

---

<p align="center">

### 🤟 Turning Gestures into Words — One Signal at a Time.

**Built with ❤️ using Embedded Systems, Bluetooth & Machine Learning**

</p>
