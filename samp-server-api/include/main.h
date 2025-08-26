#pragma once
#include <stdint.h>
#include "NetworkTypes.h"

#if defined(__linux__)
using BYTE = uint8_t;
using CHAR = char;
using DWORD = uint32_t;
using BOOL = int;
using WORD = uint16_t;
#else
#include <Windows.h>
#endif

#define ISLINUX (defined(__linux__))
#define ISWIN32 (defined(WIN32))

using VEHICLEID = uint16_t;
using PLAYERID = uint16_t;


struct struc_92
{
  char _pad0;
  BYTE gap1[50];
  char _pad;
};

struct CScriptTimers
{
  BYTE gap0[12];
  DWORD m_dwTimerCount;
};

struct struc_24
{
  BYTE gap0[32];
  char _pad;
};

struct CScriptHttps
{
  int field_0[200];
};