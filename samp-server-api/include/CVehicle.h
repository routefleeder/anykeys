#include "basics/CarModInfo.h"
#include "basics/SpawnInfo.h"
#include "main.h"
#include "basics/matrix.h"
#include "basics/vector.h"

#pragma pack(1)
struct CVehicle
{
  VECTOR field_0;
  MATRIX4X4 m_matWorld;
  char field_4C[12];
  char field_58[12];
  VEHICLEID m_VehicleID;
  short field_66;
  BYTE gap68[2];
  short field_6A;
  BYTE gap6C[14];
  int field_7A;
  int field_7E;
  VEHICLE_SPAWN_INFO m_SpawnInfo;
  float m_fHealth;
  int field_AA;
  int field_AE;
  char field_B2;
  char field_B3;
  char field_B4;
  short field_B5;
  CAR_MOD_INFO m_CarModInfo;
  char field_CE[33];
  char field_EF;
  char field_F0;
  char field_F1;
  char field_F2;
  char field_F3;
  char field_F4;
  char field_F5;
  char field_F6;
  char field_F7;
  char field_F8;
  char field_F9;
  char field_FA;
  char field_FB;
  char field_FC;
  char field_FD;
  char field_FE;
  char field_FF;
  char field_100;
  BYTE gap101[4];
  int field_105;
  char field_109;
  char field_10A;

  CVehicle(int iModel, CVector* vecPos, float fRotation, int iColor1, int iColor2, int iRespawnTime);
  void StreamOutVehicle();
  CVehicle* Constructor(int iModel, CVector* vecPos, float fRotation, int iColor1, int iColor2, int iRespawnTime);
};
#pragma pack(pop)
