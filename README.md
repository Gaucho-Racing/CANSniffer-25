# CAN Sniffer-25
Reads all messages sent over CAN and outputs their data over serial to be displayed on a screen.

## Usage
1. Flash the board (use PlatformIO in VS Code) or use the already-flashed board and plug it in via USB
2. Connect the pins correctly (CAN-H <--> CAN-H, etc)
3. Run `cat /dev/ttyACM0` to see the output (you may need to change the port)

## Platform IO and Teensy
This is a project extended from GR24 and uses that board to provide CAN Sniffing capabilities. This is **_NOT_** an STM32-based project.

Accordingly, see `src/main.cpp` for almost all functionality. Exact CAN-IDs are almost certainly out of date, try to keep this as general as possible accordingly.
