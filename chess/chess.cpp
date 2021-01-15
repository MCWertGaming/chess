#include "chess.hpp"
#include "parsing.hpp"
#include <stdexcept>

// TODO move to FOLF
#define createVector(from,to) to - from

/* private members */

/* parsing functions */
unsigned int chess::chess::getPiece(unsigned int *x, unsigned int *y)
{
    if (chessField[*x][*y] - getColor(x,y) < 7)
        return chessField[*x][*y] - getColor(x,y);
    else
        std::runtime_error("Illegal piece value inside chess::chess::chessField[][] found!");
    return 0; // compiler dummy
}
unsigned int chess::chess::getColor(unsigned int *x, unsigned int *y)
{
    if (chessField[*x][*y] < 27 &&
        chessField[*x][*y] > pieceBlackColor)
        return pieceBlackColor;
    else if (chessField[*x][*y] < 17 &&
             chessField[*x][*y] > pieceWhiteColor)
        return pieceWhiteColor;
    else if (chessField[*x][*y] == pieceEmpty)
        return pieceEmpty;
    else
        std::runtime_error("Illegal color value inside chess::chess::chessField[][] found!");
    return 0; // compiler dummy
}
/* manipulate pieces */
void chess::chess::removePiece(const unsigned int *pieceX, const unsigned int *pieceY)
{
    // changes the piece location to 0
    chessField[*pieceX][*pieceY] = 0;
}
void chess::chess::addPiece(const unsigned int *pieceX, const unsigned int *pieceY, const unsigned int *pieceID)
{
    // places a piece
    chessField[*pieceX][*pieceY] = *pieceID;
}
// TODO
// bool chess::chess::checkMate(unsigned int *kingX, unsigned int *kingY)
// {
//     return true;
// }

/* public members */

chess::chess::chess()
{
    clearField();
}

/* game manipulation */
void chess::chess::clearField()
{
    for (int i = 0; i <= 7; ++i)
    {
        for (int j = 0; j <= 7; ++j)
        {
            chessField[i][j] = pieceEmpty;
        }
    }
}
void chess::chess::initializeField()
{
    // white
    chessField[0][0] = pieceWhiteRook;
    chessField[1][0] = pieceWhiteKnight;
    chessField[2][0] = pieceWhiteBishop;
    chessField[3][0] = pieceWhiteQueen;
    chessField[4][0] = pieceWhiteKing;
    chessField[5][0] = pieceWhiteBishop;
    chessField[6][0] = pieceWhiteKnight;
    chessField[7][0] = pieceWhiteRook;
    for (int i = 0; i <= 7; ++i)
    {
        chessField[i][1] = pieceWhitePawn;
    }
    // black
    chessField[0][7] = pieceBlackRook;
    chessField[1][7] = pieceBlackKnight;
    chessField[2][7] = pieceBlackBishop;
    chessField[3][7] = pieceBlackQueen;
    chessField[4][7] = pieceBlackKing;
    chessField[5][7] = pieceBlackBishop;
    chessField[6][7] = pieceBlackKnight;
    chessField[7][7] = pieceBlackRook;
    for (int i = 0; i <= 7; ++i)
    {
        chessField[i][6] = pieceBlackPawn;
    }
}
void chess::chess::createPiece(unsigned int locationX, unsigned int locationY, unsigned int pieceId)
{
    chessField[locationX][locationY] = pieceId;
}
unsigned int chess::chess::movePiece(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY, bool whitesTurn)
{

    // pre move checks
    // check for invalid input to avoid segmentation fault
    if (!onBoard(&fromX, &fromY, &toX, &toY))
        return 1;
    if (!preMoveChecks(&fromX, &fromY, &toX, &toY, getColor(&fromX, &fromY), getColor(&toX, &toY), &whitesTurn))
        return 2;
        // actual check, if the movement is legal
    else if (!canMove(&fromX, &fromY, &toX, &toY))
        return 3;
    // TODO check, if king is in check
    // TODO check, if it's checkmate
    // TODO check for stalemate

    // add the new figure
    // addPiece(toX,toY, getPiece(fromX,fromY));

    // remove the figure
    // removePiece(fromX,fromY);
    // TODO remove old piece

    // (add the new danger zones)


    return 0;
}
bool chess::chess::canMovePiece(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY, bool whitesTurn)
{
    // pre move checks
    // check for invalid input to avoid segmentation fault
    if (!onBoard(&fromX, &fromY, &toX, &toY))
        return false;
    if (!preMoveChecks(&fromX, &fromY, &toX, &toY, getColor(&fromX, &fromY), getColor(&toX, &toY), &whitesTurn))
        return false;
        // actual check, if the movement is legal
    else if (!canMove(&fromX, &fromY, &toX, &toY))
        return false;
    
    // figure would move
    return true;
}

/* piece movement checks */
bool chess::chess::canMove(unsigned int *fromX, unsigned int *fromY, unsigned int *toX, unsigned int *toY)
{
    switch (getPiece(fromX,fromY))
    {
        case piecePawn:
            return canPawnMove(fromX, fromY, toX, toY, createVector(*fromX,*toX), createVector(*fromY,*toY));
        case pieceRook:
            return canRookMove(fromX, fromY, toX, toY, createVector(*fromX,*toX), createVector(*fromY,*toY));
        case pieceBishop:
            return canBishopMove(fromX, fromY, toX, createVector(*fromX,*toX), createVector(*fromY,*toY));
        case pieceKnight:
            return canKnightMove(createVector(*fromX,*toX), createVector(*fromY,*toY));
        case pieceKing:
            return canKingMove(fromX,fromY,toX,toY,createVector(*fromX,*toX), createVector(*fromY,*toY));
        case pieceQueen:
            return canQueenMove(fromX, fromY, toX, toY, createVector(*fromX,*toX), createVector(*fromY,*toY));
        default:
            std::runtime_error("chess::chess::getPiece() returned an illegal value!");
    }
    return 0; // compiler dummy
}
bool chess::chess::canPawnMove(unsigned int *fromX, unsigned int *fromY, unsigned int *toX, unsigned int *toY, const signed int xVector, const signed int yVector)
{
    unsigned int toYup = *toY + 1;
    unsigned int toYdown = *toY - 1;
    return (// white pawn moving one forward
            getColor(fromX, fromY) == pieceWhiteColor && yVector == 1 && xVector == 0 && getPiece(toX, toY) == pieceEmpty) ||
           // white Pawn moving two forward
           (getColor(fromX, fromY) == pieceWhiteColor && yVector == 2 && xVector == 0 && *fromY == 1 && getPiece(toX, toY) == pieceEmpty &&
            getPiece(toX, &toYdown) == pieceEmpty) ||
           // white Pawn capturing a piece
           (getColor(fromX, fromY) == pieceWhiteColor && yVector == 1 && (xVector == 1 || xVector == -1) && getPiece(toX, toY) != pieceEmpty && getColor(toX, toY) == pieceBlackColor) ||
           // black Pawn moving one Forward
           (getColor(fromX, fromY) == pieceBlackColor && yVector == -1 && xVector == 0 && getPiece(toX, toY) == pieceEmpty) ||
           // black Pawn moving two forward
           (getColor(fromX, fromY) == pieceBlackColor && yVector == -2 && xVector == 0 && *fromY == 6 && getPiece(toX, toY) == pieceEmpty &&
            getPiece(toX, &toYup) == pieceEmpty) ||
           // black Pawn capturing a piece
           (getColor(fromX, fromY) == pieceBlackColor && yVector == 1 && (xVector == 1 || xVector - 1) && getPiece(toX, toY) != pieceEmpty && getColor(toX, toY) == pieceWhiteColor);
}
bool chess::chess::canRookMove(unsigned int *fromX, unsigned int *fromY, const unsigned int *toX, const unsigned int *toY, const signed int xVector, const signed int yVector)
{
    // right
    if (xVector > 0 && yVector == 0)
    {
        for (unsigned int i = *fromX + 1; i < *toX; ++i)
        {
            if (getPiece(&i,fromY) != pieceEmpty)
                return false;
        }
    }
        // left
    else if (xVector < 0 && yVector == 0)
    {
        for (unsigned int i = *toX + 1; i < *fromX; ++i)
        {
            if (getPiece(&i,fromY) != pieceEmpty)
                return false;
        }
    }
        // up
    else if (yVector > 0 && xVector == 0)
    {
        for (unsigned int i = *fromY +1; i < *toY; ++i)
        {
            if (getPiece(fromX,&i) != pieceEmpty)
                return false;
        }
    }
        // down
    else if (yVector < 0 && xVector == 0)
    {
        for (unsigned int i = *toY + 1; i < *fromY; ++i)
        {
            if (getPiece(fromX,&i) != pieceEmpty)
                return false;
        }
    }
    else
        return false;
    return true;
}
bool chess::chess::canBishopMove(const unsigned int *fromX, const unsigned int *fromY, const unsigned int *toX, const signed int xVector, const signed int yVector)
{
    // vector of +/+
    if (xVector == yVector && xVector > 0)
    {
        unsigned int j = *fromY +1;
        for (unsigned int i = *fromX +1; i < *toX; ++i)
        {
            if (getPiece(&i,&j) != pieceEmpty)
                return false;
            j++;
        }
        return true;
    }
        // vector of -/-
    else if (xVector == yVector && xVector < 0)
    {
        unsigned int j = *fromY - 1;
        for (unsigned int i = *fromX - 1; i > *toX; --i)
        {
            if (getPiece(&i,&j) != pieceEmpty)
                return false;
            j--;
        }
        return true;
    }
        // vector of +/-
    else if (-xVector == yVector && xVector > 0)
    {
        unsigned int j = *fromY -1;
        for (unsigned int i = *fromX +1; i < *toX; ++i)
        {
            if (getPiece(&i,&j) != pieceEmpty)
                return false;
            j--;
        }
        return true;
    }
        // vector of -/+
    else if (-xVector == yVector && xVector < 0)
    {
        unsigned int j = *fromY +1;
        for (unsigned int i = *fromX -1; i > *toX; --i)
        {
            if (getPiece(&i,&j) != 0)
                return false;
            j++;
        }
        return true;
    }
    else
        return false;
}
bool chess::chess::canKnightMove(const signed int xVector, const signed int yVector)
{
    return (// move knight two forward and one to the side
                   (xVector == 2 || xVector == -2) && (yVector == 1 || yVector == -1)) ||
           ((yVector == 2 || yVector == -2) && (xVector == 1 || xVector == -1));
}
bool chess::chess::canKingMove(unsigned int *fromX, unsigned int *fromY, const unsigned int *toX, const unsigned int *toY, signed int xVector, signed int yVector)
{
    // move king
    return (yVector == 0 || yVector == 1 || yVector == -1) && (xVector == 0 || xVector == 1 || xVector == -1) &&
           !kingInDanger(*toX, *toY, getColor(fromX, fromY));
}
bool chess::chess::canQueenMove(unsigned int* fromX, unsigned int *fromY, unsigned int *toX, unsigned int *toY, signed int xVector, signed int yVector)
{
    // simply moves like Bishop (diagonal) or Rook (vertical)
    return canBishopMove(fromX, fromY, toX, xVector, yVector) || canRookMove(fromX, fromY, toX, toY, xVector, yVector);
}
bool chess::chess::kingInDanger(unsigned int locationX, unsigned int locationY, unsigned int pieceColor)
{
    for (unsigned int i = 0; i <= 7; ++i)
    {
        for (unsigned int j = 0; j <= 7; ++j)
        {
            if (getPiece(&i,&j) != pieceEmpty)
                if ((getColor(&i,&j) == pieceWhiteColor && pieceColor == pieceBlackColor) || (getColor(&i,&j) == pieceBlackColor && pieceColor == pieceWhiteColor))
                    if (canMove(&i, &j, &locationX, &locationY))
                        return true;
        }
    }
    return false;
}

/* pre move checks */

bool chess::preMoveChecks(const unsigned int* fromX, const unsigned int* fromY, const unsigned int* toX, const unsigned int* toY, const unsigned int colorFrom, const unsigned int colorTo, const bool* whitesTurn)
{
    return checkPieceExists(&colorFrom) &&
           !checkSameLocation(fromX, fromY, toX, toY) &&
           checkRightColor(&colorFrom, whitesTurn) &&
           !checkCaptureTeam(&colorTo, whitesTurn);
}
bool chess::checkSameLocation(const unsigned int *fromX, const unsigned int *fromY, const unsigned int *toX, const unsigned int *toY)
{
    return fromX == toX && fromY == toY;
}
bool chess::onBoard(const unsigned int* coordination1, const unsigned int *coordination2, const unsigned int *coordination3, const unsigned int *coordination4)
{
    return *coordination1 < 8 &&
           *coordination2 < 8 &&
           *coordination3 < 8 &&
           *coordination4 < 8;
}
bool chess::checkPieceExists(const unsigned int* colorFrom)
{
    return *colorFrom != pieceEmpty;
}
bool chess::checkRightColor(const unsigned int*colorFrom, const bool *whitesTurn)
{
    return (*colorFrom == pieceWhiteColor && *whitesTurn) ||
           (*colorFrom == pieceBlackColor && !*whitesTurn);
}
bool chess::checkCaptureTeam(const unsigned int* colorDestination, const bool *whitesTurn)
{
    return *colorDestination != pieceEmpty &&
           ((*colorDestination == pieceWhiteColor && *whitesTurn) ||
           (*colorDestination == pieceBlackColor && !*whitesTurn));
}
