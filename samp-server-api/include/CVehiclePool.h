#pragma once
#include "CVehicle.h"

struct CVehiclePool
{
    char field_0[212];
    int m_iVirtualWorld[2000];
    int m_bVehicleSlotState[2000];
    CVehicle *m_pVehicles[2000];
    int m_iPoolSize;

    VEHICLEID New(int iVehicleType, VECTOR *vecPos, float fRotation, int iColor1, int iColor2, int iRespawnDelay);
    int SetNewCVehiclePoolSize();
};