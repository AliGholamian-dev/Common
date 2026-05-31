#pragma once

#include "Common/StringHelpers.h"
#include "Common/BasicDataTypes.h"
#include "Common/CompilerDetection.h"
#include "Common/NameManglingGuard.h"
#include <assert.h>

Common_NameManglingGuard_Begin

#define internal        static
#define global          static
#define local_persist   static

#if defined(Common_Compiler_MSVC)
    #define Trap() __debugbreak()
#elif defined(Common_Compiler_GCC) || defined(Common_Compiler_Clang)
    #define Trap() __builtin_trap()
#else
    #define Trap()
    #error "[ Trap ]: Unknown trap intrinsic for this compiler"
#endif

#define AssertAlways(x) do{if(!(x)) {Trap();}}while(0)

#ifdef NDEBUG
    #define Assert(x) (void)(x)
#else
    #define Assert(x) AssertAlways(x)
#endif

#define InvalidCodePath     Assert(!"Invalid Code Path!")
#define NotImplemented      Assert(!"Not Implemented!")
#define StaticAssert(C, ID) global UInt8 Glue(ID, __LINE__)[(C)?1:-1]
#define NoOp                ((void)0)
#define Unused(x)           (void)(x)

Common_NameManglingGuard_End
