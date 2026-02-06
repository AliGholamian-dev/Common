#pragma once

#include "Common/NameManglingGuard.h"

Common_NameManglingGuard_Begin

#define unused(x)      (void)(x)
#define internal       static
#define global         static
#define local_persist  static

Common_NameManglingGuard_End
