#include "registers.h"

extern SPI_HandleTypeDef hspi1;

#define NRF24_CMD_R_REGISTER 0x00

uint8_t nrf24_read_reg(uint8_t reg) {
  uint8_t tx[2] = {NRF24_CMD_R_REGISTER | reg, 0xFF};
  uint8_t rx[2] = {0};

  HAL_GPIO_WritePin(CSN_Port, CSN_Pin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(&hspi1, tx, rx, 2, HAL_MAX_DELAY);
  HAL_GPIO_WritePin(CSN_Port, CSN_Pin, GPIO_PIN_SET);

  return rx[1];
}