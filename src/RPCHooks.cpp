#include "InitStuff.h"
#include "PluginPointers.h"
#include "PluginNatives.h"

void PluginInitialize::RegisterRPCHooks()
{
    char rpcid = 241;
    PluginPointers::GetCNetGamePointer()->GetRakServerVTable()->RegisterAsRemoteProcedureCall(PluginPointers::GetCNetGamePointer()->m_pRak, &rpcid, PluginNatives::GetPlayerPressedKey);
}