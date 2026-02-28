#pragma once

#include "Common/NameManglingGuard.h"

Common_NameManglingGuard_Begin

#define Common_Define_Handle(HandleName) typedef struct HandleName##_T* HandleName

Common_NameManglingGuard_End
