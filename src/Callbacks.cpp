// #include "sampgdk.h"
#include "Callbacks.h"
#include "CnetGame.h"
// #include "basics/CGameMode.h"
#include "PluginPointers.h"

int PluginCallbacks::OnPlayerPressKey(int lastKey, int key, int playerid)
{
    CNetGame* netgame_ptr = PluginPointers::GetCNetGamePointer();
    if(!netgame_ptr->m_pGameMode->m_bInitialised) return 0;

    int amx_id = 0;
    cell retval = 0; // Amx-Callback return value

    if(!amx_FindPublic(&netgame_ptr->m_pGameMode->m_amx, "OnPlayerPressKey", &amx_id))
    {
        amx_Push(&netgame_ptr->m_pGameMode->m_amx, lastKey);
        amx_Push(&netgame_ptr->m_pGameMode->m_amx, key);
        amx_Push(&netgame_ptr->m_pGameMode->m_amx, playerid);
        amx_Exec(&netgame_ptr->m_pGameMode->m_amx, &retval, amx_id);
    }

    for(int v = 0; v < 16; ++v)
    {
        AMX* amx = netgame_ptr->m_pFilterScripts->m_pFilterScripts[v];
        if(amx != nullptr)
        {
            if(!amx_FindPublic(amx, "OnPlayerPressKey", &amx_id))
            {
                amx_Push(amx, lastKey);
                amx_Push(amx, key);
                amx_Push(amx, playerid);
                amx_Exec(amx, &retval, amx_id);
            }
        }
    }

    return retval;
}