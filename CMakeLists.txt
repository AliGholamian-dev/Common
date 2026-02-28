cmake_minimum_required(VERSION 3.10)
project(Common C)

add_library(
    Common
    INTERFACE
    Include/Common/NameManglingGuard.h
    Include/Common/PlatformDetection.h
    Include/Common/CompilerDetection.h
    Include/Common/BasicDataTypes.h
    Include/Common/Keywords.h
    Include/Common/Endian.h
    Include/Common/Handle.h
    Include/Common/Packed.h)
    
target_include_directories(Common INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Include)
