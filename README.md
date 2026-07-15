GND - GND
CE - A2/PA_3
SCK - A1/PA_1
MISO - A5/PA_6

VCC - 3v3
CSN - A3/PA_4
MOSI - A6/PA_7

CONFIG = 0x0E
CONFIG = 0x00

## Verifying CONFIG register

rx[0] returns 0x00 (0000 0000) which is the status byte.
rx[1] returns 0x0E (0000 1110) which is the CONFIG register being read back.
