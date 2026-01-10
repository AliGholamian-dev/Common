#pragma once

#include "Common/CompilerDetection.h"
#include "Common/NameManglingGuard.h"

Common_NameManglingGuard_Begin

#if defined(Common_Compiler_GCC) || defined(Common_Compiler_CLang)
    #define Packed_Struct_Start
    #define Packed_Struct_End
    #define Packed_Struct_Attribute __attribute__((packed))
#else
    #define Packed_Struct_Start
    #define Packed_Struct_End
    #define Packed_Struct_Attribute
    #error "[ Packing ]: Packing not supported or unknown compiler"
#endif

Common_NameManglingGuard_End
