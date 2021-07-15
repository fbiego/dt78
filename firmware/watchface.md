# Watch Face

The [`flash.bin`](https://github.com/fbiego/dt78/raw/master/firmware/flash.bin) file is extracted from the SPI Flash chip used in the watch.

Using [`rawpixels.net`](http://rawpixels.net/), watchafces can be visualized on the following offsets;

>- 2877966
>- 3662510
>- 3752484
>- 4411727
>- 4972934
>- 5851767
>- 5974157
>- 6608472
>- 7541023

settings used is `240` x `240`, `RGB8` format

It is not clear which format is used as RGB8 gives a discolored output

![1](watchface.jpeg?raw=true "3")

I modified half of the bytes to 0xFF (which is white in RGB8) but this gives a bluish color
