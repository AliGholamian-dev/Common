#pragma once

#include "Common/NameManglingGuard.h"

Common_NameManglingGuard_Begin

#define Stringify_(S)   #S
#define Stringify(S)    Stringify_(S)
#define Glue_(A,B)      A##B
#define Glue(A,B)       Glue_(A,B)

Common_NameManglingGuard_End
