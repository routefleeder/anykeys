#pragma once
#include "basics/CGameMode.h"
#include "basics/CFilterscripts.h"
#include "CPlayerPool.h"
#include "CVehiclePool.h"
#include "CPickupPool.h"
#include "CObjectPool.h"
#include "CMenuPool.h"
#include "CTextDrawPool.h"
#include "CLabelPool.h"
#include "CGangzonePool.h"
#include "CActorPool.h"
#include "BitStream.h"
#include "RakServerInterface_vtbl.h"

struct CNetGame
{
  CGameMode *m_pGameMode;
  CFilterScripts *m_pFilterScripts;
  CPlayerPool *m_pPlayerPool;
  CVehiclePool *m_pVehiclePool;
  CPickupPool *m_pPickupPool;
  CObjectPool *m_pObjectPool;
  CMenuPool *m_pMenuPool;
  CTextDrawPool *m_pTextPool;
  CLabelPool *m_pLabelPool;
  CGangZonePool *m_pGangZonePool;
  CActorPool *m_pActorPool;
  int m_iCurrentGameModeIndex;
  int m_iCurrentGameModeRepeat;
  BOOL m_bFirstGameModeLoaded;
  CScriptHttps *m_pScriptHttps;
  CScriptTimers *m_pScriptTimers;
  RakServerInterface *m_pRak; //RakSerInterface
  int m_iLastServerTickUpdate;
  int m_iServerTickCount;
  int m_iServerTickRate;
  BOOL m_bLanMode;
  int m_iShowPlayerMarkers;
  bool m_bShowNameTags;
  BYTE m_byteWorldTime;
  bool m_bAllowWeapons;
  bool m_bStuntBonus;
  char field_5C;
  BYTE m_byteWeather;
  int m_iGameState;
  float m_fGravity;
  int m_iDeathDropMoney;
  char field_6A;
  char field_6B;
  bool m_bLimitGlobalChatRadius;
  bool m_bUseCJWalk;
  float m_fGlobalChatRadius;
  float m_fNameTagDrawDistance;
  bool m_bDisableEnterExits;
  bool m_bNameTagLOS;
  bool m_bManualVehicleEngineAndLights;
  bool m_bLimitPlayerMarkerRadius;
  float m_fPlayerMarkerRadius;
  BOOL m_bVehicleFriendlyFire;
  int m_iSpawnsAvailable;
  PLAYER_SPAWN_INFO m_AvailableSpawns[318];

    void SendToPlayer(char* uniqueID, RakNet::BitStream* stream, unsigned short playerid, char orderingchannel);
    void BroadCastData(char* uniqueID, RakNet::BitStream* stream, PLAYERID excludedPlayer, char orderingChannel);
    void VehicleBroadcast(char* uniqueID, RakNet::BitStream* stream, uint16_t vehicleid, PLAYERID playerid, char orderingchannel);
    // void UpdateNetwork();
    // void Packet_NewIncomingConnection(Packet* packet);
    // void Packet_DisconnectionNotification(Packet* packet);
    void KickPlayer(PLAYERID kickPlayer);
    RakServerInterfaceVTBL* GetRakServerVTable();

    void Packet_NewIncomingConnection(Packet* packet);
};
