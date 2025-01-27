
# HP-PrimeWeb
#### Internet on the HP Prime
# DOESN"T WORK DONT TRY - ABANDONED
## Important
You must change SSID and PASSWORD at the top of the ESP32 code to your wifi name and password.
  
## Setup

You need a Arduino Leonardo (You can find one for $10 online. [The one I use!](https://www.keyestudio.com/products/keyestudio-atmega32u4-leonardo-r3-development-board-1m-micro-usb-cable-for-diy-project)). You are also going to need an ESP32 dev board. I was able to find one on AliExpress for $1. 
  
The two will be communicating over serial, but because the usb port on the Arduino will be used up by the USB-HID Connection to the calculator, you have to wire the serial pins of the arduino to the serial pins of the ESP32. The only problem is that the ESP32 operates at 3.3V and the Arduino at 5V. The only way to deal with this (at least I think) is to use a level shifter. You can purchase them, but I made one [with this tutorial](https://www.instructables.com/DIY-5v-to-33v-Logic-Level-Shifter/).
  
To get it to work, you first have to flash the ESP32 and Arduino with the included Firmware using the Arduino IDE or CLI. Make sure to also install the HP Prime Program on your calculator. Also to make it more portable, you can wire the ESP32 to get 3.3V power and gnd from the Arduino. Once everything is wired and connected, use the included HP Prime Program to send and recieve the website!
