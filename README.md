GND - GND
CE - A2/PA_3
SCK - A1/PA_1
MISO - A5/PA_6

VCC - 3v3
CSN - A3/PA_4
MOSI - A6/PA_7

VRX - PB_0 - D3 - ADC_CHANNEL_15
VRY - PA_5 - A4 - ADC_CHANNEL_10
SW - PB_6 - D5

CONFIG = 0x0E
CONFIG = 0x00

## Verifying CONFIG register

rx[0] returns 0x0E (0000 1110) which is the status byte.
rx[1] returns 0x08 (0000 1000) which is the CONFIG register being read back.

functional example sending one packet every 1 second
