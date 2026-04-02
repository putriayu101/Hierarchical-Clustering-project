# 🌱 Plant Recommendation System on Agricultural Land Using Hierarchical Clustering Method
<div align="center">
<img width="268" height="307" alt="image" src="https://github.com/user-attachments/assets/eaca4333-bc71-44b4-b363-1eb76d1b1151" /> </div>

## 📌 Overview
This project presents an end-to-end **smart agriculture monitoring system** that integrates IoT sensors, GPS, cloud database, and machine learning to help farmers make data-driven crop selection decisions.
The system collects soil nutrient data (N, P, K), environmental parameters (pH, moisture, temperature, conductivity), and GPS location — then applies **Agglomerative Hierarchical Clustering (AHC)** to recommend the most suitable crop for each land parcel.

## 🎯 Key Results
| Metrics | Result |
| :---: | :---: |
| Model Accuracy | 95% |
| Error Rate | 4,7% |
| Average Computing Time | 2,1 Seconds |
| Data Sync | Real-time via Wi-Fi -> Firebase |

## 🏗️ System Architecture
### Blog Diagram 
System design, including a block diagram of the system shown below.
<div align = "center"> <img width="470" height="296" alt="image" src="https://github.com/user-attachments/assets/3eae90e2-867d-4ada-8c64-6ef455b4ec4c" /> </div>

### System Workflow / Flowchart
The system will follow the workflow below.
<div align = "center"> <img width="630" height="400" alt="flowchart" src="https://github.com/user-attachments/assets/f7f14a7a-2a74-4117-a992-359f197ae903" /> </div>

### AHC Design Model 
The design of the model to be created follows the workflow shown below. 
<div align = "center"> <img width="456" height="121" alt="model Ahc" src="https://github.com/user-attachments/assets/a3789b31-bd7e-42b8-89ae-1a51d0e3d0d1" /> </div>

## 🔨 Hardware Component
### Schematic 7-in-1 Sensor with Raspberry Pi
<div align = "center"> <img width="488" height="300" alt="image" src="https://github.com/user-attachments/assets/6f7ac39c-0c23-4eb8-b3c3-cdf7be11f2ae" /> </div> <br>

| Raspberry Pi | Arduino Nano | RS-485 | 7in1 Sensor |
| :---: | :---: | :---: | :---: |
| **USB Raspberry Pi** | 5V | - | Kabel Coklat |
| **USB Raspberry Pi** | GND | - | Kabel Hitam |
| **USB Raspberry Pi** | - | A+ | Kabel Kuning |
| **USB Raspberry Pi** | - | B- | Kabel Biru |
| **USB Raspberry Pi** | 5V | VCC | - |
| **USB Raspberry Pi** | GND | GND | - |
| **USB Raspberry Pi** | D3 | DE | - |
| **USB Raspberry Pi** | D4 | RE | - |
| **USB Raspberry Pi** | D5 | R0 | - |
| **USB Raspberry Pi** | D2 | DI | - |

### Schematic GPS Sensor with Raspberry Pi
<div align = "center">
  <img width="482" height="266" alt="image" src="https://github.com/user-attachments/assets/0d6c32f8-6cd4-4e2a-94b9-c398ade75486" /> </div> <br>
  
| Raspberry Pi | USB to TTL | GPS | 
| :---: | :---: | :---: |
| **USB Raspberry Pi** | GND | GND | 
| **USB Raspberry Pi** | 5V | VCC | 
| **USB Raspberry Pi** | RX | TX |
| **USB Raspberry Pi** | TX | RX | 

### Schematic TFT LCD Sensor with Raspberry Pi
<div align = "center"><img width="488" height="195" alt="image" src="https://github.com/user-attachments/assets/a82deba0-b456-40a1-827f-945e885f1fca" />
</div> <br>
| Raspberry Pi | USB to TTL |
| :---: | :---: | 
| VCC | 3.3V | 
| GND | GND |
| CS | GPIO8 | 
| RST | GPIO23 | 
| DC | GPIO18 | 
| SDI(MOSI) | GPIO10 |
| SCK | GPIO11 | 
| LED | 5V | 
| SDO(MISO) | GPIO9 | 
