#include "RakServerInterface.h"
#include "BitStream.h"
#include "PacketPriority.h"
#include "../main.h"

//__attribute__((aligned(4)))

#if defined(__linux__)
#pragma pack(push, 1)
struct RakServerInterfaceVTBL
{
  int vftable_0;
  int Start;
  int vftable_8;
  int vftable_C;
  int SetPassword;
  int vftable_14;
  int Disconnect;
  int vftable_1C;
  int vftable_20;
  int vftable_24;
  int Receive;
  int vftable_2C;
  int DeallocatePacket;
  #if defined(__linux__)
    void (*SetAllowedPlayers)(RakServerInterface* server, uint16_t AllowedPlayer);
  #else
    void (__thiscall *SetAllowedPlayers)(RakServerInterface* server, uint16_t AllowedPlayer);
  #endif
  int GetAllowedPlayers;
  int GetConnectedPlayers;
  int vftable_40;
  int vftable_44;
  int vftable_48;
  int GetLastPing;
  int vftable_50;
  int StartOccasionalPing;
  int vftable_58;
  int vftable_5C;
  int vftable_60;
  int vftable_64;
  int vftable_68;
  int vftable_6C;
  int vftable_70;
  int vftable_74;
  #if defined(__linux__)
    void (*RegisterAsRemoteProcedureCall)(RakServerInterface *server, char *, void(*)(RPCParameters*));
  #else
   /* 112 */ void (__thiscall *RegisterAsRemoteProcedureCall)(RakServerInterface *server, char *, void(*)(RPCParameters*));
  #endif
  int RegisterClassMemberRPC;
  #if defined(__linux__)
      void (*UnregisterAsRemoteProcedureCall)(RakServerInterface *server, char *uniqueID);
  #else
      void (__thiscall* UnregisterAsRemoteProcedureCall)(RakServerInterface *server, char *uniqueID);
  #endif
  #if defined(__linux__)
  int (* RPC_1)(RakServerInterface* server, char* uniqueID, RakNet::BitStream* bitstream, PacketPriority priority, PacketReliability relability, char orderingChannel, PlayerID playerID, bool broadCast, bool shiftTimestamp);
  #else
      int (__thiscall* RPC_1)(RakServerInterface* server, char* uniqueID, RakNet::BitStream* bitstream, PacketPriority priority, PacketReliability relability, char orderingChannel, PlayerID playerID, bool broadCast, bool shiftTimestamp);
  #endif
  int vftable_84;
  int vftable_88;
  int vftable_8C;
  int vftable_90;
  int vftable_94;
  int vftable_98;
  int vftable_9C;
  int vftable_A0;
  int vftable_A4;
  int vftable_A8;
  int vftable_AC;
  int vftable_B0;
  int vftable_B4;
  int vftable_B8;
  int vftable_BC;
  int vftable_C0;
  int vftable_C4;
  int vftable_C8;
  int vftable_CC;
  int vftable_D0;
  int vftable_D4;
  int vftable_D8;
  int vftable_DC;
  int vftable_E0;
  #if defined(__linux__)
      int (* GetIndexFromPlayerID)(RakServerInterface*, int16_t binaryaddress, int16_t port);
  #else
      int (__thiscall* GetIndexFromPlayerID)(RakServerInterface* server, PlayerID player);
  #endif
  int GetPlayerIDFromIndex;
  int vftable_EC;
  int AddToBanList;
  int RemoveFromBanList;
  int ClearBanList;
  int vftable_FC;
  int vftable_100;
  int vftable_104;
  int vftable_108;
  int vftable_10C;
  int vftable_110;
  int vftable_114;
  int vftable_118;
  int vftable_11C;
  int vftable_120;
};
#pragma pack(pop)
#else 
struct RakServerInterfaceVTBL
{
  int *(__thiscall *Destructor)(RakServerInterface * ServerInterface, char);
  bool (__thiscall *Start)(RakServerInterface * ServerInterface, int16_t MaxConnections, int a3, int a4, int16_t hostshort, char *a6);
  void (__thiscall *InitializeSecurity)(RakServerInterface* ServerInterface, const char *, const char *);
  void (__thiscall *DisableSecurity)(RakServerInterface * ServerInterface);
  void (__thiscall *SetPassword)(RakServerInterface* ServerInterface, char *passwordData);
  BOOL (__thiscall *HasPassword)(RakServerInterface* ServerInterface);
  void (__thiscall *Disconnect)(RakServerInterface* ServerInterface, unsigned int, unsigned __int8);
  bool (__thiscall *Send)(RakServerInterface* ServerInterface, RakNet::BitStream *, PacketPriority, PacketReliability, char, unsigned int arg10, uint16_t, char);
  int (__thiscall *Send2)(RakServerInterface* ServerInterface, void *, int, int, int, char, int, int16_t, char);
  int vftable_24;
  Packet *(__thiscall *Receive)(RakServerInterface* ServerInterface);
  void (__thiscall *Kick)(RakServerInterface* ServerInterface, uint32_t, uint16_t);
  void (__thiscall *DeallocatePacket)(RakServerInterface* ServerInterface, Packet *);
  void (__thiscall *SetAllowedPlayers)(RakServerInterface* ServerInterface, uint16_t AllowedPlayers);
  uint16_t (__thiscall *GetAllowedPlayers)(RakServerInterface* ServerInterface);
  int16_t (__thiscall *GetConnectionList)(RakServerInterface* ServerInterface);
  int (__stdcall *PlayerIDToDottedIP)(struct in_addr a1, __int16 a2, char *a3, uint16_t *a4);
  int (__stdcall *PingPlayer)(int, int16_t);
  int (__thiscall *GetAveragePing)(RakServerInterface* ServerInterface, unsigned int a2, uint16_t a3);
  int (__thiscall *GetLastPing)(RakServerInterface* ServerInterface, struct PlayerID);
  int (__thiscall *GetLowestPing)(RakServerInterface* ServerInterface, struct PlayerID);
  void (__thiscall *StartOccasionalPing)(RakServerInterface* ServerInterface);
  void (__thiscall *StopOccasionalPing)(RakServerInterface* ServerInterface);
  bool (__thiscall *IsActive)(RakServerInterface* ServerInterface);
  int (__thiscall *GetSynchronizedRandomInteger)(RakServerInterface* ServerInterface);
  void (__thiscall *StartSynchronizedRandomInteger)(RakServerInterface* ServerInterface);
  void (__thiscall *StopSynchronizedRandomInteger)(RakServerInterface* ServerInterface);
  int vftable_6C;
  int vftable_70;
  void (__thiscall *RegisterAsRemoteProcedureCall)(RakServerInterface* ServerInterface, char *, void *);
  int RegisterClassMemberRPC;
  void (__thiscall *UnregisterAsRemoteProcedureCall)(RakServerInterface* ServerInterface, char *uniqueID);
  bool (__thiscall* RPC_3)(RakServerInterface* ServerInterface, char* uniqueID, RakNet::BitStream* stream, PacketPriority priority, PacketReliability relability, char orderingChannel, PlayerID playerid, bool broadcast, bool shiftTimestamp);
  //int vftable_80;
  bool (__thiscall* RPC_2)(RakServerInterface* ServerInterface, char *uniqueID, RakNet::BitStream *parameters, PacketPriority priority, PacketReliability reliability, char orderingChannel, PlayerID playerId, bool broadcast, bool shiftTimestamp, NetworkID networkID, RakNet::BitStream *replyFromTarget);
  int vftable_88;
  int vftable_8C;
  int vftable_90;
  int vftable_94;
  int vftable_98;
  int vftable_9C;
  int vftable_A0;
  int vftable_A4;
  int vftable_A8;
  int vftable_AC;
  int vftable_B0;
  int vftable_B4;
  int vftable_B8;
  int vftable_BC;
  int vftable_C0;
  int vftable_C4;
  int vftable_C8;
  int vftable_CC;
  int vftable_D0;
  int vftable_D4;
  int vftable_D8;
  void (__thiscall *SetRouterInterface)(RakServerInterface* ServerInterface, void * RouterInterface);
  int vftable_E0;
  int (__thiscall *GetIndexFromPlayerID)(RakServerInterface* ServerInterface, PlayerID id);
  PlayerID *(__thiscall *GetPlayerIDFromIndex)(RakServerInterface* ServerInterface, PlayerID *outPlayerID, int index);
  int vftable_EC;
  int AddToBanList;
  int RemoveFromBanList;
  int ClearBanList;
  int vftable_FC;
  int vftable_100;
  int SetTimeoutTime;
  int SetMTUSize;
  int GetMTUSize;
  int AdvertiseSystem;
  int GetStatistics;
  int vftable_118;
  int ApplyNetworkSimulator;
  bool (__thiscall *IsNetworkSimulatorActive)(RakServerInterface* ServerInterface);
};
#endif
