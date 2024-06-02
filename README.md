# pico-key

A physical pentesting toolkit on a Raspberry Pi Pico

## Progress

Development will be very slow, and may take a long time. It's expected for the first releases to arrive by late August-July.

### Planned Features

- Keystroke injection

- Payload adjustment

- Hardware glitching

- USB spoofing

- MITM attacks through RNDIS

### Planned attacking process

1. Pico checks whether or not it should run a payload, by default it goes to the shell.

2. Through the shell the task is selected, you can customize this task, etc.

3. Task is executed upon startup.

4. Resets the board and allows configuration before the next run.
