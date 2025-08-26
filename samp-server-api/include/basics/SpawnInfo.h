#pragma once
#include "vector.h"

struct PLAYER_SPAWN_INFO  
{
  unsigned char byteTeam;
  int iSkin;
  unsigned char field_5;
  VECTOR vecPos;
  float fRotation;
  int iSpawnWeapons[3];
  int iSpawnWeaponsAmmo[3];
};

struct VEHICLE_SPAWN_INFO
{
  int iVehicleType;
  VECTOR vecPos;
  float fRotation;
  int iColor1;
  int iColor2;
  int iRespawnDelay;
  int iInterior;
};