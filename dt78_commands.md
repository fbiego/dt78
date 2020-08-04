
TX indicates message to watch
RX indicates message from watch

## find watch
```
TX	AB 00 03 FF 71 80
```

## shake camera
```
TX	AB 00 04 FF 79 80 01		//activate
TX	AB 00 04 FF 79 80 00		//cancel
RX	AB 00 04 FF 79 80 01		//received when watch shaked
```

## watch face
```
TX	AB 00 06 FF 95 80 01 0F 0D	//last byte 0x0D is watchface 01..0E
// setting 01..0B causes blank watchface at dial selection from watch
```

## heart rate
```
TX	AB 00 04 FF 31 09 01		//activate
TX	AB 00 04 FF 31 09 00		//cancel
RX 	AB 00 05 FF 31 09 46 0E		//value 0x46 -> 70bpm

TX	AB 00 04 FF 31 0A 01		// realtime
RX	AB 00 05 FF 31 0A 49 1B
RX	AB 00 05 FF 31 0A 47 30
RX	AB 00 05 FF 31 0A 49 30
RX	AB 00 05 FF 31 0A 49 30
RX	AB 00 05 FF 31 0A 47 30
TX	AB 00 04 FF 31 0A 00
```

## blood pressure
```
TX	AB 00 04 FF 31 21 01		//activate
TX	AB 00 04 FF 31 21 00		//cancel
RX	AB 00 05 FF 31 21 7C 4C		//value 0x7C -> 124mmHg & 0x4C -> 76mmHg
```

## blood oxygen
```
TX	AB 00 04 FF 31 11 01		//activate
TX	AB 00 04 FF 31 11 00		//cancel
RX	AB 00 05 FF 31 11 62 0E		//value 0x62 -> 98%
```

## find phone
```
TX	AB 00 04 FF 7D 80 01		//activate
TX	AB 00 04 FF 7D 80 00		//cancel
```

## watch battery level
```
RX	AB 00 05 FF 91 80 00 50		//value 0x50 -> 80%
```

## raise to wake
```
TX	AB 00 04 FF 77 80 01		//activate
TX	AB 00 04 FF 77 80 00		//cancel
```

## Notification headers
The 7th byte determines which icon will be showed with the notification
Where XX is the length starting from byte FF,72,80.. and the notification content starts after the header
```
TX	AB 00 XX FF 72 80 01 02		//Call
TX	AB 00 XX FF 72 80 02 02		//cancel call
TX	AB 00 XX FF 72 80 03 02		//Message
TX	AB 00 XX FF 72 80 07 02		//QQ
TX	AB 00 XX FF 72 80 08 02		//Skype
TX	AB 00 XX FF 72 80 09 02		//Wechat
TX	AB 00 XX FF 72 80 0A 02		//Whatsapp
TX	AB 00 XX FF 72 80 0E 02		//Line
TX	AB 00 XX FF 72 80 0F 02		//Twitter
TX	AB 00 XX FF 72 80 10 02		//Messenger
TX	AB 00 XX FF 72 80 11 02		//Messenger
TX	AB 00 XX FF 72 80 12 02		//Instagram
TX	AB 00 XX FF 72 80 13 02		//Weibo
TX	AB 00 XX FF 72 80 14 02		//KakaoTalk
```

## phone call
```
TX	AB 00 0A FF 72 80 01 02 46 65 6C 69 78
TX	AB 00 05 FF 72 80 02 02			//cancel call notification
```

## messages
```
TX	AB 00 10 FF 72 80 03 02 46 65 6C 69 78 3A 48 65 6C 6C 6F
```

## whatsapp
```
TX	AB 00 0E FF 72 80 0A 02 42 69 65 67 6F 3A 20 48 69

TX	AB 00 28 FF 72 80 0A 02 57 68 61 74 73 41 70 70 3A 20 43 68		// long packet split into 20 bytes
TX	00 65 63 6B 69 6E 67 20 66 6F 72 20 6E 65 77 20 6D 65 73 73		// next packet has header 00,01...
TX	01 61 67 65 73
```

## music control
```
TX	AB 00 04 FF 99 80 00		//play pause
TX	AB 00 04 FF 99 80 01		//previous
TX	AB 00 04 FF 99 80 02		//next
```
