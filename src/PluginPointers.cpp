#include "PluginPointers.h"
#include "InitStuff.h"
#include <thread>

CNetGame* PluginPointers::GetCNetGamePointer()
{
    #if defined(__linux__)
        return *reinterpret_cast<CNetGame**>(0x81CA4BC);
    #else
        return *reinterpret_cast<CNetGame**>(0x4F5FB8);
    #endif
}

void PluginInitialize::InitializeCNetGame()
{
    while (PluginPointers::GetCNetGamePointer() == nullptr)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100u));
    }

    PluginInitialize::RegisterRPCHooks();
}