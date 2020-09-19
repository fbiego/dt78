
### `binwalk`
```
DECIMAL       HEXADECIMAL     DESCRIPTION
--------------------------------------------------------------------------------
```

### `binwalk -E`
```
DECIMAL       HEXADECIMAL     ENTROPY
--------------------------------------------------------------------------------
0             0x0             Falling entropy edge (0.752814)
71680         0x11800         Falling entropy edge (0.830587)
```

### `binwalk -Y`
```
DECIMAL       HEXADECIMAL     DESCRIPTION
--------------------------------------------------------------------------------
174           0xAE            ARM executable code, 16-bit (Thumb), little endian, at least 1827 valid instructions
```

### `strings -tx`
```
   11b4 ..\..\..\User_Application\main.c
   16a8 %02X:%02X:%02X:%02X:%02X:%02X
  1069c 0123456789abcdef
  106b0 0123456789ABCDEF
  10c10 ..\..\src\a3\bb_a3.c
  10c28 state < BB_STATE_MAX
  10e8c ..\..\src\a3\bb_connecting_a3.c
  10eac link != NULL
  112c0 ..\..\src\a3\bb_connecting_a3.c
  112e0 link->slv_win / 2 <= LE_MAX_WIN_EXT
  11307  bbc_env.slv_win_remain > 0
  11484 ..\..\src\a3\bb_connecting_a3.c
  114a4 link->role == ROLE_SLAVE
  11620 ..\..\src\a3\bb_connecting_a3.c
  11640 prev_full_rx_win > 0
  11658 cur_full_rx_win >= prev_full_rx_win
  12998 prev->next == next
  12a14 entry->prev->next == entry
  12a30 entry->next->prev == entry
  12a84 time <= CO_MAX_SYS_TIME
  12ac4 time <= CO_MAX_SYS_TIME
  14480 Smart Watch 4
  151d4 ..\..\..\User_Application\main.c
  156fc time <= CO_MAX_SYS_TIME
  158dc Application Start!!
  15a70 ..\..\..\User_Application\main.c
  16090 ..\..\..\User_Application\main.c
  16178 ..\..\..\User_Application\main.c
  17994 ..\..\..\User_Application\main.c
  17c54 ..\..\..\User_Application\main.c
  192f5  "#%&()+,./1235689:<=?@ACDEGHIJLMNOQRSTUVXYZ[\]^_`abcdefghijjklmnoopqqrsstuuvvwxxyyzzz{{|||}}}}~~~~~
  19360 __co_list_add
  193ac bb_sche_new
  193b8 co_list_del
  193c4 co_time_increase
  193d5 co_time_decrease
  19407 ' Nbbc_widen_next_win
  1941d bbc_slave_sync
  1942c bbc_handle_slave_new
  19441 bbc_handle_new
  19450 co_time_increase
  19468 com.atebits.Tweetie2
  19480 com.apple.MobileSMS
  19494 com.apple.facetime
  194a8 jp.naver.line
  194b8 com.apple.mobilephone
  194d0 com.skype.skype
  194e0 com.iwilab.KakaoTalk
  194f8 com.facebook.Facebook
  19510 com.apple.mobilecal
  19524 com.google.Gmail
  19538 com.apple.mobilemail
  19550 com.burbn.instagram
  19564 com.tencent.xin
  19574 com.sina.weibo
  19584 net.whatsapp.WhatsApp
  1959c com.tencent.mqq
  195ac com.facebook.Messenger
  195c4 com.google.hangouts
  195d8 com.google.inbox
  195ec ..\..\..\..\..\..\components\ble\device_manager\device_manager_peripheral.c
  19638 ..\..\..\..\..\branches\hs6620_rom_a3_lib_include\coroutine\co_list.h
  19680 ..\..\..\..\..\branches\hs6620_rom_a3_lib_include\coroutine\co_time.h
```
