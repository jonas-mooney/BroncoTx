#ifndef __REGISTERS_H
#define __REGISTERS_H

#include "main.h"

uint8_t nrf24_read_reg(uint8_t reg);

void nrf24_write_reg(uint8_t reg, uint8_t value);

void nrf24_write_addr_reg(uint8_t reg, const uint8_t *addr, uint8_t len);

void nrf24_write_payload(const uint8_t *data, uint8_t len);

#endif