
TX indicates message to watch

RX indicates message from watch

# find watch
```
TX	AB 00 03 FF 71 80
```
# reset watch
```
TX  AB 00 04 FF 23 80 00
```

# shake camera
```
TX	AB 00 04 FF 79 80 01		//activate
TX	AB 00 04 FF 79 80 00		//cancel
RX	AB 00 04 FF 79 80 01		//
```

# watch face
```
TX	AB 00 06 FF 95 80 01 0F 0D	//last byte 0x0D is watchface 01..0E
//setting 01..0B causes blank watchface at dial selection from watch
```

# heart rate
```
TX	AB 00 04 FF 31 09 01		//activate
TX	AB 00 04 FF 31 09 00		//cancel
RX 	AB 00 05 FF 31 09 46 0E		//value 0x46 -> 70bpm

TX	AB 00 04 FF 31 0A 01		//activate realtime
RX	AB 00 05 FF 31 0A 49 1B
RX	AB 00 05 FF 31 0A 47 30
RX	AB 00 05 FF 31 0A 49 30
TX	AB 00 04 FF 31 0A 00		//cancel
```

# blood pressure
```
TX	AB 00 04 FF 31 21 01		//activate
TX	AB 00 04 FF 31 21 00		//cancel
RX	AB 00 05 FF 31 21 7C 4C		//value 0x7C -> 124mmHg & 0x4C -> 76mmHg

TX	AB 00 04 FF 31 22 01		//activate realtime
TX	AB 00 04 FF 31 22 00		//cancel
RX	AB 00 05 FF 31 22 71 4C		//value 0x7C -> 113mmHg & 0x4C -> 76mmHg
```

# blood oxygen
```
TX	AB 00 04 FF 31 11 01		//activate
TX	AB 00 04 FF 31 11 00		//cancel
RX	AB 00 05 FF 31 11 62 0E		//value 0x62 -> 98%

TX	AB 00 04 FF 31 12 01		//activate realtime
TX	AB 00 04 FF 31 12 00		//cancel
RX	AB 00 05 FF 31 12 62 30		//value 0x62 -> 98%
```

# all health data
```
TX	AB 00 04 FF 32 80 01		//activate
TX	AB 00 04 FF 32 80 00		//cancel
RX	AB 00 07 FF 32 80 44 61 72 4B	//heart rate, blood pressure, blood oxygen 
```

# find phone
```
TX	AB 00 04 FF 7D 80 01		//activate
TX	AB 00 04 FF 7D 80 00		//cancel
```

# watch battery level
```
TX	AB 00 04 FF 91 80 01		  // request
RX	AB 00 05 FF 91 80 00 50		// 00 notcharging; value 0x50 -> 80%
RX	AB 00 05 FF 91 80 01 50		// 01 charging; value 0x50 -> 80%
RX	AB 00 05 FF 91 80 02 64		// 02 fully charged; value 0x64 -> 100%
```

# raise to wake
```
TX	AB 00 04 FF 77 80 01		//activate
TX	AB 00 04 FF 77 80 00		//cancel
```

# Notification headers
The 7th byte determines which icon will be showed with the notification
Where XX is the length starting from byte FF,72,80.. and the notification content starts after the header
```
TX	AB 00 XX FF 72 80 01 02		//Call 3
TX	AB 00 XX FF 72 80 02 02		//cancel call
TX	AB 00 XX FF 72 80 03 02		//Message	0
TX	AB 00 XX FF 72 80 07 02		//QQ		8
TX	AB 00 XX FF 72 80 08 02		//Skype		7
TX	AB 00 XX FF 72 80 09 02		//Wechat	9
TX	AB 00 XX FF 72 80 0A 02		//Whatsapp	1
TX	AB 00 XX FF 72 80 0E 02		//Line		10
TX	AB 00 XX FF 72 80 0F 02		//Twitter	2
TX	AB 00 XX FF 72 80 10 02		//Messenger	6
TX	AB 00 XX FF 72 80 11 02		//Facebook	5
TX	AB 00 XX FF 72 80 12 02		//Instagram	4
TX	AB 00 XX FF 72 80 13 02		//Weibo		11
TX	AB 00 XX FF 72 80 14 02		//KakaoTalk	12
```

# phone call
```
TX	AB 00 0A FF 72 80 01 02 46 65 6C 69 78
TX	AB 00 05 FF 72 80 02 02			//cancel call notification
```

# messages
```
TX	AB 00 10 FF 72 80 03 02 46 65 6C 69 78 3A 48 65 6C 6C 6F
```

# whatsapp
```
TX	AB 00 0E FF 72 80 0A 02 42 69 65 67 6F 3A 20 48 69
TX	AB 00 28 FF 72 80 0A 02 57 68 61 74 73 41 70 70 3A 20 43 68		// long message split into 20 bytes
TX	00 65 63 6B 69 6E 67 20 66 6F 72 20 6E 65 77 20 6D 65 73 73		// next packet has header 00,01...
TX	01 61 67 65 73
```

# music control
```
TX	AB 00 04 FF 99 80 00	//play pause
TX	AB 00 04 FF 99 80 01	//previous
TX	AB 00 04 FF 99 80 02	//next
```
```
TX  AB 00 04 FF 9D 80 00	//play
TX  AB 00 04 FF 9D 80 01	//pause
TX  AB 00 04 FF 9D 80 02	//previous
TX  AB 00 04 FF 9D 80 02	//next
```

# set time
```
RX	AB 00 0B FF 93 80 00 07 E4 07 1F 14 2B 1B
//sets time                    M  D   h  m  s
```

# 12 hour system
```
TX  AB 00 04 FF 7C 80 01	//enable
TX  AB 00 04 FF 7C 80 02	//disable
```

# hourly measure
```
TX  AB 00 04 FF 78 80 01	//enable
TX  AB 00 04 FF 78 80 00	//disable
```

# quiet hours
```
TX  AB 00 08 FF 76 80 01 16 00 07 00	//enable from 22:00 to 7:00
TX  AB 00 08 FF 76 80 00 16 00 07 00	//disable
```

# alarm
```
//max 8 alarms
TX  AB 00 08 FF 73 80 00 01 07 00 80	//enable one time 7:00, byte[7](before 07) indicates state; 00 -> OFF, 01 -> ON
TX  AB 00 08 FF 73 80 00 01 07 00 7F	//enable everyday 7:00
TX  AB 00 08 FF 73 80 00 01 07 00 1F	//enable mon to fri 7:00
TX  AB 00 08 FF 73 80 00 01 07 00 43	//enable custom days 7:00  (null,Sun,Sat,Fri,Thu,Wed,Tue,Mon)‭[01000011]‬
```

# sedentary reminder
```
TX  AB 00 09 FF 75 80 01 0D 00 17 00 2D		//enable 13:00 to 23:00 0x2D -> interval 45mins
```

# OTA mode
```
TX  AB 00 04 FF 25 80 01		// caution. no exit. the watch will stay in this mode until the battery is low
```

# watch info
```
RX	AB 00 11 FF 92 C0 08 04 38 00 00 00 00 00 00 28 00 60 00 6B
```

# watch language
```
TX	AB 00 04 FF 7B 80 00	//last byte for language
```

# steps & hourly measurement data
```
TX	AB 00 09 FF 51 80 00 15 09 0A 0D 00	// request realtime
RX	AB 00 0E FF 51 08 00 09 7F 00 00 5A 00 00 00 00 00	//realtime steps & calories
RX	AB 00 16 FF 51 20 15 07 0B 07 00 03 7F 00 00 21 00 00 00 00 00 01 05 06 32 02	//hourly steps, calories & health data
```

# sleep data
```
RX	AB 00 0B FF 52 80 15 07 06 15 05 01 00 3A	//
```

# weather data
```
RX  AB 00 11 FF 7E 80 XY 12 00 15 00 15 10 16 00 15 10 15 10 15 // {Y -> 0/1 positive/negative} 12 -> 18°C (icon+sign & temperature value)
// the pattern suggests the set might be the weather prediction for 7 days (1 Week) [<not sure>]
// with the current watch only the first data is displayed
// X value determines the weather icon
// 0 - sun + cloud
// 1 - sun
// 2 - snow
// 3 - rain
// 4 - clouds
// 5 - tornado
// 6 - wind
// 7 - sun + haze
```
