
All commands to and from the watch follow a specific format, see [`DT78_COMMANDS.md`](https://github.com/fbiego/dt78/blob/master/DT78_COMMANDS.md)

`AB 00 xx FF yy ...`

`xx` is the packet length starting with `FF`

`yy` is the command type as shown below

```
20	connection (watch)
23	reset watch
25	OTA update mode
28	firmware info
31	heart rate, blood pressure & oxygen
32	all health data
51	steps data
52	sleep data
53	drink water reminder
71	find watch
72	notifications
73	alarms
74	user details
75	sedentary
76	quiet hours
77	raise to wake
78	hourly measure
79	shake camera
7A	
7B	
7C	12 hour system
7D	find phone
7E	weather data
7F	sleep time
85	
87	connection response (watch)
88	future weather data (high/low)
8A	
8B	
91	battery
92	device type & firmware version
93	set time
95	watch face
96	
99	music control
9B	device settings in app
9C	watchface text font & color settings
9D	music control +
9E	reminder setting (type[exercise 0x00, medicine 0x01, book 0x02, trip 0x03], enabled, time, interval)
9F	overlook reminder (interval)
A0	enabled reminders (sed 0x01, drink 0x02, overlook 0x08, exercise 0x10, medicine 0x20, book 0x40, trip 0x80)
A1	disconnect from app
A2	contact name
A3	contact number
A5	contact size & sos contact id
A6	
A7	
A8	QR codes (contact & payment)
C9	
E4	barometer & altitude data
FF	
```
