#include <gtest/gtest.h>
#include <chess/chess.hpp>
#include <chess/parsing.hpp>

TEST(gameTesting, initialState)
{
    chess::chess chessObj;
    chessObj.clearField();
    chessObj.initializeField();

    EXPECT_EQ(chessObj.getField(0,0), pieceWhiteRook);
    EXPECT_EQ(chessObj.getField(1,0), pieceWhiteKnight);
    EXPECT_EQ(chessObj.getField(2,0), pieceWhiteBishop);
    EXPECT_EQ(chessObj.getField(3,0), pieceWhiteKing);
    EXPECT_EQ(chessObj.getField(4,0), pieceWhiteQueen);
    EXPECT_EQ(chessObj.getField(5,0), pieceWhiteBishop);
    EXPECT_EQ(chessObj.getField(6,0), pieceWhiteKnight);
    EXPECT_EQ(chessObj.getField(7,0), pieceWhiteRook);
    
    EXPECT_EQ(chessObj.getField(0,1), pieceWhitePawn);
    EXPECT_EQ(chessObj.getField(1,1), pieceWhitePawn);
    EXPECT_EQ(chessObj.getField(2,1), pieceWhitePawn);
    EXPECT_EQ(chessObj.getField(3,1), pieceWhitePawn);
    EXPECT_EQ(chessObj.getField(4,1), pieceWhitePawn);
    EXPECT_EQ(chessObj.getField(5,1), pieceWhitePawn);
    EXPECT_EQ(chessObj.getField(6,1), pieceWhitePawn);
    EXPECT_EQ(chessObj.getField(7,1), pieceWhitePawn);

    EXPECT_EQ(chessObj.getField(0,7), pieceBlackRook);
    EXPECT_EQ(chessObj.getField(1,7), pieceBlackKnight);
    EXPECT_EQ(chessObj.getField(2,7), pieceBlackBishop);
    EXPECT_EQ(chessObj.getField(3,7), pieceBlackKing);
    EXPECT_EQ(chessObj.getField(4,7), pieceBlackQueen);
    EXPECT_EQ(chessObj.getField(5,7), pieceBlackBishop);
    EXPECT_EQ(chessObj.getField(6,7), pieceBlackKnight);
    EXPECT_EQ(chessObj.getField(7,7), pieceBlackRook);
    
    EXPECT_EQ(chessObj.getField(0,6), pieceBlackPawn);
    EXPECT_EQ(chessObj.getField(1,6), pieceBlackPawn);
    EXPECT_EQ(chessObj.getField(2,6), pieceBlackPawn);
    EXPECT_EQ(chessObj.getField(3,6), pieceBlackPawn);
    EXPECT_EQ(chessObj.getField(4,6), pieceBlackPawn);
    EXPECT_EQ(chessObj.getField(5,6), pieceBlackPawn);
    EXPECT_EQ(chessObj.getField(6,6), pieceBlackPawn);
    EXPECT_EQ(chessObj.getField(7,6), pieceBlackPawn);
}

TEST(gameTesting, foolsMate)
{
    chess::chess chessObj;
    chessObj.clearField();
    chessObj.initializeField();

    // f2 - f3
    //chessObj.movePiece()

}