# enable unit testing
enable_testing()

# get google test
include(GoogleTest)

add_executable(testing-target tests.cpp)
target_link_libraries(testing-target PRIVATE gtest gtest_main chesslib)
