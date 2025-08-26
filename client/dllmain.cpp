#include <windows.h>
#include <map>
// #include <thread>
// #include "common.h"
#include "raknet/RakClientInterface.h"
#include "sampapi/CNetGame.h"
// #include "sampapi/CChat.h"
// #include "sampapi/CInput.h"
#include "sampapi/CGame.h"

// #define GAME_STAGE 0xC8D4C0

// static plugin::CdeclEvent<plugin::AddressList<0x53BF0B, plugin::H_CALL>, plugin::PRIORITY_AFTER, plugin::ArgPickNone, void()> CTimerProcessEvent;

// void AddMessageJumpQ(const char* text, unsigned int time, unsigned short flag, bool bPreviousBrief)
// {
//     ((void(__cdecl*)(const char*, unsigned int, unsigned short, bool))0x69F1E0)(text, time, flag, bPreviousBrief);
// }

static char rpcId = 241;

std::map<int, bool> keyStates;
static u_long lastKey = 0;

void SendKeyRPC(int currentkey, int lastkey)
{
    int playerid = sampapi::v037r3::RefNetGame()->GetPlayerPool()->m_localInfo.m_nId;
    RakNet::BitStream bs;
    bs.Write(playerid);
    bs.Write(currentkey);
    bs.Write(lastkey);
    sampapi::v037r3::RefNetGame()->m_pRakClient->RPC(&rpcId, &bs, PacketPriority::HIGH_PRIORITY, PacketReliability::VERY_RELABLE, 0, false);
}

HHOOK g_hHook = NULL;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if(GetForegroundWindow() == FindWindowA(0, "GTA:SA:MP"))
    {
        sampapi::v037r3::CNetGame* cnet_ptr = sampapi::v037r3::RefNetGame();
        if ((nCode == HC_ACTION) && (cnet_ptr != nullptr) && (!sampapi::v037r3::RefGame()->m_nCursorMode || (sampapi::v037r3::RefGame()->m_nCursorMode == 1 || sampapi::v037r3::RefGame()->m_nCursorMode == 4)) && !sampapi::v037r3::RefGame()->IsMenuVisible())
        {
            PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;

            u_long currentKey = p->vkCode;
            if (wParam == WM_KEYDOWN)
            {
                if(!keyStates[currentKey])
                {
                    keyStates[currentKey] = true;
                    if (lastKey != 0 && lastKey != currentKey)
                    {
                        SendKeyRPC(currentKey, lastKey);
                        
                        lastKey = 0;
                    }
                    else if(lastKey == 0)
                    {
                        lastKey = currentKey;
                    }
                }
            }
            if (wParam == WM_KEYUP)
            {
                if((currentKey == VK_LMENU || currentKey == VK_RMENU) && lastKey == 0)
                {
                    SendKeyRPC(currentKey, 0);
                    lastKey = 0;
                }
                else if(currentKey == lastKey)
                {
                    SendKeyRPC(currentKey, 0);
                    lastKey = 0;
                }
                keyStates[currentKey] = false;
            }
        }
    }
    return CallNextHookEx(g_hHook, nCode, wParam, lParam);
}

void KeyThread()
{
    // while (*reinterpret_cast<unsigned char*>(GAME_STAGE) != 9) { // while (стадия игры != полностью проинициализирована)
    //     Sleep(100);
    // }
    // HWND* gtaHwnd = reinterpret_cast<HWND*>(0xC17040);
    g_hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, GetModuleHandle(NULL), 0);
    // while (true)
    // {
    //     if (GetAsyncKeyState(VK_F5) & 1)
    //     {
    //         if (GetForegroundWindow() == FindWindowA(0, "GTA:SA:MP"))
    //         {
    //             AddMessageJumpQ("~g~F5 pressed!", 1000, 0, false);

    //             char id = 241;
    //             RakNet::BitStream bs;
    //             bs.Write(VK_F5);

    //             sampapi::v037r3::RefNetGame()->m_pRakClient->RPC(&id, &bs, PacketPriority::HIGH_PRIORITY, PacketReliability::VERY_RELABLE, 0, false);
    //             sampapi::v037r3::RefChat()->AddMessage(0xFFFFFFFF, "Test RPC");
    //         }
    //     }
    // }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hModule);
        KeyThread();
    }

    return TRUE;
}