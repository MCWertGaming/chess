cmake_minimum_required(VERSION 3.16)
project(chess
        VERSION 0.0.1
        DESCRIPTION "Chess - a Simple chess game inside your terminal"
        HOMEPAGE_URL "https://github.com/MCWertGaming/chess"
        LANGUAGES CXX)

# use newest CXX standard, because why not
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# configure about file
configure_file(chess/information.hpp.in chess/information.hpp)
# add include directory for using generated headers
include_directories(${CMAKE_CURRENT_BINARY_DIR}/chess)

# include cmake modules
include(FetchContent)

# disable ftxui library targets
set(FTXUI_BUILD_EXAMPLES false)
set(FTXUI_BUILD_DOCS false)
set(FTXUI_ENABLE_INSTALL false)
set(FTXUI_BUILD_TESTS false)

# disable not required FOLF targets
set(FOLF_BUILD_EXAMPLES false)
set(FOLF_ENABLE_INSTALL false)

# download ftxui library
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui.git
)
FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# download folf-namespace library
FetchContent_Declare(folf_namespace
  GIT_REPOSITORY https://github.com/FOLF-projects/folf-namespace.git
  GIT_TAG main
)
FetchContent_GetProperties(folf_namespace)
if(NOT folf_namespace_POPULATED)
  FetchContent_Populate(folf_namespace)
  add_subdirectory(${folf_namespace_SOURCE_DIR} ${folf_namespace_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# targets
add_executable(hello-world chess/hello-world.cpp)

add_executable(config-test chess/config-test.cpp)
target_link_libraries(config-test PRIVATE folf-namespace)

add_executable(main chess/main.cpp)

# create a list of all targets
set(target-list hello-world config-test main)

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
