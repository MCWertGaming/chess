cmake_minimum_required(VERSION 3.16)
project(chess
        VERSION 0.0.1
        DESCRIPTION "Chess - a Simple chess game inside your terminal"
        HOMEPAGE_URL "https://github.com/MCWertGaming/chess"
        LANGUAGES CXX)

# use newest CXX standard, because why not
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# include dependencies
add_subdirectory(dependencies)

# inlude sub folders
add_subdirectory(chess_src)
add_subdirectory(chess_tools)
add_subdirectory(chess_fronts)
add_subdirectory(tests)

# create a list of all targets
set(target-list hello-world config-test terminal-sandbox chess-testing-old testing-target chesslib)

# enable warnings and set compile features
foreach(target ${target-list})
        # Force Microsoft Visual Studio to decode sources files in UTF-8
        if (MSVC)
                target_compile_options(${target} PUBLIC "/utf-8")
        endif()
        # Add as many warning as possible:
        if (WIN32)
                if (MSVC)
                        target_compile_options(${target} PRIVATE "/W4")
                        target_compile_options(${target} PRIVATE "/WX")
                        target_compile_options(${target} PRIVATE "/wd4244")
                        target_compile_options(${target} PRIVATE "/wd4267")
                        target_compile_options(${target} PRIVATE "/D_CRT_SECURE_NO_WARNINGS")
                endif()
                # Force Win32 to UNICODE
                target_compile_definitions(${target} PRIVATE UNICODE _UNICODE)
        else()
                target_compile_options(${target} PRIVATE "-Wall")
                target_compile_options(${target} PRIVATE "-Wextra")
                target_compile_options(${target} PRIVATE "-pedantic")
                target_compile_options(${target} PRIVATE "-Werror")
                target_compile_options(${target} PRIVATE "-Wno-sign-compare")
        endif()
endforeach(target ${target-list})
