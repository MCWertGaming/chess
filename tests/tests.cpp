#include <gtest/gtest.h>
#include <chess_src/chess.hpp>

TEST(googleTestWorking, googleTestWorking)
{
    EXPECT_EQ(true, true);
}

TEST(illegalInputTesting, notExistingPiece)
{
    chess::chess chf;
    chf.clearField();
    EXPECT_FALSE(chf.canMovePiece(2,2,2,3, true)) << "non-existing white piece";
    EXPECT_FALSE(chf.canMovePiece(3,4,5,6, false));
}
