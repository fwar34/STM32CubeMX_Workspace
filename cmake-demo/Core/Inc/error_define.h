/*
 * protocol_error.h
 *
 *  Created on: Mar 22, 2025
 *      Author: fwar3
 */
#ifndef __ERROR_DEFINE_H_
#define __ERROR_DEFINE_H_

typedef enum {
    RETURN_VALUE_OK,
    RETURN_VALUE_ERROR,
} ReturnValue;

typedef enum {
    PROTOCOL_ERROR_OK = 0,
    PROTOCOL_ERROR_INVALID_PARAM,
} ProtocolError;

#endif // !__ERROR_DEFINE_H_
