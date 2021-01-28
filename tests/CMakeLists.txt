# enable unit testing
enable_testing()

# get google test
include(GoogleTest)

add_executable(testingTarget pieceTesting.cpp gameTesting.cpp)
target_link_libraries(testingTarget PRIVATE gtest gtest_main chesslib)
