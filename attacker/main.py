# this is all i have so far, development will be focused on the pico's coding

import os

machine = 192.168.x.x

print(f"SSH'ing into {machine}")
os.system(f"ssh {machine}")

