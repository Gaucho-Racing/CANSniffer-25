# CAN Sniffer-25
Reads all messages sent over CAN and outputs their data over serial to be displayed on a screen.

## Usage
1. Flash the board (use PlatformIO) or use the already-flashed board and plug it in via USB
2. Connect the pins correctly (CAN-H <--> CAN-H, etc)
3. Run `cat /dev/ttyACM0` to see the output (you may need to change the port)
