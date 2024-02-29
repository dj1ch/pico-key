# pico-key by @dj1ch    
# licensed under GPL 3.0 
# commands.py: commands and their usage

import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.mse import Mouse

# instances
mse = Mouse(usb_hid.devices)
kbd = Keyboard(usb_hid.devices)
layout = KeyboardLayout(kbd)

# us keyboard layout:
from adafruit_hid.keyboard_layout_us import KeyboardLayoutUS as KeyboardLayout
from adafruit_hid.keycode import Keycode

# other layouts:
# replace <language> with your keyboard layout
# from keyboard_layout_win_<language> import KeyboardLayout
# from keycode_win_<language> import Keycode

# all commands are defined here
commands = {
    'WINDOWS': Keycode.WINDOWS, 'GUI': Keycode.GUI,
    'APP': Keycode.APPLICATION, 'MENU': Keycode.APPLICATION, 'SHIFT': Keycode.SHIFT,
    'ALT': Keycode.ALT, 'CONTROL': Keycode.CONTROL, 'CTRL': Keycode.CONTROL,
    'DOWNARROW': Keycode.DOWN_ARROW, 'DOWN': Keycode.DOWN_ARROW, 'LEFTARROW': Keycode.LEFT_ARROW,
    'LEFT': Keycode.LEFT_ARROW, 'RIGHTARROW': Keycode.RIGHT_ARROW, 'RIGHT': Keycode.RIGHT_ARROW,
    'UPARROW': Keycode.UP_ARROW, 'UP': Keycode.UP_ARROW, 'BREAK': Keycode.PAUSE,
    'PAUSE': Keycode.PAUSE, 'CAPSLOCK': Keycode.CAPS_LOCK, 'DELETE': Keycode.DELETE,
    'END': Keycode.END, 'ESC': Keycode.ESCAPE, 'ESCAPE': Keycode.ESCAPE, 'HOME': Keycode.HOME,
    'INSERT': Keycode.INSERT, 'NUMLOCK': Keycode.KEYPAD_NUMLOCK, 'PAGEUP': Keycode.PAGE_UP,
    'PAGEDOWN': Keycode.PAGE_DOWN, 'PRINTSCREEN': Keycode.PRINT_SCREEN, 'ENTER': Keycode.ENTER,
    'SCROLLLOCK': Keycode.SCROLL_LOCK, 'SPACE': Keycode.SPACE, 'TAB': Keycode.TAB,
    'BACKSPACE': Keycode.BACKSPACE,
    'A': Keycode.A, 'B': Keycode.B, 'C': Keycode.C, 'D': Keycode.D, 'E': Keycode.E,
    'F': Keycode.F, 'G': Keycode.G, 'H': Keycode.H, 'I': Keycode.I, 'J': Keycode.J,
    'K': Keycode.K, 'L': Keycode.L, 'M': Keycode.M, 'N': Keycode.N, 'O': Keycode.O,
    'P': Keycode.P, 'Q': Keycode.Q, 'R': Keycode.R, 'S': Keycode.S, 'T': Keycode.T,
    'U': Keycode.U, 'V': Keycode.V, 'W': Keycode.W, 'X': Keycode.X, 'Y': Keycode.Y,
    'Z': Keycode.Z, 'F1': Keycode.F1, 'F2': Keycode.F2, 'F3': Keycode.F3,
    'F4': Keycode.F4, 'F5': Keycode.F5, 'F6': Keycode.F6, 'F7': Keycode.F7,
    'F8': Keycode.F8, 'F9': Keycode.F9, 'F10': Keycode.F10, 'F11': Keycode.F11,
    'F12': Keycode.F12, 'MOUSE': {'action': 'MOVE', 'x': 0, 'y': 0, 'z': 0},
    'CLICK': {'action': 'CLICK'}, 'RIGHT_CLICK': {'action': 'RIGHT_CLICK'},
    'MIDDLE_CLICK': {'action': 'MIDDLE_CLICK'},
}

# i "borrowed" this from old code...
# https://github.com/dj1ch/pico-ducky/blob/main/duckyinpython.py
def mouse(command):
    action = command['action']
    if action == 'MOVE':
        mseX = int(command.get('x', 0))
        mseY = int(command.get('y', 0))
        mse.move(x=mseX, y=mseY)
    elif action == 'CLICK':
        mse.click(mse.LEFT_BUTTON)
    elif action == 'RIGHT_CLICK':
        mse.click(mse.RIGHT_BUTTON)
    elif action == 'MIDDLE_CLICK':
        mse.click(mse.MIDDLE_BUTTON)

def run():
    if command.upper() in commands:
        cmd = commands[command.upper()]
        if isinstance(action, Keycode):
            kbd.press(action)
            kbd.release_all()
        elif isinstance(action, dict):
            mouse(cmd)

