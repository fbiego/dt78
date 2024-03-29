


### Notifications

These commands are used to test whether the corresponding notification icon is supported on the watch.
If the watch does not display the notification, that means that it is not supported

| ID | Test Command | Icon |
| --- | --- | --- |
| 0x01 | `AB0009FF7280010274657374` | Call |
| 0x02 | `AB0005FF72800202` | cancel call |
| 0x03 | `AB0009FF7280030274657374` | Message |
| 0x04 | `AB0009FF7280040274657374` | Mail |
| 0x05 | `AB0009FF7280050274657374` | Calendar |
| 0x06 | `AB0009FF7280060274657374` |  |
| 0x07 | `AB0009FF7280070274657374` | QQ |
| 0x08 | `AB0009FF7280080274657374` | Skype |
| 0x09 | `AB0009FF7280090274657374` | Wechat |
| 0x0A | `AB0009FF72800A0274657374` | Whatsapp |
| 0x0B | `AB0009FF72800B0274657374` | Gmail |
| 0x0C | `AB0009FF72800C0274657374` | Hangouts |
| 0x0D | `AB0009FF72800D0274657374` | Downloads |
| 0x0E | `AB0009FF72800E0274657374` | Line |
| 0x0F | `AB0009FF72800F0274657374` | Twitter |
| 0x10 | `AB0009FF7280100274657374` | Facebook |
| 0x11 | `AB0009FF7280110274657374` | Messenger |
| 0x12 | `AB0009FF7280120274657374` | Instagram |
| 0x13 | `AB0009FF7280130274657374` | Weibo |
| 0x14 | `AB0009FF7280140274657374` | KakaoTalk |
| 0x15 | `AB0009FF7280150274657374` |  |
| 0x16 | `AB0009FF7280160274657374` | Viber |
| 0x17 | `AB0009FF7280170274657374` | VKontakte |
| 0x18 | `AB0009FF7280180274657374` | Telegram |
| 0x19 | `AB0009FF7280190274657374` |  |
| 0x1A | `AB0009FF72801A0274657374` | Snapchat |
| 0x1B | `AB0009FF72801B0274657374` | DingTalk |
| 0x1C | `AB0009FF72801C0274657374` | Alipay |
| 0x1D | `AB0009FF72801D0274657374` | Tiktok |
| 0x1E | `AB0009FF72801E0274657374` |  |
| 0x1F | `AB0009FF72801F0274657374` |  |
| 0x20 | `AB0009FF7280200274657374` | Whatsapp Business |
| 0x21 | `AB0009FF7280210274657374` |  |
| 0x22 | `AB0009FF7280220274657374` | Wearfit Pro |

You can check for additional icon support by changing the icon value in the brackets as shown below
- `AB0009FF7280[18]0274657374`

Note that the values is in hex format 19, 1A..1F, 20, 21

Not all commands may be supported especially on older firmware
