# pico-key by @dj1ch    
# licensed under GPL 3.0 
# shell.py: builds scripts, interface, etc

import time
import board
import digitalio
from boot import info

led = digitalio.DigitalInOut(board.LED)
led.direction = digitalio.Direction.OUTPUT

def main():
    print("\n1. Bad USB")
    print("2. Misc")
    print("3. Options")
    time.sleep(1)
    choice = input("\n> ")

    if choice == 1:
        file = input("Payload file name: ")
        try:
            with open(f"{file}", "a") as f:
                print(f"{file} accessed successfully!")
                # as of right now, we can only write three lines
                code = input("\n1 > ")
                time.sleep(1)
                f.write(f"{code}")
                codea = input("\n2 > ")
                time.sleep(1)
                f.write(f"{codea}")
                codeb = input("\n3 > ")
                time.sleep(1)
                f.write(f"{codeb}")

                print("\nSuccessfully built Bad USB script!")
                print(f + ": ")
                time.sleep(1)
                print(f.read())

        except OSError as e:
            if e.args[0] == 28:
                print("Filesystem full!")

    elif choice == 2:
        print("\n1. Turn on LED")
        print("2. Turn off LED")
        choiceb = input("\n> ")
        if choiceb == 1:
            led.value = True
        elif choiceb == 2:
            led.value = False
        else: 
            print(f"{choiceb}: Command not found")

    elif choice == 3:
        print("\n1. Board Info")
        choicec = input("\n>")
        if choicec == 1:
            info()
        else: 
            print(f"{choicec}: Command not found")