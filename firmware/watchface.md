# Watch Face

The [`flash.bin`](https://github.com/fbiego/dt78/raw/master/firmware/flash.bin) file is extracted from the SPI Flash chip used in the watch.

Using [`rawpixels.net`](http://rawpixels.net/), watchfaces can be visualized on the following offsets;

>- 2877966
>- 3662510
>- 3752484
>- 4411728
>- 4972934
>- 5851767
>- 5974157
>- 6608472
>- 7541023

settings used is `240` x `240`, `RGB8` format

RGB8 gives a discolored output because indexed colors are used

![1](watchface.jpeg?raw=true "3")

## Decoded
I have decoded some watch by mapping the pixel to the color lookup table located just before the watchface location

Load the following files on [`rawpixels.net`](http://rawpixels.net/) to see the decoded watchface

settings used is `240` x `240`, `RGB565` format, Little Endian is enabled

- [`3752484.bin`](https://github.com/fbiego/dt78/raw/master/firmware/decoded/3752484.bin)
- [`4411727.bin`](https://github.com/fbiego/dt78/raw/master/firmware/decoded/4411728.bin)
