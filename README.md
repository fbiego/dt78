# DT78 
DT78 Smartwatch Reverse Engineering

By using Wireshark & nRF Connect, I was able to decode the following [`commands`](https://github.com/fbiego/dt78/blob/master/DT78_COMMANDS.md)

More info at this [`blog`](http://www.biego.tech/dt78)

## Arduino ESP32

The [`arduino code`](https://github.com/fbiego/dt78/blob/master/dt78_ble_client/dt78_ble_client.ino) creates a client on the ESP32 board that connects to the smartwatch

Control lights using the watch [`Video`](https://youtu.be/IGo9HJPbSt0)

## Android App

Since this watch only supports notification from a few apps in the WearFit 2.0 app, I modified this code [`DT78-Alerts-Android`](https://github.com/fbiego/DT78-Alerts-Android)forked from [`mitchwongho/ESP-Alerts-for-Android`](https://github.com/mitchwongho/ESP-Alerts-for-Android) to send notifications to the app
