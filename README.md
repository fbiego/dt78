# DT78 
DT78 Smartwatch Reverse Engineering

+ [`DT78 with ESP32 PCB video`](https://youtu.be/O0CNbZo6Kx4)
+ [`DT78 ESP32 firmware`](https://github.com/fbiego/dt78-esp32-firmware)

## Firmware

Analysis of the firmware using `binwalk` [`analysis`](https://github.com/fbiego/dt78/blob/master/firmware/analysis.md)

Firmware v8.05 and update procedure for iOS in chinese language [`here`](https://github.com/fbiego/dt78/tree/master/firmware/ios_ota_chinese)

[HS6620 Dumping JTAG](https://github.com/rbaron/HS6620D-smartwatch-reveng)

## BLE Protocol

- [`commands`](https://github.com/fbiego/dt78/blob/master/DT78_COMMANDS.md)

- [`types`](https://github.com/fbiego/dt78/blob/master/CMD_TYPES.md)

<!-- More info at this [`blog`](http://www.biego.tech/dt78) -->

## SPI flash

- [`Watch faces`](https://github.com/fbiego/dt78/blob/master/firmware/watchface.md)

## Hardware

- [`FPC Connectors pinout`](https://github.com/fbiego/dt78/blob/master/HARDWARE.md)


## Datasheets
Main IC - [`HS6620D`](https://github.com/fbiego/dt78/blob/master/datasheets/HS6620D_data_sheet_V3.0.pdf)

Flash Chip - [`XT25F128B`](https://github.com/fbiego/dt78/blob/master/datasheets/XTX-XT25F128BSSIGT.pdf)

Touch IC - [`CST816S`](https://github.com/fbiego/dt78/blob/master/datasheets/CST816S.pdf)

TFT LCD - [`GC9A01A`](https://github.com/fbiego/dt78/blob/master/datasheets/GC9A01A.pdf)

## ESP32

### LCD Touch Test

This arduino code [`dt78_lcd_touch_jpg`](https://github.com/fbiego/dt78/blob/master/dt78_lcd_touch_jpg/dt78_lcd_touch_jpg.ino) interfaces the LCD and touch screen with an ESP32 board. Images will be displayed from SPIFFS and can be scrolled using the touch screen.

[`LCD Touch Test video`](https://youtu.be/1j1_iY0G4Cs)

### Client

This arduino code [`dt78_ble_client`](https://github.com/fbiego/dt78/blob/master/dt78_ble_client/dt78_ble_client.ino) creates a client on the ESP32 board that connects to the smartwatch

Control lights using the watch [`Video`](https://youtu.be/IGo9HJPbSt0)

### Server

This arduino code [`dt78_ble_server`](https://github.com/fbiego/dt78/blob/master/dt78_ble_server/dt78_ble_server.ino) creates a server on the ESP32 board that emulates the services and characteristics of the DT78 smartwatch and connect to the WearFit 2.0 app

## Android App

Since this watch only supports notification from a few apps in the WearFit 2.0 app, I modified this code [`DT78-App-Android`](https://github.com/fbiego/DT78-App-Android) to send notifications to the watch

