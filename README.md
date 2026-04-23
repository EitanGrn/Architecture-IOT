# 🛡️ Projet Mine Intelligente (LoRa P2P)

Ce projet consiste en un système de détection de mine terrestre utilisant une **Arduino Nano 33 BLE Sense** comme unité de détection et une **SODAQ ExpLoRer** comme passerelle de transmission longue portée via le protocole **LoRa P2P**.

## 📖 Description
Le système surveille en temps réel les variations de luminosité et de champ magnétique. Lorsqu'une anomalie est détectée (approche d'une source lumineuse ou d'un objet métallique), la mine déclenche une alerte visuelle et envoie un signal électrique à la station de transmission qui relaie l'information par ondes radio LoRa.

## 🛠️ Matériel utilisé
* **Capteur (Mine) :** Arduino Nano 33 BLE Sense
* **Transmetteur (Passerelle) :** SODAQ ExpLoRer (Module Microchip RN2483)
* **Capteurs embarqués :** Magnétomètre (BMI270/BMM150) et Capteur de lumière (APDS9960)

## 🔌 Branchements
Pour garantir une fiabilité maximale, la communication entre les deux cartes utilise un signal numérique direct (High/Low) plutôt qu'une liaison série classique.

| Arduino Nano 33 BLE | SODAQ ExpLoRer | Rôle |
| :--- | :--- | :--- |
| **Pin D2** | **Pin D2** | Signal d'alerte électrique (3.3V) |
| **GND** | **GND** | Masse commune (Indispensable) |
| **+3.3V** | **3.3V** | Alimentation (si Nano non branchée en USB) |
