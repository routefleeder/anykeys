#pragma once

#include <windows.h>
#include <stdint.h>

namespace SetHooks {
    void* SetCallHook(uintptr_t HookAddress, void* DetourFunction);
}