#pragma once
#include "../main.h"

struct MENU_INT
{
    BOOL bMenu;
    BOOL bRow[12];
    BOOL bPadding[3];
};

struct CMenu
{
    BYTE m_byteMenuID;
    CHAR m_charTitle[32];
    CHAR m_charItems[12][2][32];
    CHAR m_charHeader[2][32];
    BOOL m_bInitedForPlayer[1000];
    MENU_INT m_MenuInteraction;
    float m_fXPos;
    float m_fYPos;
    float m_fCol1Width;
    float m_fCol2Width;
    BYTE m_byteColumns;
    BYTE m_byteColCount[2];
};