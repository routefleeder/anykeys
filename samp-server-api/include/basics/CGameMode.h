#pragma once

#include "amx/amx.h"

#pragma pack(push, 1)
struct CGameMode
{
  AMX m_amx;
  bool m_bInitialised;
  bool m_bSleeping;
  float m_fSleepTime;

  int OnPlayerKeyStateChange(cell playerid, cell newkeys, cell oldkeys);
  int OnVehicleMod(cell playerid, cell vehicleid, cell componentid);
};
#pragma pack(pop)