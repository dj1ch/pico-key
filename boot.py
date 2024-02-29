# pico-key by @dj1ch    
# licensed under GPL 3.0 
# boot.py: bootup

import time

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
     

def info():
    print("\nBoard info: ")
    # print board info

def startup(): 
    print(coolArt)
    time.sleep(1)
    print(author)

# run 
bootup()
