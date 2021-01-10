#include <gtest/gtest.h>
#include <chess/chess.hpp>
#include <chess/parsing.hpp>

TEST(googleTestWorking, googleTestWorking)
{
    EXPECT_EQ(true, true);
}

TEST(illegalInputTesting, notExistingPiece)
{
    chess::chess chf;
    chf.clearField();
    EXPECT_FALSE(chf.canMovePiece(2,2,2,3, true)) << "non-existing white piece";
    EXPECT_FALSE(chf.canMovePiece(3,4,5,6, false)) << "non-existing black piece";
}
TEST(illegalInputTesting, movePieceToItsOwnLocation)
{
    chess::chess chf;
    chf.clearField();
    chf.createPiece(2,2,pieceBlackPawn);
    chf.createPiece(4,4,pieceWhitePawn);
    EXPECT_FALSE(chf.canMovePiece(2,2,2,2, true));
    EXPECT_FALSE(chf.canMovePiece(4,4,4,4,true));
}
TEST(illegalInputTesting, moveToIllegalPosition)
{
    chess::chess chf;
    chf.clearField();
    chf.createPiece(2,2,pieceBlackPawn);
    chf.createPiece(4,4,pieceWhitePawn);
    EXPECT_FALSE(chf.canMovePiece(2,2,34,78, true));
    EXPECT_FALSE(chf.canMovePiece(4,4,90,23489,true));
    EXPECT_FALSE(chf.canMovePiece(99,424,4324,42342,false));
    EXPECT_FALSE(chf.canMovePiece(4554,444,43534,45435,false));
}
TEST(illegalInputTesting, giveWrongColor)
{
    chess::chess chf;
    chf.clearField();
    chf.createPiece(3,3,pieceWhitePawn);
    chf.createPiece(5,5,pieceBlackPawn);
    EXPECT_FALSE(chf.canMovePiece(3,3,3,4, false));
    EXPECT_FALSE(chf.canMovePiece(5,5,5,4, true));
}

TEST(pieceMovementTest, whitePawnTestingMiddle)
{
    chess::chess chf;
    chf.clearField();
    chf.createPiece(3,4,pieceWhitePawn);
    EXPECT_TRUE(chf.canMovePiece(3,4,3,5, true));
    EXPECT_FALSE(chf.canMovePiece(3,4,3,6, true));
    EXPECT_FALSE(chf.canMovePiece(3,4,3,7, true));
    EXPECT_FALSE(chf.canMovePiece(3,4,4,5, true));
    EXPECT_FALSE(chf.canMovePiece(3,4,4,4, true));
    EXPECT_FALSE(chf.canMovePiece(3,4,1,3, true));
    EXPECT_FALSE(chf.canMovePiece(3,4,1,6, true));
    EXPECT_FALSE(chf.canMovePiece(3,4,3,3, true));
}
TEST(pieceMovementTest, whitePawnTestingFirstMove)
{
    chess::chess chf;
    chf.clearField();
    chf.createPiece(3,1,pieceWhitePawn);
    EXPECT_TRUE(chf.canMovePiece(3,1,3,2, true));
    EXPECT_TRUE(chf.canMovePiece(3,1,3,3, true));
    EXPECT_FALSE(chf.canMovePiece(3,1,3,4, true));
    EXPECT_FALSE(chf.canMovePiece(3,1,3,0, true));
    EXPECT_FALSE(chf.canMovePiece(3,1,1,4, true));
    EXPECT_FALSE(chf.canMovePiece(3,1,4,0, true));
    EXPECT_FALSE(chf.canMovePiece(3,1,4,1, true));
    EXPECT_FALSE(chf.canMovePiece(3,1,4,2, true));
    EXPECT_FALSE(chf.canMovePiece(3,1,4,3, true));
    EXPECT_FALSE(chf.canMovePiece(3,1,6,6, true));
    EXPECT_FALSE(chf.canMovePiece(3,1,7,1, true));
}
TEST(pieceMovementTest, blackPawnTestingMiddle)
{
    chess::chess chf;
    chf.clearField();
    chf.createPiece(3,4,pieceBlackPawn);
    EXPECT_TRUE(chf.canMovePiece(3,4,3,3, false));
    EXPECT_FALSE(chf.canMovePiece(3,4,1,6, false));
    EXPECT_FALSE(chf.canMovePiece(3,4,1,3, false));
    EXPECT_FALSE(chf.canMovePiece(3,4,4,4, false));
    EXPECT_FALSE(chf.canMovePiece(3,4,4,5, false));
    EXPECT_FALSE(chf.canMovePiece(3,4,3,7, false));
    EXPECT_FALSE(chf.canMovePiece(3,4,3,6, false));
    EXPECT_FALSE(chf.canMovePiece(3,4,3,5, false));
}
TEST(pieceMovementTest, blackPawnTestingFirstMove)
{
    chess::chess chf;
    chf.clearField();
    chf.createPiece(3,6,pieceBlackPawn);
    EXPECT_TRUE(chf.canMovePiece(3,6,3,4, false));
    EXPECT_TRUE(chf.canMovePiece(3,6,3,5, false));
    EXPECT_FALSE(chf.canMovePiece(3,6,3,2, false));
    EXPECT_FALSE(chf.canMovePiece(3,6,3,3, false));
    EXPECT_FALSE(chf.canMovePiece(3,6,1,4, false));
    EXPECT_FALSE(chf.canMovePiece(3,6,4,0, false));
    EXPECT_FALSE(chf.canMovePiece(3,6,4,1, false));
    EXPECT_FALSE(chf.canMovePiece(3,6,4,2, false));
    EXPECT_FALSE(chf.canMovePiece(3,6,4,3, false));
    EXPECT_FALSE(chf.canMovePiece(3,6,6,6, false));
    EXPECT_FALSE(chf.canMovePiece(3,6,7,1, false));
}
TEST(pieceMovementTest, whitePawnAccessWhitePiece)
{
    chess::chess chf;
    chf.clearField();
    chf.createPiece(4,1,pieceWhitePawn);
    chf.createPiece(4,2,pieceWhiteKnight);
    chf.createPiece(4,3,pieceWhiteKing);
    chf.createPiece(3,2,pieceBlackKnight);
    chf.createPiece(5,2,pieceBlackKnight);
    chf.createPiece(5,3,pieceBlackKnight);
    chf.createPiece(3,4,pieceWhitePawn);
    chf.createPiece(3,5,pieceWhiteKnight);
    chf.createPiece(3,6,pieceWhiteKnight);
    chf.createPiece(2,5,pieceBlackBishop);
    chf.createPiece(4,5,pieceBlackBishop);
    chf.createPiece(6,5,pieceWhitePawn);
    chf.createPiece(6,6,pieceBlackBishop);
    chf.createPiece(6,7,pieceBlackBishop);
    chf.createPiece(5,6,pieceWhiteBishop);
    chf.createPiece(7,6,pieceWhiteBishop);
    EXPECT_TRUE(chf.canMovePiece(4,1,3,2, true));
    EXPECT_TRUE(chf.canMovePiece(4,1,5,2, true));
    EXPECT_TRUE(chf.canMovePiece(3,4,2,5, true));
    EXPECT_TRUE(chf.canMovePiece(3,4,4,5, true));
    EXPECT_FALSE(chf.canMovePiece(4,1,4,2, true));
    EXPECT_FALSE(chf.canMovePiece(4,1,4,3, true));
    EXPECT_FALSE(chf.canMovePiece(4,1,5,3, true));
    EXPECT_FALSE(chf.canMovePiece(3,4,3,5, true));
    EXPECT_FALSE(chf.canMovePiece(3,4,3,6, true));
    EXPECT_FALSE(chf.canMovePiece(6,5,6,6, true));
    EXPECT_FALSE(chf.canMovePiece(6,5,6,7, true));
    EXPECT_FALSE(chf.canMovePiece(6,5,5,6, true));
    EXPECT_FALSE(chf.canMovePiece(6,5,7,6, true));
}
TEST(pieceMovementTest, testRookMovement)
{
    chess::chess chf;
    chf.clearField();
    chf.createPiece(3,2,pieceWhiteRook);
    chf.createPiece(5,5,pieceBlackRook);
    chf.createPiece(3,5,pieceWhitePawn);
    chf.createPiece(5,2,pieceBlackPawn);
    EXPECT_TRUE(chf.canMovePiece(3,2,1,2, true));
    EXPECT_TRUE(chf.canMovePiece(3,2,3,0, true));
    EXPECT_TRUE(chf.canMovePiece(3,2,5,2, true));
    EXPECT_TRUE(chf.canMovePiece(3,2,5,2, true));
    EXPECT_FALSE(chf.canMovePiece(3,2,3,2, true));
    EXPECT_FALSE(chf.canMovePiece(3,2,1,0, true));
    EXPECT_FALSE(chf.canMovePiece(3,2,1,5, true));
    EXPECT_FALSE(chf.canMovePiece(3,2,1,7, true));
    EXPECT_FALSE(chf.canMovePiece(3,2,3,5, true));
    EXPECT_FALSE(chf.canMovePiece(3,2,3,7, true));
    EXPECT_FALSE(chf.canMovePiece(3,2,6,0, true));
    EXPECT_FALSE(chf.canMovePiece(3,2,6,6, true));

    EXPECT_TRUE(chf.canMovePiece(5,5,3,5, false));
    EXPECT_TRUE(chf.canMovePiece(5,5,5,6, false));
    EXPECT_TRUE(chf.canMovePiece(5,5,6,5, false));
    EXPECT_FALSE(chf.canMovePiece(5,5,3,2, false));
    EXPECT_FALSE(chf.canMovePiece(5,5,1,0, false));
    EXPECT_FALSE(chf.canMovePiece(5,5,1,2, false));
    EXPECT_FALSE(chf.canMovePiece(5,5,1,5, false));
    EXPECT_FALSE(chf.canMovePiece(5,5,1,7, false));
    EXPECT_FALSE(chf.canMovePiece(5,5,3,0, false));
    EXPECT_FALSE(chf.canMovePiece(5,5,3,7, false));
    EXPECT_FALSE(chf.canMovePiece(5,5,6,0, false));
    EXPECT_FALSE(chf.canMovePiece(5,5,6,6, false));
    EXPECT_FALSE(chf.canMovePiece(5,5,6,2, false));
    EXPECT_FALSE(chf.canMovePiece(5,5,5,2, false));
    EXPECT_FALSE(chf.canMovePiece(5,5,5,1, false));
}
TEST(pieceMovementTest, testBishopMovement)
{
    chess::chess chf;
    chf.clearField();
    chf.createPiece(3,3,pieceWhiteBishop);
    EXPECT_TRUE(chf.canMovePiece(3,3,1,1, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,1,5, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,5,5, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,6,0, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,3,1, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,3,5, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,6,2, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,6,5, true));
}
TEST(pieceMovementTest, testKnightMovement)
{
    chess::chess chf;
    chf.clearField();
    chf.createPiece(3,3,pieceWhiteKnight);
    EXPECT_TRUE(chf.canMovePiece(3,3,1,2,true));
    EXPECT_TRUE(chf.canMovePiece(3,3,1,4, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,2,1, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,2,5, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,4,1, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,4,5, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,5,4, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,5,2, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,0,0, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,0,5, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,1,6, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,2,4, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,3,5, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,4,3, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,5,6, true));
}
TEST(pieceMovementTest, testKingMovement)
{
    chess::chess chf;
    chf.clearField();
    chf.createPiece(3,3,pieceWhiteKing);
    EXPECT_TRUE(chf.canMovePiece(3,3,2,2, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,2,3, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,2,4, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,3,4, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,3,2, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,4,2, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,4,3, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,4,4, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,0,0, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,0,3, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,2,0, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,2,5, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,3,5, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,5,7, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,6,1, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,7,6, true));
}
TEST(pieceMovementTest, testQueenMovement)
{
    chess::chess chf;
    chf.clearField();
    chf.createPiece(3,3,pieceWhiteQueen);
    EXPECT_TRUE(chf.canMovePiece(3,3,1,1, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,1,5, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,2,3, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,3,5, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,6,0, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,7,3, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,0,2, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,1,6, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,1,7, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,4,5, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,7,0, true));
}
TEST(pieceMovementTest, KingCanNotGoIntoDanger)
{
    chess::chess chf;
    chf.clearField();
    chf.createPiece(3,3,pieceWhiteKing);
    chf.createPiece(2,6,pieceBlackRook);
    EXPECT_TRUE(chf.canMovePiece(3,3,3,4, true));
    EXPECT_TRUE(chf.canMovePiece(3,3,3,2, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,2,2, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,2,3, true));
    EXPECT_FALSE(chf.canMovePiece(3,3,2,4, true));
}
TEST(pieceMovementTest, PawnCanNotGoThroughAnotherPieceOnDoubleStep)
{
    chess::chess chf;
    chf.clearField();
    chf.createPiece(3,6,pieceBlackPawn);
    chf.createPiece(3,1,pieceWhitePawn);
    chf.createPiece(3,5,pieceBlackPawn);
    chf.createPiece(3,2,pieceBlackPawn);
    EXPECT_FALSE(chf.canMovePiece(3,6,3,4, false));
    EXPECT_FALSE(chf.canMovePiece(3,1,3,3, false));
}
TEST(pieceMovementTest, BishopCanNotGoThroughOtherPieces)
{
    chess::chess chf;
    chf.clearField();
    chf.createPiece(3,4,pieceWhiteBishop);
    chf.createPiece(1,2,pieceWhitePawn);
    chf.createPiece(2,5,pieceBlackPawn);
    chf.createPiece(5,6,pieceBlackPawn);
    chf.createPiece(5,2,pieceBlackPawn);
    EXPECT_TRUE(chf.canMovePiece(3,4,4,5, true));
    EXPECT_FALSE(chf.canMovePiece(3,4,1,6, true));
    EXPECT_FALSE(chf.canMovePiece(3,4,0,7, true));
    EXPECT_FALSE(chf.canMovePiece(3,4,0,1, true));
    EXPECT_FALSE(chf.canMovePiece(3,4,6,7, true));
    EXPECT_FALSE(chf.canMovePiece(3,4,6,1, true));
    EXPECT_FALSE(chf.canMovePiece(3,4,7,0, true));
}