cmake_minimum_required(VERSION 3.11)
project("AnyKeys" LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

add_compile_options(/MT)

set(SHARED_DIR ${CMAKE_SOURCE_DIR}/plugin-sdk-cmake/shared)

add_definitions(-DSAMP_R3_COMPILE)

add_compile_definitions(GTASA)
add_compile_definitions(RW)
add_compile_definitions(IS_PLATFORM_WIN_X86)
add_compile_definitions(WIN32)
add_compile_definitions(IS_PLATFORM_WIN)
add_compile_definitions(IS_ARCHITECTURE_X86)
add_compile_definitions(IS_ARCHITECTURE_32_BIT)

include_directories(${CMAKE_SOURCE_DIR}/plugin-sdk-cmake)
include_directories(${CMAKE_SOURCE_DIR}/plugin-sdk-cmake/include/game_sa)
include_directories(${CMAKE_SOURCE_DIR}/plugin-sdk-cmake/safetyhook)
include_directories(${CMAKE_SOURCE_DIR}/plugin-sdk-cmake/shared)
include_directories(${CMAKE_SOURCE_DIR}/plugin-sdk-cmake/stb)

include_directories(${SHARED_DIR}/bass)
include_directories(${SHARED_DIR}/comp)
include_directories(${SHARED_DIR}/dxsdk)
include_directories(${SHARED_DIR}/extender)
include_directories(${SHARED_DIR}/extensions)
include_directories(${SHARED_DIR}/game)

include_directories(${CMAKE_SOURCE_DIR}/SAMP-API/include)
include_directories(${CMAKE_SOURCE_DIR}/include)
# include_directories(${CMAKE_SOURCE_DIR}/minhook/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/plugin-sdk-cmake)

add_subdirectory(${CMAKE_SOURCE_DIR}/SAMP-API)
add_subdirectory(${CMAKE_SOURCE_DIR}/raknet)
# add_subdirectory(${CMAKE_SOURCE_DIR}/minhook)

file(GLOB_RECURSE FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_library(AnyKeys SHARED
    dllmain.cpp
    ${FILES}
)

target_link_libraries(AnyKeys PRIVATE sampapi raknet plugin-sdk)