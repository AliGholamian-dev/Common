#pragma once

#include "Common/NameManglingGuard.h"

Common_NameManglingGuard_Begin

typedef enum Compiler
{
    Compiler_Unknown,
    Compiler_Intel,
    Compiler_Clang,
    Compiler_GCC,
    Compiler_MSVC,
} Compiler;

#if defined(__INTEL_COMPILER) || defined(__INTEL_LLVM_COMPILER)
    #define Common_Compiler_Intel
#elif defined(__clang__)
    #define Common_Compiler_Clang
#elif defined(__GNUC__)
    #define Common_Compiler_GCC
#elif defined(_MSC_VER)
    #define Common_Compiler_MSVC
#else
    #define Common_Compiler_Unknown
    #error "[ Compiler ]: Unknown compiler"
#endif

static inline Compiler Common_GetCompiler(void)
{
    #if defined(Common_Compiler_Intel)
        return Compiler_Intel;
    #elif defined(Common_Compiler_Clang)
        return Compiler_Clang;
    #elif defined(Common_Compiler_GCC)
        return Compiler_GCC;
    #elif defined(Common_Compiler_MSVC)
        return Compiler_MSVC;
    #else
        return Compiler_Unknown;
    #endif
}

Common_NameManglingGuard_End
