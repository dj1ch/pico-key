# pico-key
A physical pentesting toolkit on a regular Raspberry Pi Pico. 

### Intro
You've probably seen other similar tools for other MCU's and SBC's, such as the ESP32 Marauder, ESP8266 Deauther, P4wnP1 A.L.O.A, PocketPhishr, Pwnagotchi, etc. Although these are all very good projects, there hasn't been much talk regarding the Raspberry Pi Pico becoming a good tool in the right hands. 

The Raspberry Pi Pico is a flexible microcontroller board designed for multiple purposes. With this project, I intend to use make a powerful Keystroke Injection tool for such an intricate board with a special purpose. It is designed to be easy to configure, modify, and use for fun. This will be designed to be a little more than a *Bad USB*. Instead of being a basic, high-level program on a Pico, we build firmware designed for keystroke injection.

### Development progress
This [project](https://github.com/users/dj1ch/projects/3) showcases my progress thus far. 

### Install guide

TBA, I don't plan on making an install guide until everything is set up. 

### The attack: explained
Unlike your usual *Bad USB*, the setup is a lot more complex. 

1. When it boots up, it checks your `config.h` to determine whether or not it will run the duckyscript on startup. Regardless if set to `true` or `false`, it will not run if there is nothing in the `payload.dd`, the default payload.

2. If not running the payload, it will open the shell, which allows you to edit payloads, test payloads, control GPIO, etc.

3. Your config must be edited to allow the script to be run on startup after editing it, using the shell or your computer.

**Before asking to install, this is merely a blueprint for what I will be working on for the next couple of weeks!**

### The shell

The shell allows you to do a fair share of things with the board, allowing you to make it look like a USB drive by blinking the LED, checking board stats, and testing of payloads. I plan on making this a very small "OS" for the Pico to do basic things.

### FAQ

**How long will it be until a release?**

Most of the changes haven't been tested and it is yet to work as intended. This might take a while depending on how long it will take to implement the wanted feature(s). Most likely this will all be finalized sometime around late April 2024

**Can it do things other than Keystroke injection?**

It's pretty bare bones right now, it has a work-in-progress text editor, to build the scripts on the board without having to worry about editing the files on your computer, along with being able to test scripts on the device it is plugged into. Unless we can implement some way to control GPIO over the shell, it does only keystroke injection. The OS itself is minimal and can only do so much.

### Contributing

TBA will add contributing guidelines soon

**Made with :heart: by [@dj1ch](https://github.com/dj1ch)**
