cmake_minimum_required(VERSION 3.11)
project("anykeys" LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-DHAVE_STDINT_H)

if(WIN32)
    add_definitions(-DWINDOWS_IGNORE_PACKING_MISMATCH)
    add_definitions(-D_WINSOCKAPI_)
    add_compile_options(/MT)
elseif(UNIX)
    add_compile_definitions(-DLINUX)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -fvisibility=hidden -s -g -nostdlib -m32 -static -pthread")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32 -nostdlib -O3 -s -g -fvisibility=hidden -Os -static-libstdc++ -static-libgcc -Bstatic -lstdc++ -lm -lc -lgcc_s -lgcc -static -pthread")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -m32 -O3 -static -Wl,-Bstatic -lstdc++ -lm -lc -lgcc_s -lgcc -pthread")
endif()

add_subdirectory(${CMAKE_SOURCE_DIR}/samp-server-api)
# add_subdirectory(${CMAKE_SOURCE_DIR}/minhook)
include_directories(${CMAKE_SOURCE_DIR}/samp-server-api/include/raknet)

# include_directories(${CMAKE_SOURCE_DIR}/amx)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/samp-server-api/include)
# include_directories(${CMAKE_SOURCE_DIR}/minhook/include)

file(GLOB_RECURSE FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_library(anykeys SHARED
    main.cpp
    ${FILES}
    exports.def
)

target_link_libraries(anykeys PRIVATE sapi)