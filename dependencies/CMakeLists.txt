# include cmake modules
include(FetchContent)

# disable ftxui library targets
set(FTXUI_BUILD_EXAMPLES OFF CACHE BOOL "don't build examples" FORCE)
set(FTXUI_BUILD_DOCS OFF CACHE BOOL "don't build docs" FORCE)
set(FTXUI_ENABLE_INSTALL OFF CACHE BOOL "disable install" FORCE)
set(FTXUI_BUILD_TESTS OFF CACHE BOOL "disable tests" FORCE)

# disable not required FOLF targets
set(FOLF_BUILD_EXAMPLES OFF CACHE BOOL "don't build examples" FORCE)
set(FOLF_ENABLE_INSTALL OFF CACHE BOOL "disable install" FORCE)
set(FOLF_ENABLE_TESTING OFF CACHE BOOL "disable testing of folf" FORCE)

# disable google-test targets
set(INSTALL_GTEST OFF CACHE BOOL "disable gtest install" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "disable gmock" FORCE)

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

# download google test
FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG master
)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
        FetchContent_Populate(googletest)
        add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
