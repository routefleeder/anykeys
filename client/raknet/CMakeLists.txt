cmake_minimum_required(VERSION 3.11)
project("raknet samp vendor" LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 14)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-DRAKSAMP_CLIENT)
add_definitions(-D_WINSOCKAPI_)

add_compile_options(/MP)
add_compile_options(/Zp1)

add_compile_definitions(WINDOWS_IGNORE_PACKING_MISMATCH)
# Найдите все .cpp и .h файлы во всех вложенных папках
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Создайте библиотеку с найденными файлами
add_library(raknet STATIC ${SOURCES})
