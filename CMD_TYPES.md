
All commands to and from the watch follow a specific format, see [`DT78_COMMANDS.md`](https://github.com/fbiego/dt78/blob/master/DT78_COMMANDS.md)

`AB 00 xx FF yy ...`

`xx` is the packet length starting with `FF`

`yy` is the command type as shown below

```
23	reset watch
25	OTA update mode
28	firmware info
31	heart rate, blood pressure & oxygen
51	steps data
52	sleep data
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
91	battery
92	device type & firmware version
93	set time
95	watch face
96	
99	music control
9B  device settings in app
9C
A1	disconnect from app
A5	
A6	
FF	
```
