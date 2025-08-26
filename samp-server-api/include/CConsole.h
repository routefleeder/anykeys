#pragma once

#ifdef _WIN32
    #include <Windows.h>
#else
    using DWORD = unsigned int;
#endif
typedef void(__cdecl *VARCHANGEFUNC)();

enum CON_VARTYPE : int
{
    CON_VARTYPE_FLOAT = 0u,
    CON_VARTYPE_INT = 1u,
    CON_VARTYPE_BOOL = 2u,
    CON_VARTYPE_STRING = 3u,
};

enum CON_VARFLAG : int
{
  CON_VARFLAG_DEBUG = 1u,
  CON_VARFLAG_READONLY = 2u,
  CON_VARFLAG_RULE = 4u,
};


#pragma pack(1)
struct ConsoleVariable_s
{
  CON_VARTYPE VarType;
  DWORD VarFlags;
  void *VarPtr;
  VARCHANGEFUNC VarChangeFunc;
};
#pragma pack(pop)

#pragma pack(1)
struct CConsole
{
    unsigned char gap0;
    int field_1;
    int field_5;
    int field_9;
    int field_D;
    int field_11;
    void AddVariable(const char *pVarName, CON_VARTYPE VarType, DWORD VarFlags, void *VarPtr, VARCHANGEFUNC VarChangeFunc);
    bool GetBoolVariable(const char *pVarName);
    int GetIntVariable(const char *pVarName);
    void Execute(const char *pExecute);
    void PrintVariableList();
    void ModifyVariableFlags(const char *pVarName, CON_VARFLAG VarFlags);

    ConsoleVariable_s* FindVariable(const char* pVarName);

    static inline CConsole* GetConsole()
    {
        #if defined(WIN32)
            return *reinterpret_cast<CConsole**>(0x4F5FBC);
        #endif
    }
};
#pragma pack(pop)
