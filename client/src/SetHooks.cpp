#include "SetHooks.h"

namespace SetHooks {

void* SetCallHook(uintptr_t HookAddress, void* DetourFunction) {
    uintptr_t OriginalFunction = *reinterpret_cast<uintptr_t*>(HookAddress + 1) + HookAddress + 5;
    DWORD oldProt;
    VirtualProtect(reinterpret_cast<void*>(HookAddress + 1), sizeof(uintptr_t), PAGE_READWRITE, &oldProt);
    *reinterpret_cast<uintptr_t*>(HookAddress + 1) = reinterpret_cast<uintptr_t>(DetourFunction) - HookAddress - 5;
    VirtualProtect(reinterpret_cast<void*>(HookAddress + 1), sizeof(uintptr_t), oldProt, &oldProt);
    return reinterpret_cast<void*>(OriginalFunction);
}

}