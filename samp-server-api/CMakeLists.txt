cmake_minimum_required(VERSION 3.11)
project(serverapi LANGUAGES C CXX)

if(UNIX)
    add_compile_definitions(-DHAVE_STDINT_H -DLINUX)
elseif(WIN32)
    add_definitions(-DHAVE_STDINT_H -DWIN32 -D_WINSOCKAPI_)
    add_definitions(-DWINDOWS_IGNORE_PACKING_MISMATCH)
    add_compile_options(/Zp1)
    add_compile_options(/MT)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/raknet)

file(GLOB_RECURSE FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(sapi STATIC ${FILES})