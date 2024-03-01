# pico-key by @dj1ch    
# licensed under GPL 3.0 
# boot.py: bootup

import time
import microcontroller
import board
import gc

coolArt = """
███████████████████████████████████████████████
█▄─▄▄─█▄─▄█─▄▄▄─█─▄▄─█▀▀▀▀▀██▄─█─▄█▄─▄▄─█▄─█─▄█
██─▄▄▄██─██─███▀█─██─█████████─▄▀███─▄█▀██▄─▄██
▀▄▄▄▀▀▀▄▄▄▀▄▄▄▄▄▀▄▄▄▄▀▀▀▀▀▀▀▀▄▄▀▄▄▀▄▄▄▄▄▀▀▄▄▄▀▀
"""

author = """
█████████████████████████████████████████
█▄─▄─▀█▄─█─▄███▄─▄▄▀███▄─▄█▀░██─▄▄▄─█─█─█
██─▄─▀██▄─▄█████─██─█─▄█─███░██─███▀█─▄─█
▀▄▄▄▄▀▀▀▄▄▄▀▀▀▀▄▄▄▄▀▀▄▄▄▀▀▀▄▄▄▀▄▄▄▄▄▀▄▀▄▀
"""

def bootup():
    startup()
    load(5)
    info()

def load(loops):
    dots = [" ",".", "..", "..."]
    for _ in range(loops):
        for dot in dots:
            print("\rStarting" + dot, end="" )
            time.sleep(0.5)
            print("\r" + " " * len("Starting" + dot), end="")
     
# as of right now it only prints temp and memory available
def info():
    print("\nBoard info: ")
    temp = microcontroller.cpu.temperature
    print(temp + " Celsius")
    mem = gc.mem_free()
    print(mem)

def startup(): 
    print(coolArt)
    time.sleep(1)
    print(author)

# run 
if __name__ == "__bootup__":
    bootup()
