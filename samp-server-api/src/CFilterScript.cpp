#include "basics/CFilterscripts.h"

int CFilterScripts::OnPlayerKeyStateChange(cell playerid, cell newkeys, cell oldkeys)
{
    #if ISLINUX
        return reinterpret_cast<int(*)(CFilterScripts*, cell, cell, cell)>(0x80A5C80)(this, playerid, newkeys, oldkeys);
    #elif defined(WIN32)
        return reinterpret_cast<int(__thiscall*)(CFilterScripts*, cell, cell, cell)>(0x46B660)(this, playerid, newkeys, oldkeys);
    #endif
}

int CFilterScripts::OnVehicleMod(cell playerid, cell vehicleid, cell componentid)
{
    #if ISLINUX
        return reinterpret_cast<int(*)(CFilterScripts*, cell, cell, cell)>(0x80A28B0)(this, playerid, vehicleid, componentid);
    #elif defined(WIN32)
        return reinterpret_cast<int(__thiscall*)(CFilterScripts*, cell, cell, cell)>(0x46BA30)(this, playerid, vehicleid, componentid);
    #endif
}