#include "../main.h"
#include "CnetGame.h"

void CNetGame::KickPlayer(PLAYERID playerid)
{
    #if ISLINUX
        reinterpret_cast<void(*)(CNetGame* ,uint16_t)>(0x80AE8C0)(this, playerid);
    #elif defined(WIN32)
        reinterpret_cast<void(__thiscall*)(CNetGame* ,uint16_t)>(0x48E870)(this, playerid);
    #endif
}

void CNetGame::SendToPlayer(char* uniqueID, RakNet::BitStream* stream, unsigned short playerid, char orderingchannel)
{
    #if ISLINUX
        reinterpret_cast<void(*)(CNetGame*, char*, RakNet::BitStream*, uint16_t, char)>(0x80AC1D0)(this, uniqueID, stream, playerid, orderingchannel);
    #elif defined(WIN32)
        reinterpret_cast<void(__thiscall*)(CNetGame*, char*, RakNet::BitStream*, uint16_t, char)>(0x48E440)(this, uniqueID, stream, playerid, orderingchannel);
    #endif
}

RakServerInterfaceVTBL* CNetGame::GetRakServerVTable()
{
    return *reinterpret_cast<RakServerInterfaceVTBL**>(this->m_pRak);
}

void CNetGame::Packet_NewIncomingConnection(Packet* packet)
{
    #if ISLINUX

    #elif defined(WIN32)
        reinterpret_cast<void(__thiscall*)(CNetGame*, Packet*)>(0x48E780)(this, packet);
    #endif
}

void CNetGame::BroadCastData(char* uniqueID, RakNet::BitStream* stream, PLAYERID excludedPlayer, char orderingChannel)
{
    #if ISLINUX
        reinterpret_cast<void(*)(CNetGame*, char*, RakNet::BitStream*, PLAYERID, char)>(0x80ABAD0)(this, uniqueID, stream, excludedPlayer, orderingChannel);
    #elif defined(WIN32)
        reinterpret_cast<void(__thiscall*)(CNetGame*, char*, RakNet::BitStream*, PLAYERID, char)>(0x48E190)(this, uniqueID, stream, excludedPlayer, orderingChannel);
    #endif
}

void CNetGame::VehicleBroadcast(char* uniqueID, RakNet::BitStream* stream, uint16_t vehicleid, PLAYERID playerid, char orderingchannel)
{
    #if ISLINUX
        reinterpret_cast<void(*)(CNetGame*, char*, RakNet::BitStream*, uint16_t, PLAYERID)>(0x80AC080)(this, uniqueID, stream, vehicleid, playerid);
    #elif defined(WIN32)
        reinterpret_cast<void(__thiscall*)(CNetGame*, char*, RakNet::BitStream*, uint16_t, PLAYERID, char)>(0x48E350)(this,  uniqueID, stream, vehicleid, playerid, orderingchannel);

    #endif
}