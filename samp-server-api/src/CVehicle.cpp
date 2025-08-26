#include "CVehicle.h"

CVehicle::CVehicle(int iModel, CVector* vecPos, float fRotation, int iColor1, int iColor2, int iRespawnTime)
{
    #if ISLINUX
        reinterpret_cast<void(*)(CVehicle*, int, CVector*, float, int, int, int)>(0x0814AF60)(this, iModel, vecPos, fRotation, iColor1, iColor2, iRespawnTime);
    #elif defined(WIN32)
        reinterpret_cast<void(__thiscall*)(CVehicle*, int, CVector*, float, int, int, int)>(0x488300)(this, iModel, vecPos, fRotation, iColor1, iColor2, iRespawnTime);
    #endif
}

void CVehicle::StreamOutVehicle()
{
    #if ISLINUX
        reinterpret_cast<void(*)(CVehicle*)>(0x814B1A0)(this);
    #elif defined(WIN32)
        reinterpret_cast<void(__thiscall*)(CVehicle*)>(0x4884E0)(this);
    #endif
}

CVehicle* CVehicle::Constructor(int iModel, CVector* vecPos, float fRotation, int iColor1, int iColor2, int iRespawnTime)
{
    #if ISLINUX
        return reinterpret_cast<CVehicle*(*)(CVehicle*, int, CVector*, float, int, int, int)>(0x0814AF60)(this, iModel, vecPos, fRotation, iColor1, iColor2, iRespawnTime);
    #elif defined(WIN32)
        return reinterpret_cast<CVehicle*(__thiscall*)(CVehicle*, int, CVector*, float, int, int, int)>(0x488300)(this, iModel, vecPos, fRotation, iColor1, iColor2, iRespawnTime);
    #endif
}