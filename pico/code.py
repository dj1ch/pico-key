# this is the code for the pico. this requires circuitpython 8.29(latest version)
#
# for keystrokes:
#
# kbd.press(keycode.<letter/button>)
# time.sleep(1)
# kbd.release(keycode.<letter/button previously user>)
# 
# you can also do: 
#
# kbd.release_all() 
#
# this will release all keys if you combine them with other keys.
#
# kbd.press(keycode.<1st key/button>, keycode.<2nd key/button>)
# time.sleep(1)
# kbd.release_all()
#
# for mouse movement:
#
# mouse.move(<x>,<y>)
# mouse.click(mouse.<side>_BUTTON)
# time.sleep(1)
#


import board
import digitalio
import time
import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keycode import Keycode
from adafruit_hid.mouse import Mouse

# instance of mouse
mouse = Mouse(usb_hid.devices)

# instance of keyboard
kbd = Keyboard(usb_hid.devices)

# turn on led
led = digitalio.DigitalInOut(board.LED)
led.direction = digitalio.Direction.OUTPUT
led.value = True

# start 
time.sleep(10)
while True: 
# set mouse commands here

# turn off led, you can unplug it
led.value = False