# configure about file
configure_file(info.hpp.in info.hpp)

# chess source
set(chess-source chess.cpp)

# make chess a library
add_library(chesslib ${chess-source})
# target_link_libraries(chesslib PRIVATE -lib-)
target_include_directories(chesslib INTERFACE ${PROJECT_SOURCE_DIR} ${PROJECT_BINARY_DIR})
set_target_properties(chesslib PROPERTIES
        PUBLIC_HEADER "chess_src/chess.hpp;chess_src/info.hpp;chess_src/parsing.hpp")
