#include "w25q64.h"
#include "error_define.h"
#include "log.h"
#include "spi.h"
#include "usart.h"
#include "w25q64_commands.h"

void W25q64Init() {}

int32_t W25q64ReadDeviceId(uint8_t *mid, uint16_t *did)
{
    uint8_t tmp[2] = {0};
    int32_t ret = HAL_OK;
    uint8_t dummyByte = W25Q64_DUMMY_BYTE;
    W25Q64_START();
    do {
        ret = HAL_SPI_Transmit(&hspi1, W25Q64_DEVICE_ID, 1, HAL_MAX_DELAY);
        if (ret != HAL_OK) {
            LogError("send W25Q64_DEVICE_ID failed! error: %d\n", ret);
            break;
        }
        ret = HAL_SPI_TransmitReceive(&hspi1, &dummyByte, mid, sizeof(mid),
                                      HAL_MAX_DELAY);
        if (ret != HAL_OK) {
            LogError("receive mid failed! error: %d\n", ret);
            break;
        }
        ret = HAL_SPI_TransmitReceive(&hspi1, &dummyByte, &tmp[1],
                                      sizeof(uint8_t), HAL_MAX_DELAY);
        if (ret != HAL_OK) {
            LogError("receive did high byte failed! error: %d\n", ret);
            break;
        }
        ret = HAL_SPI_TransmitReceive(&hspi1, &dummyByte, &tmp[0],
                                      sizeof(uint8_t), HAL_MAX_DELAY);
        if (ret != HAL_OK) {
            LogError("receive did low byte failed! error: %d\n", ret);
            break;
        }
    } while (0);
    W25Q64_STOP();

    if (ret == HAL_OK) {
        *did = *(uint16_t *)tmp;
        ret = RETURN_VALUE_OK;
    } else {
        ret = RETURN_VALUE_ERROR;
    }

    return ret;
}