#Smart Agriculture System (AgroNaut)
#Overview

AgroNaut is an IoT and Machine Learning based smart agriculture system that recommends suitable crops based on environmental and soil conditions.

The system collects real-time data using sensors, sends it to the cloud, and uses a trained ML model to predict the best crop for cultivation.



#Features

Real-time temperature and humidity monitoring

Soil moisture detection

Cloud integration using ThingSpeak

Machine Learning-based crop recommendation

Data visualization using live graphs

Scalable design (supports NPK sensor integration)



#System Architecture
Sensors → ESP32 → WiFi → ThingSpeak → ML Model → Crop Recommendation


#Hardware Components

ESP32 (WiFi-enabled microcontroller)

DHT22 Sensor (Temperature & Humidity)

Soil Moisture Sensor

NPK Sensor (conceptual / dataset-based)



#Connections

DHT22 → GPIO 4

Soil Sensor → GPIO 34

Power → 3.3V & GND

Note: NPK sensor is included in system design but simulated using dataset values due to Wokwi limitations.




#IoT Implementation

ESP32 reads sensor values

Data is sent to ThingSpeak using HTTP API

Fields used:

Field 1 → Temperature

Field 2 → Humidity

Field 3 → Soil Moisture



#ThingSpeak Output

Real-time data is visualized using graphs:

Temperature vs Time

Humidity vs Time

Soil Moisture vs Time



#Machine Learning Model

Dataset: Crop Recommendation Dataset (Kaggle)

Features: N, P, K, Temperature, Humidity, pH, Rainfall

Algorithm: K-Nearest Neighbors (KNN)

Accuracy: ~95%



#Tools & Technologies

ESP32 (IoT)

ThingSpeak (Cloud Platform)

Wokwi (Simulation)

Python (Machine Learning)

Scikit-learn



#Author

Sanya Gupta
CSE-Dual Degree
NIT Hamirpur












