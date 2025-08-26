#pragma once
#include "main.h"
#include "CPlayer.h"

class CPlayerPool
{
public:
    int m_iVirtualWorld[1000];
    int field_FA0;
    int field_FA4;
    int field_FA8;
    int m_iPlayerScore[1000];
    int m_iPlayerMoney[1000];
    int m_iPlayerDrunkLevel[1000];
    DWORD field_3E8C[1000];
    CHAR m_szPlayerClientID[1000][101];
    CHAR m_szPlayerVersion[1000][25];
    int field_23A5C[1000];
    BOOL m_bPlayerSlotState[1000];
    CPlayer *m_pPlayers[1000];
    CHAR m_szPlayerName[1000][25];
    BOOL m_bIsAnAdmin[1000];
    BOOL m_bIsAnNPC[1000];
    BYTE gap2EA24[8000];
    int field_30964;
    int m_iPoolSize;
    int field_3096C;
};

