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
                code_a = input("\n1 > ")
                time.sleep(1)
                f.write(f"{code_a}")
                code_b = input("\n2 > ")
                time.sleep(1)
                f.write(f"{code_b}")
                code_c = input("\n3 > ")
                time.sleep(1)
                f.write(f"{code_c}")
                
                # exits and returns to home screen in case if you type "exit"
                if code_a.upper() == "EXIT":
                    main()
                elif code_b.upper() == "EXIT":
                    main()
                elif code_c.upper() == "EXIT":
                    main()

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
        choice_b = input("\n> ")
        if choice_b == 1:
            led.value = True
        elif choice_b == 2:
            led.value = False
        else: 
            print(f"{choice_b}: Command not found")

    elif choice == 3:
        print("\n1. Board Info")
        choice_c = input("\n>")
        if choice_c == 1:
            info()
        else: 
            print(f"{choice_c}: Command not found")