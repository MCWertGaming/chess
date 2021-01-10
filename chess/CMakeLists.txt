# configure about file
configure_file(info.hpp.in info.hpp)

# make chess a library
add_library(chesslib chess.cpp)
# target_link_libraries(chesslib PRIVATE -lib-)
target_include_directories(chesslib INTERFACE ${PROJECT_SOURCE_DIR} ${PROJECT_BINARY_DIR})
set_target_properties(chesslib PROPERTIES
        PUBLIC_HEADER "chess/chess.hpp;chess/info.hpp;chess/parsing.hpp")
