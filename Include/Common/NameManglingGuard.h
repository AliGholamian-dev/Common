#pragma once

#ifdef __cplusplus
    #define Common_NameManglingGuard_Begin extern "C" {
    #define Common_NameManglingGuard_End }
#else
    #define Common_NameManglingGuard_Begin
    #define Common_NameManglingGuard_End
#endif
