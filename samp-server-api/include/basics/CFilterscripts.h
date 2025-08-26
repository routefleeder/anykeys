#pragma once
#include "amx/amx.h"

struct CFilterScripts
{
  AMX *m_pFilterScripts[16];
  char m_szFilterScriptName[16][255];
  int m_iFilterScriptCount;

  int OnPlayerKeyStateChange(cell playerid, cell newkeys, cell oldkeys);
  int OnVehicleMod(cell playerid, cell vehicleid, cell componentid);
};