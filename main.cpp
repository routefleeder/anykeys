// #include "ptl.h"
#include <thread>
#include "InitStuff.h"
#include "sampgdk.h"
// #include "PluginPointers.h"
// #include "PluginNatives.h"

extern void *pAMXFunctions;

// AMX_NATIVE_INFO NATIVES_LIST[] =
// {
  //     {"NewNative", PluginNatives::NewNative},
  //     { 0, 0 },
  // };
  
  // class Script : public ptl::AbstractScript<Script> {
    //  public:
    //   // native ExampleNative(int_number, Float:float_number, &ref, const text[]);
    //   cell n_ExampleNative(int int_number, float float_number, cell *ref,
    //                        std::string text) {
      //     Log("int_number = %d, float_number = %.2f, text = '%s'", int_number,
      //         float_number, text.c_str());
      
      //     *ref = 23;

//     return 1;
//   }
// };

// class Plugin : public ptl::AbstractPlugin<Plugin, Script> {
//  public:
//   const char *Name() { return "anykeys"; }

//   bool OnLoad() {
//     RegisterNative<&Script::n_ExampleNative>("ExampleNative");

//     Log("anykeys plugin loaded");

//     return true;
//   }
// };

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData) {
  std::thread(PluginInitialize::InitializeCNetGame).detach();
  pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
  sampgdk_logprintf("\n----------------------------------------\nanykeys plugin v1.0 successfully loaded!\n\nAuthor: routefleeder\n\nhttps://github.com/routefleeder/anykeys\n----------------------------------------\n");
  // sampgdk::Load(ppData);
  return true;
  // return Plugin::DoLoad(ppData);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
    return sampgdk::Unload();
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx)
{
  // return amx_Register(amx, NATIVES_LIST, -1);
  return 1;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx) { return 1; }

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
  return sampgdk::Supports() | SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}