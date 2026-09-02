#include "joystick.h"

extern ADC_HandleTypeDef hadc1;

uint32_t Read_ADC_Channel(uint32_t channel) {
  ADC_ChannelConfTypeDef sConfig = {0};
  sConfig.Channel = channel;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_47CYCLES_5;
  HAL_ADC_ConfigChannel(&hadc1, &sConfig);

  HAL_ADC_Start(&hadc1);
  HAL_ADC_PollForConversion(&hadc1, 10);
  uint32_t value = HAL_ADC_GetValue(&hadc1);
  HAL_ADC_Stop(&hadc1);

  return value; // 12-bit result: 0–4095
}

void Joystick_Read(uint16_t *x, uint16_t *y) {
  *x = Read_ADC_Channel(ADC_CHANNEL_15); // PB0  = VRX
  *y = Read_ADC_Channel(ADC_CHANNEL_10); // PA5  = VRY
}