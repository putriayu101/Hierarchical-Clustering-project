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
<div align = "center"><img width="488" height="195" alt="image" src="https://github.com/user-attachments/assets/a82deba0-b456-40a1-827f-945e885f1fca" /> </div> <br>

| TFT LCD | Raspberry Pi |
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


## 🤖 Machine Learning - Agglomerative Hierarchical Clustering (AHC)
### Features
  - Nitrogen (N)
  - Phosporus (P)
  - Potassium (K)
  - pH Level
  - Soil Moisture
  - Temperature
  - Conductivity

### How It Works
 1. **Data Collection** - The dataset comes from the ICFA (Indian Chamber of Food and Agriculture), which is the leading organization for addressing business agendas and policies and serves as a global platform for agribusiness technology and services. 
  2. **Data Preprocessing** - The process of converting data into the desired format, cleaning the data, reducing data dimensions, and more. 
  3. **Selection of Linkage** - The hierarchical clustering method used to determine how to calculate the distance between clusters. The Cophentic Correlation Coefficient (CCC) is used, which measures the correlation between the distances displayed in the dendrogram and the original distances in the data
  4. **Selection of Distance Matrices** - To determine the most appropriate distance matrix, a comparison is made between several methods, such as Manhattan, Euclidean, and cosine similarity.
  5. **Dendrogram** - A graphical representation in the form of a tree diagram used to illustrate/visualize the clustering hierarchy, where points or groups of points that are more similar to one another are combined earlier in the clustering process. 
  6. **Cluster Selection** - The Elbow method and cluster distribution results are used to determine the approximate number of clusters to be used.
  7. **Model Evaluation** - Used to measure performance in providing crop recommendations by calculating accuracy and comparing it with the model’s predictions against real-world data.
  8. **Crop Recommendations** - Once the AHC model has demonstrated good performance, it can be applied to predict crop recommendations based on the provided values.

## System Analytics
  1. **Selection of Linkage** <br>
     Based on the comparison of linkage methods, the *Average* linkage method yielded the highest score, meaning that the dendrogram will be visualized using *Average* linkage.
     
| Linkage | Coefficient Correlation Cophenetic (CCC) |
| :---: | :---: |
| Single | 0,888 |
| Complete | 0,895 |
| Average | 0,945 |
| Ward | 0,880 |

  2. **Cluster Selection** <br>
     Using the *Elbow method* as an evaluation metric to determine the optimal number of clusters. <br>
   <div align = "center"> <img width="371" height="241" alt="image" src="https://github.com/user-attachments/assets/63924f5f-2a4b-4671-9a07-5b0b9e3f6677" /> </div> <br>
    As shown in the figure, the decrease in the *Within-Cluster Sum of Squares* (WCSS) begins to slow significantly in cluster 5. Therefore, cluster 5 is considered effective for clustering in the model.

  4. **Selection of Distance Matrices** <br>
      Selecting a distance matrix to obtain the optimal data distribution. We use the clusters we selected earlier to examine the data distribution results for each distance matrix. <br>
     
     | Cluster | Manhattan | Eucledian | Cosine |
     | :---: | :---:|:---:|:---:|
     |1|499|1738|499|
     |2|200|186|499|
     |3|214|219|200|
     |4|316|43|735|
     |5|801|14|267|

    From the results, it can be concluded that the *Cosine* matrix exhibits a more balanced data distribution compared to the Manhattan and Euclidean matrices.

  5. **Dendogram** <br>
     <img width="440" height="224" alt="image" src="https://github.com/user-attachments/assets/c08fa96b-2b28-443f-b284-b86f3e4fc2d4" /> <br>
    The dendrogram in the figure was generated using average linkage and a cosine matrix.

  6. **Pengelompokkan Tanaman Hasil Clustering** <br>
     This clustering is used to identify which plant names are included in each cluster. The clustering results are based on a cosine matrix, 5 clusters, and average linkage. <br>
     
     |Cluter ke-|Nama Tanaman|
     |:---:|:---|
     |1|Corn, Chickpeas, Black-eyed peas, Snow peas, Red beans, Lentils, Mangoes|
     |2|Pomegranate, Orange, Green beans, Coconut, Papaya|
     |3|Grape, Apple|
     |4|Corn, Cotton, Coffee, Melon, Rice, Papaya, Banana, Hemp, Watermelon|
     |5|Gude beans, Black beans, Capri beans, Lentils|
     
## 🛠️ Tech Stack
  - Machine Learning  : Python, Scikit-learn (AgglomerativeClustering)
  - Data Processing   : Pandas, NumPy
  - Visualization     : Matplotlib, Seaborn, Dendrogram
  - Cloud Database    : Firebase Realtime Database
  - IoT Hardware      : 7-in-1 Soil Sensor, Neo-6M GPS, Raspberry Pi, TFT LCD
  - Connectivity      : Wi-Fi (Raspberri Pi)

## Result 
  1. **Wi-Fi Connection** <br>
     Digunakan internet HP dengan kekuatan sebesar 2.4 GHz untuk menghubungkan alat dengan internet.Pada pengukuran, semakin kecil nilai (negatif) misalnya mendekati -50 dBm, kekuatan sinyal semakin baik. Dan sebaliknya, apabila nilai (negatif) makin besar misal mendekati -100 dBm, artinya kekuatan sinyal semakin buruk. <br>
     <img width="456" height="271" alt="image" src="https://github.com/user-attachments/assets/98a2fbbe-22f9-4bad-8d7b-ee116d10c83b" /> <br>
     Dari hasil pengukuran, dapat disimpulkan bahwa kekuatan sinyal dari hospot HP memiliki jangkauan efektif sekitar 50m, dan jangkauan maksimal di 70m. Oleh karena itu, jarak efektif untuk pengiriman data dari alat ke *cloud database* maksimal di jarak 70m.
     
  2. **GPS Testing** <br>
     Dilakukan pengukuran perbedaan jarak antara hasil dari perangkat dengan titik yang sebenarnya. Contoh Hasil pengukuran,

     |Detection|Actual|Different Distance (m)|
     |Latitude|Longitude|Latitude|Longitude|
