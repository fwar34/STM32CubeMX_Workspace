#include "w25q64.h"
#include "error_define.h"
#include "log.h"
#include "spi.h"
#include "usart.h"
#include "w25q64_commands.h"

void W25q64Init() {}

int32_t W25q64ReadDeviceId(uint8_t *mid, uint16_t *did)
{
    uint8_t response[3] = {0};
    int32_t ret = HAL_OK;

    W25Q64_START();
    do {
        // 发送命令
        ret = HAL_SPI_Transmit(&hspi1, &W25Q64_DEVICE_ID, 1, HAL_MAX_DELAY);
        if (ret != HAL_OK) {
            LogError("Send command failed: %d", ret);
            break;
        }

        // 接收3字节响应（Manufacturer ID + Device ID高字节 + Device ID低字节）
        ret = HAL_SPI_TransmitReceive(&hspi1, &W25Q64_DUMMY_BYTE, response, 3,
                                      HAL_MAX_DELAY);
        if (ret != HAL_OK) {
            LogError("Receive data failed: %d", ret);
            break;
        }
    } while (0);
    W25Q64_STOP();

    if (ret == HAL_OK) {
        *mid = response[0];
        *did = (response[1] << 8) | response[2]; // 合并高、低字节
        return RETURN_VALUE_OK;
    } else {
        return RETURN_VALUE_ERROR;
    }
}