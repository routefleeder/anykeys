#include "CConsole.h"

bool CConsole::GetBoolVariable(const char *pVarName)
{
    #if defined(WIN32)
        return reinterpret_cast<bool(__thiscall*)(CConsole*, const char*)>(0x48B5F0)(this, pVarName);
    #endif
}

int CConsole::GetIntVariable(const char *pVarName)
{
    return reinterpret_cast<int(__thiscall*)(CConsole*, const char*)>(0x48B5B0)(this, pVarName);
}

void CConsole::AddVariable(const char *pVarName, CON_VARTYPE VarType, DWORD VarFlags, void *VarPtr, VARCHANGEFUNC VarChangeFunc)
{
    #if defined(WIN32)
        return reinterpret_cast<void(__thiscall*)(CConsole*, const char*, CON_VARTYPE, DWORD, void*, VARCHANGEFUNC)>(0x48C3E0)(this, pVarName, VarType, VarFlags, VarPtr, VarChangeFunc);
    #endif
}

void CConsole::Execute(const char *pExecute)
{
    #if defined(WIN32)
        return reinterpret_cast<void(__thiscall*)(CConsole*, const char*)>(0x48B610)(this, pExecute);
    #endif
}

ConsoleVariable_s* CConsole::FindVariable(const char* pVarName)
{
    #if defined(WIN32)
        return reinterpret_cast<ConsoleVariable_s*(__thiscall*)(CConsole*, const char*)>(0x48B3D0)(this, pVarName);
    #endif
}

void CConsole::PrintVariableList()
{
    #if defined(WIN32)
        reinterpret_cast<void(__thiscall*)(CConsole*)>(0x48AF10)(this);
    #endif
}

void CConsole::ModifyVariableFlags(const char *pVarName, CON_VARFLAG VarFlags)
{
    #if defined(WIN32)
        reinterpret_cast<void(__thiscall*)(CConsole*, const char*, CON_VARFLAG)>(0x48B4B0)(this, pVarName, VarFlags);
    #endif
}
