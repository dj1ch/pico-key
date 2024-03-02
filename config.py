# pico-key by @dj1ch    
# licensed under GPL 3.0 
# config.py: universal configuration for pico

# determines if the script should be run on startup
run_on_startup = False

# note you can have multiple payloads, this is the default
payload = "payload.dd" 

def check_start():
    return run_on_startup

def check_payload():
    return payload