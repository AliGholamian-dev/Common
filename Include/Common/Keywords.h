#pragma once

#include "Common/NameManglingGuard.h"
#include <assert.h>

Common_NameManglingGuard_Begin

#define unused(x)           (void)(x)
#define dynamic_assert(x)   assert(x)

Common_NameManglingGuard_End
