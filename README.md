# NanoBench

This is a simple portable hardware tool that allows for easy, multifunctional, visual development and testing.  The [Arduino Nano](https://www.arduino.cc/en/pmwiki.php?n=Main/ArduinoBoardNano) is a relatively inexpensive MCU board, with mulitple ports which can be used to drive a [ILI9341 tft display](https://cdn-shop.adafruit.com/datasheets/ILI9341.pdf) and read and write digital and analogue signals.  The NanoBench utilises this to create a reusable base for modular sense and control applications which benefit from having a display.  Extender Modules are thus developed to take advantage of the readily accessible ports and the permanaent display. [Adafruit](https://www.adafruit.com/) have helpfully published drivers for this display, making this a simple project.  Similar devices can be easily made with other MCU units with more features, and I will make them to be compatible with the extender modules.   

One key goal is allow integrated programmability of the nanobench (i.e. not requiring uploading from a PC).  A parsible scripting program is required as well as an interface for this to be entered and editted directly on the Nano...whether this is actually possible given the limited resources of the Nano is to be explored.

![Version 0.1](https://github.com/saiftynet/NanoBench/blob/main/Images/nanobench.jpg)

In this version the nano board is exposed to allow access to the reset button, LEDs.  There an ON off switch.  The power pins are brought out to headers on either side of the box (one side for 5V, the other for 3.3V, an I2C port is positioned at the back of the box...not visible. In the front the remaining pins are made available for extender modules. 

## The Parts

* The prototype box is roughly cut from 7.5cm square bits of plywood.
* An arduino nano or clone is required, with associated header pins
* Resistors for level shifting...I had 2.2K and 1.5k resistors (other combinations may be used to covert 5V logic to 3.3V logic of the display board) and level shifter may be used as well.
* A display unit...for my usecase the 2.2in 320X240 display worked well
* A 9V battery connector and battery was used to make the unit stand alone...a rechargeable version will be made 
* Banana plug headers for the 5v, 3.3V and Gnd
* a 4 pin JST connector for the I2C port

## The Wiring

A the diplay is connected via the  

## The Basic Sketches

## Extender Modules
