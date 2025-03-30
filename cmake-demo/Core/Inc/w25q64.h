/*
 * w25q64.h
 *
 *  Created on: Mar 26, 2025
 *      Author: fwar3
 */

#ifndef INC_W25Q64_H_
#define INC_W25Q64_H_

#include "main.h"
#include "stm32f1xx_hal.h"
#include <inttypes.h>

#define W25Q64_START()                                                         \
    HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_RESET)
#define W25Q64_STOP()                                                          \
    HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_SET)

void W25q64Init();
int32_t W25q64ReadDeviceId(uint8_t *mid, uint16_t *did);

#endif /* INC_W25Q64_H_ */
