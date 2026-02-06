#pragma once

#include "Common/NameManglingGuard.h"

Common_NameManglingGuard_Begin

#if defined(__GNUC__) && !defined(__clang__) && !defined(__INTEL_COMPILER)
    #define Common_Compiler_GCC
#elif defined(__clang__)
    #define Common_Compiler_CLang
#else
    #define Common_Compiler_Unknown
    #error "[ Compiler ]: Unknown compiler"
#endif

Common_NameManglingGuard_End
