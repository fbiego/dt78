# DT78 
DT78 Smartwatch Reverse Engineering

## Firmware

Analysis of the firmware using `binwalk` [`analysis`](https://github.com/fbiego/dt78/blob/master/firmware/analysis.md)

Firmware v8.05 and update procedure for iOS in chinese language [`here`](https://github.com/fbiego/dt78/tree/master/firmware/ios_ota_chinese)

[`commands`](https://github.com/fbiego/dt78/blob/master/DT78_COMMANDS.md)

[`types`](https://github.com/fbiego/dt78/blob/master/CMD_TYPES.md)

More info at this [`blog`](http://www.biego.tech/dt78)

### [`Watch faces`](https://github.com/fbiego/dt78/blob/master/firmware/watchface.md)


[HS6620 Dumping JTAG](https://github.com/rbaron/HS6620D-smartwatch-reveng)

## Hardware

### Touch Pinout

| FPC | Pin |
| --- | --- |
| 1 | TSCL |
| 2 | TSDA |
| 3 | TINT |
| 4 | TRST |
| 5 | VCC |
| 6 | GND |

### TFT LCD Pinout

| FPC | Pin |
| --- | --- |
| 1 | LEDK |
| 2 | SDA |
| 3 | LEDA |
| 4 | SCLK |
| 5 | IOVCC18 |
| 6 | RESET |
| 7 | IOVCC18 |
| 8 | CS |
| 9 | TE |
| 10 | GND |
| 11 | A0|
| 12 | GND |
| 13 | VCC28 |
| 14 | GND |
| 15 | VCC28 |

## Datasheets
Main IC - [`HS6620D`](https://github.com/fbiego/dt78/blob/master/datasheets/HS6620D_data_sheet_V3.0.pdf)

Flash Chip - [`XT25F128B`](https://github.com/fbiego/dt78/blob/master/datasheets/XTX-XT25F128BSSIGT.pdf)

Touch IC - [`CST816S`](https://github.com/fbiego/dt78/blob/master/datasheets/CST816S.pdf)

TFT LCD - [`GC9A01A`](https://github.com/fbiego/dt78/blob/master/datasheets/GC9A01A.pdf)

## ESP32

### LCD Touch Test

This arduino code [`dt78_lcd_touch_jpg`](https://github.com/fbiego/dt78/blob/master/dt78_lcd_touch_jpg/dt78_lcd_touch_jpg.ino) interfaces the LCD and touch screen with an ESP32 board. Images will be displayed from SPIFFS and can be scrolled using the touch screen.

### Client

This arduino code [`dt78_ble_client`](https://github.com/fbiego/dt78/blob/master/dt78_ble_client/dt78_ble_client.ino) creates a client on the ESP32 board that connects to the smartwatch

Control lights using the watch [`Video`](https://youtu.be/IGo9HJPbSt0)

### Server

This arduino code [`dt78_ble_server`](https://github.com/fbiego/dt78/blob/master/dt78_ble_server/dt78_ble_server.ino) creates a server on the ESP32 board that emulates the services and characteristics of the DT78 smartwatch and connect to the WearFit 2.0 app

## Android App

Since this watch only supports notification from a few apps in the WearFit 2.0 app, I modified this code [`DT78-App-Android`](https://github.com/fbiego/DT78-App-Android) to send notifications to the watch

