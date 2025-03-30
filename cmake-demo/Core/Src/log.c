#include "log.h"
#include "usart.h"
#include <stdarg.h>
#include <stdio.h>

void Log(uint8_t level, const char *fmt, ...)
{
    static char logBuffer[256];
    const char *logStr = "";
    switch (level) {
    case LOG_DEBUG:
        logStr = "[DEBUG] ";
        break;
    case LOG_INFO:
        logStr = "[INFO] ";
        break;
    case LOG_WARNING:
        logStr = "[WARNING] ";
        break;
    case LOG_ERROR:
        logStr = "[ERROR] ";
        break;
    default:
        break;
    }

    va_list args;
    va_start(args, fmt);
    int32_t prefixLen = snprintf(logBuffer, sizeof(logBuffer), "%s", logStr);
    int32_t msgLen = vsnprintf(logBuffer + prefixLen,
                               sizeof(logBuffer) - prefixLen, fmt, args);
    va_end(args);

    if (prefixLen + msgLen > 0) {
        UartPrint(logBuffer, prefixLen + msgLen);
    }
}