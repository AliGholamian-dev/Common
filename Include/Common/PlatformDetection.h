#pragma once

#include "Common/NameManglingGuard.h"

Common_NameManglingGuard_Begin

#if defined(_WIN32) && defined(_WIN64)
    #define Common_Platform_Windows64
#elif defined(_WIN32)
    #define Common_Platform_Windows32
#elif defined(__linux__) && !defined(__ANDROID__)
    #define Common_Platform_Linux
#else
    #define Common_Platform_Unknown
    #error "[ Platform ]: Unknown platform"
#endif

Common_NameManglingGuard_End
