#include "CVehiclePool.h"

VEHICLEID CVehiclePool::New(int iVehicleType, VECTOR *vecPos, float fRotation, int iColor1, int iColor2, int iRespawnDelay)
{
    #if ISLINUX
        return reinterpret_cast<VEHICLEID(*)(CVehiclePool*, int, VECTOR*, float, int, int, int)>(0x814CB10)(this ,iVehicleType, vecPos, fRotation, iColor1, iColor2, iRespawnDelay); 
    #elif defined(WIN32)
        return reinterpret_cast<VEHICLEID(__thiscall*)(CVehiclePool* ,int, VECTOR*, float, int, int, int)>(0x467460)(this ,iVehicleType, vecPos, fRotation, iColor1, iColor2, iRespawnDelay);
    #endif
}

int CVehiclePool::SetNewCVehiclePoolSize()
{
    #if ISLINUX
        return reinterpret_cast<int(*)(CVehiclePool*)>(0x814CA20)(this);
    #elif defined(WIN32)
        return reinterpret_cast<int(__thiscall*)(CVehiclePool*)>(0x4673C0)(this);
    #endif
}