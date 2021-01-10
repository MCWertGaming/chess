# targets
add_executable(hello-world hello-world.cpp)

add_executable(config-test config-test.cpp)
target_link_libraries(config-test
        PRIVATE folf-namespace
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component
        )

add_executable(terminal-sandbox terminal-sandbox.cpp)
target_link_libraries(terminal-sandbox
        PRIVATE folf-namespace
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component
        )