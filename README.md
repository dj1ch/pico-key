# pico-key
A POC using python and circuitpython to exploit a target machine, with a keylogger and a server written in python. 

### Development progress
This [project](https://github.com/users/dj1ch/projects/3) showcases my progress thus far.

### Install guide
TBA, I don't plan on making an install guide until everything is set up. 

### The attack: explained
This simple keystroke injection is complex, starting with one thing, the Raspberry Pi Pico. This is just how I plan for it to work, this may not be 100% possible but it will by the time development is done.

1. First, the Pico is plugged into the target device. The first thing it does is do the keystroke injection attack on the computer. It downloads the *[server.py](/victim/server.py)* and installs python. It then runs that server.py file. 

Hopefully you can obtain the hostname of the machine by running: 

```shell
ping <machine_ip_here>
```

This should return the output that will show the machine IP and hostname most likely. 

2. The Pico after this step can be unplugged by the victim. Assuming they're already suspicious, they should throw it out or something like that. Hopefully you will be able to recover the device.

3. The file just ran by python on the target machine will start a server on a specific IP address(will add later) on the local network. Hopefully, you have access to this network, as this will help create an SSH(Secure Shell) server on the target machine. 

4. If you have that IP address, you will have remote access to the machine. From here, do what you want with the target machine.

**Before asking to install, this is merely a blueprint for what I will be working on for the next couple weeks!**

### FAQ
TBA 

### Contributing
TBA, will add contributing guidelines soon

**Made with :heart: from [@dj1ch](https://github.com/dj1ch)**
