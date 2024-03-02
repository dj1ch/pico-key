# pico-key by @dj1ch    
# licensed under GPL 3.0 
# shell.py: builds scripts, interface, etc

import time
import board
import digitalio
from boot import info
import commands

# led
led = digitalio.DigitalInOut(board.LED)
led.direction = digitalio.Direction.OUTPUT

def main():
    while True:
        print("\n1. Build Bad USB script")
        print("2. Test Bad USB script")
        print("3. Fake USB drive")
        print("4. Misc")
        print("5. Options")
        time.sleep(1)
        choice = int(input("\n> "))

        if choice == 1:
            print("\nPayloads are built here, but can also be modified using a file manager.")
            print("Type 'exit' to exit to the main menu.")
            file = input("\nPayload file name? > ")
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
                    print(file + ": ")
                    time.sleep(1)
                    print(f.read())

            except OSError as e:
                if e.args[0] == 28:
                    print("Filesystem full!")
            except FileNotFoundError:
                print("File not found.")
            except Exception as ex:
                print(f"An error occurred: {ex}")

        elif choice == 2:
            print("\nRemember that testing the script will run this on your machine!")
            user_warning = input("Are you okay with this? (Y/N) > ")
            if user_warning.upper() == "Y":
                continue
            elif user_warning.upper() == "N":
                break
            else: 
                print(f"{user_warning}: Not a response")
    
            file_path = input("Script to test? > ")
            if file_path.upper() == "EXIT":
                break
            else: 
                commands.read_line(file_path)
        
        elif choice == 3:
            print("\nEssentially, all this does is blink the Pico to make it seem like a USB drive in case you were in public. Usually it blinks if you're writing data or viewing files.")
            print("\n1. Start LED blinking")
            print("2. Stop LED blinking")

        elif choice == 4:
            print("\nMostly random things are put here, if there are features that are pretty much useless I put them here.")
            print("\n1. Turn on LED")
            print("2. Turn off LED")
            choice_b = input("\n> ")
            if choice_b == "1":
                led.value = True
            elif choice_b == "2":
                led.value = False
            elif choice_b.upper() == "EXIT":
                break
            else: 
                print(f"{choice_b}: Command not found")

        elif choice == 5:
            print("\nHere we would put settings to set for the board, see the current board information, etc.")
            print("\n1. Board Info")
            choice_c = input("\n> ")
            if choice_c == "1":
                info()
            elif choice_c.upper() == "EXIT":
                break
            else: 
                print(f"{choice_c}: Command not found")

def file_path():
    return file_path