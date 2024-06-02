# ⚠️ Project Archived...

> [!WARNING]
> I will no longer continue development due to a lack of maintenance and time. Use at your own risk, any issue made will not be acknowledged. However, this project is currently being rewritten currently.

<details>
<summary>Old README.md</summary>

# pico-key

A physical pentesting toolkit on a regular Raspberry Pi Pico.

## Intro

You've probably seen other similar tools for other MCUs and SBCs, such as the ESP32 Marauder, ESP8266 Deauther, P4wnP1 A.L.O.A, PocketPhishr, Pwnagotchi, etc. Although these are all very good projects, there hasn't been much talk regarding the Raspberry Pi Pico becoming a good tool in the right hands.

The Raspberry Pi Pico is a flexible microcontroller board designed for multiple purposes. With this project, I intend to use make a powerful Keystroke Injection tool for such an intricate board with a special purpose. It is designed to be easy to configure, modify, and use for fun. This will be designed to be a little more than a *Bad USB*. Instead of being a basic, high-level program on a Pico, we build firmware designed for keystroke injection.

### Development Progress

This [project](https://github.com/users/dj1ch/projects/3) showcases my progress thus far.

### Install guide

**For testing only!**

When the code is ready, run the following:

First, we install dependencies.

```bash
sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib -y
```

```bash
cd pico-key-*/pico-key
mkdir build
cd build
cmake ..
make pico-key
```

### The attack: explained

Unlike your usual *Bad USB*, this is a lot more complex.

1. When it boots up, it checks your `config.c` to determine whether or not it will run the duckyscript on startup, then also spoofs the Pico's serial number, product type, etc to make it look like a USB to the host system. Regardless if set to `true` or `false` is set in `config.c`, it will not run if there is nothing in a memory buffer which contains your duckyscript.

2. If not running the payload, it will open the shell, which allows you to edit payloads, test payloads, control GPIO, etc. Other additional tools can be used.

3. From the shell, you will need to create a script manually, which will remain consistent after reboots.

4. Your config must be edited to allow the script to be run on startup after editing it, also done using the shell.

5. The `tinyusb` library takes the duckyscript from the specified memory address for which the buffer is located and writes it to the host when it boots up, assuming that the configuration is set correctly.

Essentially, this is just a *Metasploit-style* pentesting tool for the Raspberry Pi Pico.

Think of the whole process like this:

```text
shell user input -> formatted in an array -> array written to formatted part of memory -> interpreted on boot -> directly translates to commands/keys -> commands used and written to host
```

Although you as the user only sees:

```text
shell user input -> saved to memory -> written to host
```

Kind of a complex process but it still works!

**Before asking to install, this is merely a blueprint for what I will be working on for the next couple of weeks!**

### The shell

The shell allows you to do a fair share of things with the board, allowing you to make it look like a USB drive by blinking the LED, checking board stats, and testing of payloads. I plan on making this a very small "OS" for the Pico to do basic things.

### FAQ

**How long will it be until a release?**

Most of the changes haven't been tested and it is yet to work as intended. This might take a while depending on how long it will take to implement the wanted feature(s). Most likely this will all be finalized sometime around late summer (July to August) 2024.

**Can it do things other than Keystroke injection?**

It's pretty bare bones right now, it has a work-in-progress text editor, to build the scripts on the board without having to worry about editing the files on your computer, along with being able to test scripts on the device it is plugged into. Unless we can implement some way to control GPIO over the shell, it does only keystroke injection. The OS itself is minimal and can only do so much.

### Contributing

TBA will add contributing guidelines soon

**Made with :heart: by [@dj1ch](https://github.com/dj1ch)**

</details>
