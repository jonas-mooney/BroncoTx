#include "registers.h"

extern SPI_HandleTypeDef hspi1;

#define NRF24_CMD_R_REGISTER 0x00
#define NRF24_CMD_W_REGISTER 0x20
#define NRF24_CMD_W_TX_PAYLOAD 0xA0

#define CSN_Port GPIOA
#define CSN_Pin GPIO_PIN_4

uint8_t nrf24_read_reg(uint8_t reg) {
  uint8_t tx[2] = {NRF24_CMD_R_REGISTER | reg, 0xFF};
  uint8_t rx[2] = {0};

  HAL_GPIO_WritePin(CSN_Port, CSN_Pin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(&hspi1, tx, rx, 2, HAL_MAX_DELAY);
  HAL_GPIO_WritePin(CSN_Port, CSN_Pin, GPIO_PIN_SET);

  return rx[1];
}

void nrf24_write_reg(uint8_t reg, uint8_t value) {
  uint8_t tx[2] = {NRF24_CMD_W_REGISTER | reg, value};
  uint8_t rx[2];

  HAL_GPIO_WritePin(CSN_Port, CSN_Pin, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(&hspi1, tx, rx, 2, HAL_MAX_DELAY);
  HAL_GPIO_WritePin(CSN_Port, CSN_Pin, GPIO_PIN_SET);
}

void nrf24_write_addr_reg(uint8_t reg, const uint8_t *addr, uint8_t len) {
  uint8_t cmd = NRF24_CMD_W_REGISTER | reg;

  HAL_GPIO_WritePin(CSN_Port, CSN_Pin, GPIO_PIN_RESET);
  HAL_SPI_Transmit(&hspi1, &cmd, 1, HAL_MAX_DELAY);
  HAL_SPI_Transmit(&hspi1, (uint8_t *)addr, len, HAL_MAX_DELAY);
  HAL_GPIO_WritePin(CSN_Port, CSN_Pin, GPIO_PIN_SET);
}

void nrf24_write_payload(const uint8_t *data, uint8_t len) {
  uint8_t cmd = NRF24_CMD_W_TX_PAYLOAD;

  HAL_GPIO_WritePin(CSN_Port, CSN_Pin, GPIO_PIN_RESET);
  HAL_SPI_Transmit(&hspi1, &cmd, 1, HAL_MAX_DELAY);
  HAL_SPI_Transmit(&hspi1, (uint8_t *)data, len, HAL_MAX_DELAY);
  HAL_GPIO_WritePin(CSN_Port, CSN_Pin, GPIO_PIN_SET);
}