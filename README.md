# DT78 
DT78 Smartwatch Reverse Engineering

## Firmware
Analysis of the firmware using `binwalk` [`analysis`](https://github.com/fbiego/dt78/blob/master/firmware/analysis.md)

Firmware v8.05 and update procedure for iOS in chinese language [`here`](https://github.com/fbiego/dt78/tree/master/firmware/ios_ota_chinese)

By using Wireshark, nRF Connect app & an ESP32 board, I was able to decode the following [`commands`](https://github.com/fbiego/dt78/blob/master/DT78_COMMANDS.md), [`types`](https://github.com/fbiego/dt78/blob/master/CMD_TYPES.md)

More info at this [`blog`](http://www.biego.tech/dt78)

Flash chip used in the watch - [`XT25F128B`](https://github.com/fbiego/dt78/blob/master/XTX-XT25F128BSSIGT.pdf)

#### Telegram

Join the telegram group [`DT78 Smartwatch`](https://t.me/dt78app)

#### Notification test video

Custom app for relaying notifications 
[`Youtube`](https://youtu.be/2429i_2OC2A)

## ESP32

### Client

This arduino code [`dt78_ble_client`](https://github.com/fbiego/dt78/blob/master/dt78_ble_client/dt78_ble_client.ino) creates a client on the ESP32 board that connects to the smartwatch

Control lights using the watch [`Video`](https://youtu.be/IGo9HJPbSt0)

### Server

This arduino code [`dt78_ble_server`](https://github.com/fbiego/dt78/blob/master/dt78_ble_server/dt78_ble_server.ino) creates a server on the ESP32 board that emulates the services and characteristics of the DT78 smartwatch and connect to the WearFit 2.0 app

## Android App

Since this watch only supports notification from a few apps in the WearFit 2.0 app, I modified this code [`DT78-App-Android`](https://github.com/fbiego/DT78-App-Android) to send notifications to the watch

