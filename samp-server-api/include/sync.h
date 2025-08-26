#include "basics/vector.h"
#include "main.h"

struct AIM_SYNC_DATA
{
  char _pad0;
  VECTOR field_1;
  VECTOR field_D;
  unsigned char gap19[5];
  char _pad;
};

struct INCAR_SYNC_DATA
{
  char _pad0;
  unsigned char gap1[61];
  char _pad;
};

struct PASSENGER_SYNC_DATA
{
  VEHICLEID VehicleID;
  unsigned char gap2[21];
  char _pad;
};

// sizeof 70
struct ONFOOT_SYNC_DATA
{
  WORD lrAnalog;
  WORD udAnalog;
  WORD wKeys;
  VECTOR vecPos;
  BYTE gap12[16];
  BYTE byteHealth;
  BYTE byteArmour;
  unsigned short weaponID;
  BYTE byteSpecialAction;
  BYTE gap26[29];
  char _pad;
};

// int x = sizeof(ONFOOT_SYNC_DATA);

struct UNOCCUPIED_SYNC_DATA
{
  char _pad0;
  unsigned char gap1[65];
  char _pad;
};

struct SPECTATOR_SYNC_DATA
{
  char _pad0;
  unsigned char gap1[16];
  char _pad;
};

struct TRAILER_SYNC_DATA
{
  char _pad0;
  VECTOR field_2;
  unsigned char gapE[16];
  VECTOR field_1E;
  unsigned char gap2A[11];
  char _pad;
};