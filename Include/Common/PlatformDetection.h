#pragma once

#include "Common/NameManglingGuard.h"

Common_NameManglingGuard_Begin

typedef enum Platform
{
    Platform_Unknown,
    Platform_Windows32,
    Platform_Windows64,
    Platform_Linux,
    Platform_Android,
} Platform;

#if defined(_WIN64)
    #define Common_Platform_Windows64
    #define Common_Platform_Windows
#elif defined(_WIN32)
    #define Common_Platform_Windows32
    #define Common_Platform_Windows
#elif defined(__ANDROID__)
    #define Common_Platform_Android
#elif defined(__linux__)
    #define Common_Platform_Linux
#else
    #define Common_Platform_Unknown
    #error "[ Platform ]: Unknown platform"
#endif

static inline Platform Common_GetPlatform(void)
{
    #if defined(Common_Platform_Windows64)
        return Platform_Windows64;
    #elif defined(Common_Platform_Windows32)
        return Platform_Windows32;
    #elif defined(Common_Platform_Android)
        return Platform_Android;
    #elif defined(Common_Platform_Linux)
        return Platform_Linux;
    #else
        return Platform_Unknown;
    #endif
}

Common_NameManglingGuard_End