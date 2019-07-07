# HC6502 #
![HC6502](https://github.com/wuxx/HC6502/blob/master/doc/HC6502.jpg)

#### [自己动手做计算机之HC6502 综述] ####
这是实验室推出的一个相对较复杂的开源DIY项目，通过自己动手搭建一个小型计算机HC6502，可以让你真正从底层自下而上、从硬件到软件完全理解一个完整的系统，对CPU、内存、外设、软件驱动的原理有一个更加深刻的认识。
HC6502 支持ps/2键盘的输出，以及vga显示输出，通过uart shell可实现更多的控制操作，支持串口、gpio操作。
通过适当的扩展，可以用HC6502来做很多好玩的项目，比如可以使用串口wifi模块接入到internet，将HC6502变成一个web服务器；当然也可以作为一般的单片机使用，用gpio来作一些控制；也可以尝试编写一些小游戏，使用vga显示器和键盘进行游戏显示和操作；...。
HC6502全系统分为四片电路板：
1 主板
主板上包括CPU 6502，EEPROM AT28C256、SRAM 61256、译码模块、GPIO 6522，以及UART 6551，两个牛角座用于和键盘、显示器连接。
2 EEPROM 编程器
HC6502使用了一片32KB的并行的EEPROM AT28C256作为非易失存储，也就是相当于是'硬盘'，由于市面上用于烧写并行EEPROM的设备并不多，而且价格极为昂贵（价格普遍在百元以上），所以我们自己制作了一个简单的烧录器，使用串口命令来将系统镜像烧录至EEPROM中。
3 PS2 键盘 驱动板
HC6502 可以使用键盘，这里自制了一块驱动板，用于将键盘协议转换成自定义的数据通信协议。
4 VGA驱动板
这里使用了一个STM32单片机来进行VGA的驱动，和主板之间通过自定义数据通信协议来传输控制信息和数据信息。
HC6502的所有的资料均可在https://github.com/wuxx/HC6502获取，欢迎感兴趣的朋友一起参与完善优化。

#### [自己动手做计算机之HC6502 主板-硬件] ####
#### [自己动手做计算机之HC6502 主板-软件] ####
#### [自己动手做计算机之HC6502 EEPROM编程器-硬件] ####
#### [自己动手做计算机之HC6502 EEPROM编程器-软件] ####
#### [自己动手做计算机之HC6502 PS/2键盘驱动板-硬件] ####
#### [自己动手做计算机之HC6502 PS/2键盘驱动板-软件] ####
#### [自己动手做计算机之HC6502 VGA显示驱动板-硬件] ####
#### [自己动手做计算机之HC6502 VGA显示驱动板-软件] ####
#### [自己动手做计算机之HC6502 后记] ####

reference:
6502-home-computer
http://www.grappendorf.net/projects/6502-home-computer/eeprom-and-a-first-program.html
红白机拆机
https://zh.ifixit.com/Guide/%E4%BB%BB%E5%A4%A9%E5%A0%82FC%E6%8B%86%E8%A7%A3/3199
6502 CPU
https://wiki.nesdev.com/w/index.php/CPU_pin_out_and_signal_description
https://wiki.nesdev.com/w/index.php/Nesdev#6502
http://wilsonminesco.com/6502primer/MysteryPins.html
https://user.xmission.com/~trevin/atari/6502_pinout.html
https://ist.uwaterloo.ca/~schepers/MJK/6502.html