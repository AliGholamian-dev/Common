#pragma once

#include "Common/CompilerDetection.h"
#include "Common/NameManglingGuard.h"

Common_NameManglingGuard_Begin

#define Common_System_NotDetectedEndian 0000
#define Common_System_LittleEndian      1234
#define Common_System_BigEndian         4321

#if defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
    #define Common_System_ByteOrder Common_System_LittleEndian
#elif defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
    #define Common_System_ByteOrder Common_System_BigEndian
#else
    #define Common_System_ByteOrder Common_System_NotDetectedEndian
    #error "[ Endianness ]: Endianness could not be detected at compile time"
#endif

Common_NameManglingGuard_End