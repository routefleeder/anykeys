# anykeys
A plugin for the SA-MP server that adds the ability to work with all keys on the keyboard.

So u can capture any key by the callback like this (key combinations also supported):
```pawn
#include <anykeys>

public OnPlayerPressKey(playerid, key, lastkey)
{
  if(key == VK_J || key == VK_LSHIFT) // for single key presses
  {
    new keyCode[144];
    format(keyCode, sizeof(keyCode), "You just pressed J or Left Shift key! Key code: %d", key);
    SendClientMessage(playerid, -1, "You just pressed J or Left Shift key!");
  }
  else if(key == VK_W && lastkey == VK_LSHIFT) // for key combinations
  {
    SendClientMessage(playerid, -1, "Shift + W combination detected!");
  }

  return 1;
}
```

All the key names defines u can check in `anykeys.inc`.

# Want to build and compile the project by urself? No problem:

Into the project repo u can find `CMakeLists.txt` files, all u need is contains in the root and the anykeys/client directories.
# Plugin build:
```bash
cmake -B build -A Win32 # for Windows
# then u can compile via Visual Studio (MSVC) from the .sln file in the new build folder (make sure if u have it and all needed C++ packages/redists.
# or by:
cd build
cmake --build --config=Release

# Linux building:
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

# Used libraries:
[sampgdk](https://github.com/Hereticbeast/sampgdk)
[RakNet](https://github.com/facebookarchive/RakNet)
[SAMP-API](https://github.com/BlastHackNet/SAMP-API)
