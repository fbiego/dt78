# DT78 
DT78 Smartwatch Reverse Engineering

By using Wireshark, nRF Connect app & an ESP32 board, I was able to decode the following [`commands`](https://github.com/fbiego/dt78/blob/master/DT78_COMMANDS.md)

More info at this [`blog`](http://www.biego.tech/dt78)

## ESP32

### Client

This arduino code [`dt78_ble_client`](https://github.com/fbiego/dt78/blob/master/dt78_ble_client/dt78_ble_client.ino) creates a client on the ESP32 board that connects to the smartwatch

Control lights using the watch [`Video`](https://youtu.be/IGo9HJPbSt0)

### Server

This arduino code [`dt78_ble_server`](https://github.com/fbiego/dt78/blob/master/dt78_ble_server/dt78_ble_server.ino) creates a server on the ESP32 board that emulates the services and characteristics of the DT78 smartwatch and connect to the WearFit 2.0 app

## Android App

Since this watch only supports notification from a few apps in the WearFit 2.0 app, I modified this code [`DT78-App-Android`](https://github.com/fbiego/DT78-App-Android)forked from [`mitchwongho/ESP-Alerts-for-Android`](https://github.com/mitchwongho/ESP-Alerts-for-Android) to send notifications to the watch

### Current status

Note: I may not update the android code on this repository [`DT78-App-Android`](https://github.com/fbiego/DT78-App-Android) so it should server as a starting point for anyone interested in building the app

#### Notification test video

[`Youtube`](https://youtu.be/2429i_2OC2A)

#### Implemented

* Notifications upto 120 characters to the watch
* Call & SMS listener (requires Contacts, Phone & SMS permission)
* Watch battery percentage on the ongoing notification (priority PRIORITY_MIN, IMPORTANCE_MIN)
* Find phone feature rings and locks phone then sends Phone battery percentage as notification to the watch (requires Device Admin permission)
