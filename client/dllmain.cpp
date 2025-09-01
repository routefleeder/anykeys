#include <windows.h>
#include <thread>
#include "raknet/RakClientInterface.h"
#include "sampapi/CNetGame.h"
#include "sampapi/CGame.h"

#include "plugin.h"
#include <map>

#define GAME_STAGE 0xC8D4C0

// using CTimer__Update = void(__fastcall*)(void*);
// CTimer__Update pOriginalFunction = nullptr;

// using CGame__Process = void(__fastcall*)(void*);
// CGame__Process ofGameProcess = nullptr;

// static plugin::CdeclEvent<plugin::AddressList<0x53BF0B, plugin::H_CALL>, plugin::PRIORITY_AFTER, plugin::ArgPickNone, void()> CTimerProcessEvent;

std::map<int, bool> keyStates;

static char rpcId = 241;

void SendKeyRPC(int currentkey, int lastkey)
{
    int playerid = sampapi::v037r3::RefNetGame()->GetPlayerPool()->m_localInfo.m_nId;
    RakNet::BitStream bs;
    bs.Write(playerid);
    bs.Write(currentkey);
    bs.Write(lastkey);
    sampapi::v037r3::RefNetGame()->m_pRakClient->RPC(&rpcId, &bs, PacketPriority::HIGH_PRIORITY, PacketReliability::VERY_RELABLE, 0, false);
}

void SafetyKeyHook()
{
    if((GetForegroundWindow() == FindWindowA(0, "GTA:SA:MP") || GetForegroundWindow() == FindWindowA(0, "GTA:S&SMP")) && sampapi::v037r3::RefNetGame() != nullptr && (!sampapi::v037r3::RefGame()->m_nCursorMode || (sampapi::v037r3::RefGame()->m_nCursorMode == 1 || sampapi::v037r3::RefGame()->m_nCursorMode == 4)) && !sampapi::v037r3::RefGame()->IsMenuVisible())
    {
        bool isShiftPressed = plugin::KeyPressed(VK_SHIFT);
        bool isCtrlPressed = plugin::KeyPressed(VK_CONTROL);
        bool isAltPressed = plugin::KeyPressed(VK_MENU);

        for(int i = 1; i < 256; ++i)
        {
            if(i == VK_SHIFT || i == VK_CONTROL || i == VK_MENU || i == VK_LSHIFT || i == VK_LCONTROL || i == VK_LMENU || i == VK_RSHIFT || i == VK_RCONTROL || i == VK_RMENU) continue;

            if(plugin::KeyPressed(i) && !keyStates[i])
            {
                if(isShiftPressed)
                {
                    keyStates[i] = true;
                    SendKeyRPC(i, VK_SHIFT);
                    break;
                }
                else if(isCtrlPressed)
                {
                    keyStates[i] = true;
                    SendKeyRPC(i, VK_CONTROL);
                    break;
                }
                else if(isAltPressed)
                {
                    keyStates[i] = true;
                    SendKeyRPC(i, VK_MENU);
                    break;
                }
                else
                {
                    keyStates[i] = true;
                    SendKeyRPC(i, 0);
                    break;
                }
            }
            else if(!plugin::KeyPressed(i) && keyStates[i])
            {
                keyStates[i] = false;
                break;
            }
        }
    }
}

void InitAndLoad()
{
    while(*reinterpret_cast<unsigned char*>(GAME_STAGE) != 9)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100u));
    }
    plugin::Events::gameProcessEvent.after += SafetyKeyHook;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hModule);
        std::thread(InitAndLoad).detach();
    }

    return TRUE;
}