


### Notifications

These commands are used to test whether the corresponding notification icon is supported on the watch.
If the watch does not display the notification, that means that is is not supported


- `AB0009FF7280010274657374`		//Call
- `AB0005FF72800202`		//cancel call
- `AB0009FF7280030274657374`		//Message
- `AB0009FF7280070274657374`		//QQ
- `AB0009FF7280080274657374`		//Skype
- `AB0009FF7280090274657374`		//Wechat
- `AB0009FF72800A0274657374`		//Whatsapp
- `AB0009FF72800E0274657374`		//Line
- `AB0009FF72800F0274657374`		//Twitter
- `AB0009FF7280100274657374`		//Facebook
- `AB0009FF7280110274657374`		//Messenger
- `AB0009FF7280120274657374`		//Instagram
- `AB0009FF7280130274657374`		//Weibo
- `AB0009FF7280140274657374`		//KakaoTalk
- `AB0009FF7280160274657374`		//Viber
- `AB0009FF7280180274657374`		//Telegram

You can check for additional icon support by changing the icon value in the brackets as shown below
- AB0009FF7280[18]0274657374

Note that the values is in hex format 19, 1A..1F, 20, 21

From the commands above notice that some missing values 04..06, 0B..0D. It is necessary to check as some watches may support it
