#include "PluginNatives.h"
// #include <future>
#include "BitStream.h"
#include <string>
// #include "sampgdk.h"
// #include "PluginPointers.h"
#include "Callbacks.h"

void PluginNatives::GetPlayerPressedKey(RPCParameters *rpcparams)
{
    // std::async(std::launch::async, [&]()
    // {
        int playerid;
        int key;
        int lastKey;
        RakNet::BitStream stream = RakNet::BitStream(rpcparams->input, rpcparams->numberOfBitsOfData / 8 + 1, true);
        stream.Read(playerid);
        stream.Read(key);
        stream.Read(lastKey);

        PluginCallbacks::OnPlayerPressKey(lastKey, key, playerid);

        // std::string pid_str = std::to_string(playerid);
        // std::string key_str = std::to_string(key);
        // std::string f_str = "ID: " + pid_str + " | Key: " + key_str;
        // SendClientMessageToAll(0xffffffff, key_str.c_str());
        // printf("%s\n", f_str.c_str());
    // });
}