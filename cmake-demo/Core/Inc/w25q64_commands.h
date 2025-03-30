#ifndef __W25Q64_COMMANDS_H_
#define __W25Q64_COMMANDS_H_

#define W25Q64_WRITE_ENABLE 0x06           // 写使能
#define W25Q64_WRITE_DISABLE 0x04          // 写禁止
#define W25Q64_READ_STATUS_REG1 0x05       // 读取状态寄存器 1
#define W25Q64_READ_STATUS_REG2 0x35       // 读取状态寄存器 2
#define W25Q64_WRITE_STATUS_REG 0x01       // 写状态寄存器
#define W25Q64_PAGE_PROGRAM 0x02           // 页编程
#define W25Q64_QUAD_PAGE_PROGRAM 0x32      // 四线页编程
#define W25Q64_BLOCK_ERASE_64K 0xD8        // 64KB 块擦除
#define W25Q64_BLOCK_ERASE_32K 0x52        // 32KB 块擦除
#define W25Q64_SECTOR_ERASE 0x20           // 4KB 扇区擦除
#define W25Q64_CHIP_ERASE 0xC7             // 芯片擦除
#define W25Q64_ERASE_SUSPEND 0x75          // 擦除暂停
#define W25Q64_ERASE_RESUME 0x7A           // 擦除恢复
#define W25Q64_POWER_DOWN 0xB9             // 掉电模式
#define W25Q64_HIGH_PERF_MODE 0xA3         // 高性能模式
#define W25Q64_CONTINUOUS_READ_MODE 0xFF   // 连续读取模式
#define W25Q64_RELEASE_POWER_DOWN 0xAB     // 释放掉电模式
#define W25Q64_MANUFACTURER_ID 0x90        // 读取制造商 ID
#define W25Q64_DEVICE_ID 0x9F              // 读取设备 ID
#define W25Q64_UNIQUE_ID 0x4B              // 读取唯一 ID
#define W25Q64_READ_DATA 0x03              // 标准读取数据
#define W25Q64_FAST_READ 0x0B              // 快速读取数据
#define W25Q64_DUAL_OUT_FAST_READ 0x3B     // 双线输出快速读取
#define W25Q64_DUAL_INOUT_FAST_READ , 0xBB // 双线输入输出快速读取
#define W25Q64_QUAD_OUT_FAST_READ 0x6B     // 四线输出快速读取
#define W25Q64_QUAD_INOUT_FAST_READ 0xEB   // 四线输入输出快速读取

#define W25Q64_DUMMY_BYTE , 0xFF // 接收一个字节的时候交换的字节

#endif // !__W25Q64_COMMANDS_H_