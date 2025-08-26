#include "basics/CGameMode.h"

int CGameMode::OnPlayerKeyStateChange(cell playerid, cell newkeys, cell oldkeys)
{
    #if ISLINUS
        return reinterpret_cast<int(*)(CGameMode*, cell, cell, cell)>(0x80A5C80)(this, playerid, newkeys, oldkeys);
    #elif defined(WIN32)
        return reinterpret_cast<int(__thiscall*)(CGameMode*, cell, cell, cell)>(0x46E250)(this, playerid, newkeys, oldkeys);
    #endif
}

int CGameMode::OnVehicleMod(cell playerid, cell vehicleid, cell componentid)
{
    #if ISLINUX
        return reinterpret_cast<int(*)(CGameMode*, cell, cell, cell)>(0x80A60B0)(this, playerid, vehicleid, componentid);
    #elif defined(WIN32)
        return reinterpret_cast<int(__thiscall*)(CGameMode*, cell, cell, cell)>(0x46E5D0)(this, playerid, vehicleid, componentid);
    #endif
}