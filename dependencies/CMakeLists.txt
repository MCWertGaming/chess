# include cmake modules
include(FetchContent)

# disable ftxui library targets
set(FTXUI_BUILD_EXAMPLES off)
set(FTXUI_BUILD_DOCS off)
set(FTXUI_ENABLE_INSTALL off)
set(FTXUI_BUILD_TESTS off)

# disable not required FOLF targets
set(FOLF_BUILD_EXAMPLES off)
set(FOLF_ENABLE_INSTALL off)

# disable google-test targets
set(INSTALL_GTEST off)
set(BUILD_GMOCK off)

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
