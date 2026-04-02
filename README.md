# 🌱 Plant Recommendation System on Agricultural Land Using Hierarchical Clustering Method - Final Year Project


<div align = "center">
<img width="268" height="307" alt="Plant Recommendation System" src="https://github.com/user-attachments/assets/eaca4333-bc71-44b4-b363-1eb76d1b1151" /> </div>

<br><br>

---

## 📌 Overview

This project presents an end-to-end **smart agriculture monitoring system** that integrates IoT sensors, GPS, cloud database, and machine learning to help farmers make data-driven crop selection decisions.

The system collects soil nutrient data (N, P, K) and environmental parameters (pH, moisture, temperature, conductivity) along with GPS location — then applies **Agglomerative Hierarchical Clustering (AHC)** to recommend the most suitable crop for each land parcel.

---

## 🎯 Key Results

<div align="center">

| Metric | Result |
| :---: | :---: |
| Model Accuracy | **95%** |
| Error Rate | **4.7%** |
| Average Computing Time | **2.1 Seconds** |
| GPS Location Error | **±4.18 m average** |
| Data Sync | **Real-time via Wi-Fi → Firebase** |

</div>

---

## 🏗️ System Architecture

### Block Diagram
<div align="center">
<img width="470" height="296" alt="Block Diagram" src="https://github.com/user-attachments/assets/3eae90e2-867d-4ada-8c64-6ef455b4ec4c" />
</div>

### System Workflow / Flowchart
<div align="center">
<img width="630" height="400" alt="System Flowchart" src="https://github.com/user-attachments/assets/f7f14a7a-2a74-4117-a992-359f197ae903" />
</div>

### AHC Model Design
<div align="center">
<img width="456" height="121" alt="AHC Model Design" src="https://github.com/user-attachments/assets/a3789b31-bd7e-42b8-89ae-1a51d0e3d0d1" />
</div>

---

## 🔧 Hardware Components

### 1. Schematic — 7-in-1 Soil Sensor with Raspberry Pi

<div align="center">

<img width="488" height="300" alt="7-in-1 Sensor Schematic" src="https://github.com/user-attachments/assets/6f7ac39c-0c23-4eb8-b3c3-cdf7be11f2ae" />

<br>

| Raspberry Pi | Arduino Nano | RS-485 | 7-in-1 Sensor |
| :---: | :---: | :---: | :---: |
| USB | 5V | — | Kabel Coklat |
| USB | GND | — | Kabel Hitam |
| USB | — | A+ | Kabel Kuning |
| USB | — | B- | Kabel Biru |
| USB | 5V | VCC | — |
| USB | GND | GND | — |
| USB | D3 | DE | — |
| USB | D4 | RE | — |
| USB | D5 | RO | — |
| USB | D2 | DI | — |

</div>

### 2. Schematic — GPS Sensor (Neo-6M) with Raspberry Pi

<div align="center">

<img width="482" height="266" alt="GPS Sensor Schematic" src="https://github.com/user-attachments/assets/0d6c32f8-6cd4-4e2a-94b9-c398ade75486" />

<br>

| Raspberry Pi | USB to TTL | GPS Neo-6M |
| :---: | :---: | :---: |
| USB | GND | GND |
| USB | 5V | VCC |
| USB | RX | TX |
| USB | TX | RX |

</div>

### 3. Schematic — TFT LCD with Raspberry Pi

<div align="center">

<img width="488" height="195" alt="TFT LCD Schematic" src="https://github.com/user-attachments/assets/a82deba0-b456-40a1-827f-945e885f1fca" />

<br>

| TFT LCD | Raspberry Pi |
| :---: | :---: |
| VCC | 3.3V |
| GND | GND |
| CS | GPIO8 |
| RST | GPIO23 |
| DC | GPIO18 |
| SDI (MOSI) | GPIO10 |
| SCK | GPIO11 |
| LED | 5V |
| SDO (MISO) | GPIO9 |

</div>

---

## 🤖 Machine Learning — Agglomerative Hierarchical Clustering (AHC)

### Input Features

<div align="center">

| # | Feature | Unit |
| :---: | :--- | :---: |
| 1 | Nitrogen (N) | mg/kg |
| 2 | Phosphorus (P) | mg/kg |
| 3 | Potassium (K) | mg/kg |
| 4 | pH Level | — |
| 5 | Soil Moisture | % |
| 6 | Temperature | °C |
| 7 | Conductivity | µS/cm |

</div>

### How It Works

1. **Data Collection** — Dataset sourced from ICFA (Indian Chamber of Food and Agriculture), a leading global platform for agribusiness technology and policies.
2. **Data Preprocessing** — Converting data into the desired format, cleaning, and dimensionality reduction.
3. **Linkage Selection** — The Cophenetic Correlation Coefficient (CCC) is used to select the best linkage method by measuring the correlation between dendrogram distances and original data distances.
4. **Distance Matrix Selection** — Comparison between Manhattan, Euclidean, and Cosine similarity to determine the most appropriate distance matrix.
5. **Dendrogram Visualization** — A tree diagram used to visualize the clustering hierarchy, where more similar data points are combined earlier.
6. **Cluster Selection** — The Elbow method and cluster distribution results are used to determine the optimal number of clusters.
7. **Model Evaluation** — Performance is measured by calculating accuracy and comparing model predictions against real-world data.
8. **Crop Recommendation** — Once the AHC model demonstrates good performance, it is applied to predict crop recommendations based on sensor input values.

---

## 📊 System Analytics

### 1. Linkage Selection

Based on comparison of linkage methods, the **Average** linkage yielded the highest Cophenetic Correlation Coefficient.

<div align="center">

| Linkage | Cophenetic Correlation Coefficient (CCC) |
| :---: | :---: |
| Single | 0.888 |
| Complete | 0.895 |
| **Average** | **0.945 ✅** |
| Ward | 0.880 |

</div>

### 2. Cluster Selection — Elbow Method

<div align="center">

<img width="371" height="241" alt="Elbow Method" src="https://github.com/user-attachments/assets/63924f5f-2a4b-4671-9a07-5b0b9e3f6677" />

</div>

As shown in the figure, the decrease in *Within-Cluster Sum of Squares* (WCSS) begins to slow significantly at **cluster 5**. Therefore, **5 clusters** is selected as the optimal number.

### 3. Distance Matrix Selection

<div align="center">

| Cluster | Manhattan | Euclidean | Cosine |
| :---: | :---: | :---: | :---: |
| 1 | 499 | 1,738 | 499 |
| 2 | 200 | 186 | 499 |
| 3 | 214 | 219 | 200 |
| 4 | 316 | 43 | 735 |
| 5 | 801 | 14 | 267 |

</div>

The **Cosine** distance matrix shows a more balanced data distribution compared to Manhattan and Euclidean, and is therefore selected as the distance matrix.

### 4. Dendrogram

Generated using **Average linkage** and **Cosine distance matrix**.

<div align="center">

<img width="440" height="224" alt="Dendrogram" src="https://github.com/user-attachments/assets/c08fa96b-2b28-443f-b284-b86f3e4fc2d4" />

</div>

### 5. Crop Clustering Results

Clustering performed using Cosine matrix, 5 clusters, and Average linkage.

<div align="center">

| Cluster | Crop Names |
| :---: | :--- |
| 1 | Corn, Chickpeas, Pigeon Peas, Caper Peas, Red Beans, Lentils, Mango |
| 2 | Pomegranate, Orange, Green Beans, Coconut, Papaya |
| 3 | Grape, Apple |
| 4 | Corn, Cotton, Coffee, Melon, Rice, Papaya, Banana, Jute, Watermelon |
| 5 | Pigeon Beans, Black Beans, Caper Beans, Lentils |

</div>

---

## 🛠️ Tech Stack

<div align="center">

| Category | Tools |
| :--- | :--- |
| Machine Learning | Python, Scikit-learn (AgglomerativeClustering) |
| Data Processing | Pandas, NumPy |
| Visualization | Matplotlib, Seaborn, SciPy Dendrogram |
| Cloud Database | Firebase Realtime Database |
| IoT Hardware | 7-in-1 Soil Sensor, Neo-6M GPS, Raspberry Pi, TFT LCD |
| Connectivity | Wi-Fi (Raspberry Pi) |

</div>

---

## 📈 Testing & Results

### 1. Wi-Fi Connection Range

<div align="center">

<img width="456" height="271" alt="Wi-Fi Connection Test" src="https://github.com/user-attachments/assets/98a2fbbe-22f9-4bad-8d7b-ee116d10c83b" />

</div>

The device uses a **2.4 GHz Wi-Fi** connection. Signal strength closer to **-50 dBm** indicates a stronger signal; closer to **-100 dBm** indicates a weaker signal.

> Based on measurement results, the effective range is **±50 meters** with a maximum range of **70 meters**.

### 2. GPS Accuracy Testing

GPS coordinates compared against actual positions measured via Google Maps (5 of 10 total measurements shown).

<div align="center">

| Detection Latitude | Detection Longitude | Actual Latitude | Actual Longitude | Distance Error (m) |
| :---: | :---: | :---: | :---: | :---: |
| -7.365747 | 112.678061 | -7.365686 | 112.678056 | 6.81 |
| -7.378297 | 112.683716 | -7.378299 | 112.683719 | 0.39 |
| -7.399825 | 112.673079 | -7.399798 | 112.673050 | 4.38 |
| -7.391175 | 112.644457 | -7.391162 | 112.644473 | 2.28 |
| -7.348064 | 112.689821 | -7.348062 | 112.689826 | 0.59 |
|  | | |**Average (10 measurements)**| **4.18 m** |

</div>

Based on 10 measurement results, the average GPS error is **4.18 meters**, which is classified as **good accuracy** for agricultural field applications.

### 3. AHC Model Accuracy Testing

The model was tested with varying dataset sizes (12 to 100 data points).

<div align="center">

| Total Data | Correct Predictions | Wrong Predictions | Accuracy (%) | Error (%) |
| :---: | :---: | :---: | :---: | :---: |
| 12 | 11 | 1 | 91.6 | 8.4 |
| 22 | 21 | 1 | 95.6 | 4.6 |
| 30 | 29 | 1 | 96.6 | 3.4 |
| 50 | 49 | 1 | 98.0 | 2.0 |
| 65 | 62 | 3 | 95.3 | 4.7 |
| 100 | 95 | 5 | 95.0 | 5.0 |
|  | |**Average**| **95.0** | **4.7** |

</div>

The AHC model achieved an average accuracy of **95%** with an average error rate of **4.7%**, demonstrating consistent performance across all dataset sizes.

### 4. Crop Recommendation Output

Real-time sensor readings with corresponding crop recommendations and computation times.

<div align="center">

| N | P | K | Temp (°C) | Humidity (%) | pH | Conductivity | Recommended Crop | Compute Time (s) |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 127 | 339 | 334 | 28.3 | 62.6 | 9.0 | 793 | Grape | 2.109 |
| 21 | 96 | 89 | 27.4 | 29.1 | 7.7 | 289 | Chickpea | 2.118 |
| 5 | 58 | 50 | 27.5 | 20.5 | 9.0 | 209 | Pigeon Pea | 2.112 |
| 35 | 127 | 120 | 28.9 | 27.5 | 8.9 | 354 | Chickpea | 2.109 |
| 46 | 154 | 147 | 32.8 | 48.0 | 9.0 | 408 | Lentil | 2.113 |
| 6 | 45 | 38 | 28.3 | 12.7 | 6.4 | 184 | Caper Pea | 2.111 |
| 208 | 527 | 523 | 30.2 | 53.0 | 6.8 | 1,182 | Grape | 2.110 |
|  | | | | | | |**Average**| **2.110 s** |

</div>

The system performed consistently with an average computation time of **2.110 seconds** per recommendation. After measurement, data is displayed on the TFT LCD and transmitted to Firebase via Wi-Fi in real-time.

---

## 📄 Documentation

<div align="center">

| Document | Description |
| :---: | :--- |
| 📘 Guide Book | Complete hardware and software setup guide |
| 📊 Dataset | Soil nutrient dataset (ICFA) used for model training | 
| 💻 Code | Full source code — preprocessing, clustering, recommendation | 
| 📝 Paper | Research paper / Final Year Project report |
| 🎥 Video Demo | System demonstration video |

</div>

---

## 👩‍💻 Author


**Putri Ayu Licha Wardani**
<br>
Politeknik Elektronika Negeri Surabaya (PENS)
<br>
🔗LinkedIn: [linkedin.com/in/putriayulichawardani](https://www.linkedin.com/in/putriayulichawardani/)
<br>
📧Email: putriayulw10@gmail.com

---

## 📜 License

This project is associated with academic research at **Politeknik Elektronika Negeri Surabaya (PENS)**.
© 2024 Putri Ayu Licha Wardani. All rights reserved.

---

