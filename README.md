# pico-key
A physical pentesting toolkit on a regular Raspberry Pi Pico. 

### Intro
The Raspberry Pi Pico is a flexible microcontroller board designed for multiple purposes. With this project I intend to use make a powerful Keystroke Injection tool for such an intricate board with a special purpose. It is designed to be easy to configure, modify, and use for fun. This will be designed to be a little more than a *Bad USB*.

### Development progress
This [project](https://github.com/users/dj1ch/projects/3) showcases my progress thus far. 

### Install guide

**Note: You need to install the latest (stable) version of Circuitpython for this to work.**

TBA, I don't plan on making an install guide until everything is set up. 

### The attack: explained
Unlike your usual *Bad USB*, the setup is a lot more complex. 

1. When it boots up, it checks your `config.py` to determine whether or not it will run the duckyscript on startup. Regardless if set to `True` or `False`, it will not run if there is nothing in the `payload.dd`, the default payload.

2. If not running the payload, it will open the shell, which allows you to edit payloads, test payloads, control GPIO, etc

3. Your config must be edited to allow the script to be run on startup after editing it, using the shell or your computer.

**Before asking to install, this is merely a blueprint for what I will be working on for the next couple weeks!**

### FAQ
TBA 

### Contributing
TBA, will add contributing guidelines soon

**Made with :heart: from [@dj1ch](https://github.com/dj1ch)**
