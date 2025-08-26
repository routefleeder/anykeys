#pragma once
#include "basics/CMenu.h"
struct CMenuPool
{
    CMenu *m_pMenus[128];
    BOOL m_bMenuSlotState[128];
    BYTE m_bytePlayerMenu[1000];
};