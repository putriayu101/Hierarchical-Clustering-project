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

### Schematic 7-in-1 Sensor with Raspberry Pi
<img width="576" height="293" alt="image" src="https://github.com/user-attachments/assets/6f7ac39c-0c23-4eb8-b3c3-cdf7be11f2ae" />
| Raspberry Pi | Arduino | 7in1 Sensor | 
| :---: | :---: | :---: | :---: |
| USB Raspberry Pi | 5V | - | Brown Cabel |
| ---------------- | GND | - | Blcak cabel |
