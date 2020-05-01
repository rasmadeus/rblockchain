cmake_minimum_required(VERSION 3.14)
project(rblockchain VERSION 1.0 LANGUAGES CXX)

set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

add_executable(
    rblockchain
    block.h
    block.cpp
    blockchain.h
    blockchain.cpp
    sha256/sha256.h
    sha256/sha256.cpp
    main.cpp
)

target_compile_features(
    rblockchain
    INTERFACE
        cxx_std_17
)

target_compile_options(
    rblockchain
    INTERFACE
        "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

target_include_directories(
    rblockchain
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(
    rblockchain
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/sha256
)
