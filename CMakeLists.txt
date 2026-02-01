cmake_minimum_required(VERSION 3.10)
project(Common C)

add_library(
    Common
    INTERFACE
    NameManglingGuard.h
    CompilerDetection.h
    BasicDataTypes.h
    Keywords.h
    Endian.h
    Packed.h)
    
target_include_directories(Common INTERFACE ${CMAKE_CURRENT_LIST_DIR}/..)
