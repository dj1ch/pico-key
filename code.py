# pico-key by @dj1ch    
# licensed under GPL 3.0 
# code.py: main functions

import os
import shell
import commands
import config

payload_file = config.check_payload()

def main():
    # check for the file
    if payload_file in os.listdir():
        if config.check_start() == False:
            shell.main()
        else:
            # if there's nothing, don't run it
            if os.path.getsize(payload_file) == 0:
                print(f"\n{payload_file} is empty. Exiting into shell!")
                shell.main() 
            else:
                commands.read_line(payload_file)

main()
