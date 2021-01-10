#include <gtest/gtest.h>
#include <chess_src/chess.hpp>

TEST(googleTestWorking, googleTestWorking)
{
    EXPECT_EQ(true, true);
}

TEST(illegalInputTesting, notExistingPice)
{
    chess::chess chf;
    chf.clearField();
    EXPECT_FALSE(chf.canMovePice(2,2,2,3, true)) << "non-existing white piece";
    EXPECT_FALSE(chf.canMovePice(3,4,5,6, false));
}
