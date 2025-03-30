#include "log.h"
#include "usart.h"
#include <stdio.h>

void Log(uint8_t level, const char *fmt, ...)
{
    switch (level)
    {
    case LOG_DEBUG:
        UartPrintf("[DEBUG] ");
        break;
    case LOG_INFO:
        UartPrintf("[INFO] ");
        break;
    case LOG_WARNING:
        UartPrintf("[WARNING] ");
        break;
    case LOG_ERROR:
        UartPrintf("[ERROR] ");
        break;
    default:
        break;
    }

    va_list args;
    va_start(args, fmt);
    UartPrintf(fmt, args);
    va_end(args);
}