#include "chess.hpp"
#include "parsing.hpp"

/* private members */

/* parsing functions */
unsigned int chess::chess::getPice(unsigned int *x, unsigned int *y)
{
    return chessField[*x][*y] - getColor(x,y);
}
unsigned int chess::chess::getColor(unsigned int *x, unsigned int *y)
{
    // indicates a white pice
    if (chessField[*x][*y] > piceBlackColor)
        return piceBlackColor;
    else if (chessField[*x][*y] > piceWhiteColor)
        return piceWhiteColor;
    else
        return piceEmpty;
}
/* manipulate pices */
void chess::chess::removePice(const unsigned int *piceX, const unsigned int *piceY)
{
    // changes the pice location to 0
    chessField[*piceX][*piceY] = 0;
}
void chess::chess::addPice(const unsigned int *piceX, const unsigned int *piceY, const unsigned int *piceID)
{
    // places a piece
    chessField[*piceX][*piceY] = *piceID;
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
            chessField[i][j] = piceEmpty;
        }
    }
}
void chess::chess::initializeField()
{
    // white
    chessField[0][0] = piceWhiteRook;
    chessField[1][0] = piceWhiteKnight;
    chessField[2][0] = piceWhiteBishop;
    chessField[3][0] = piceWhiteQueen;
    chessField[4][0] = piceWhiteKing;
    chessField[5][0] = piceWhiteBishop;
    chessField[6][0] = piceWhiteKnight;
    chessField[7][0] = piceWhiteRook;
    for (int i = 0; i <= 7; ++i)
    {
        chessField[i][1] = piceWhitePawn;
    }
    // black
    chessField[0][7] = piceBlackRook;
    chessField[1][7] = piceBlackKnight;
    chessField[2][7] = piceBlackBishop;
    chessField[3][7] = piceBlackQueen;
    chessField[4][7] = piceBlackKing;
    chessField[5][7] = piceBlackBishop;
    chessField[6][7] = piceBlackKnight;
    chessField[7][7] = piceBlackRook;
    for (int i = 0; i <= 7; ++i)
    {
        chessField[i][6] = piceBlackPawn;
    }
}
void chess::chess::createPice(unsigned int locationX, unsigned int locationY, unsigned int piceId)
{
    chessField[locationX][locationY] = piceId;
}
unsigned int chess::chess::movePice(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY, bool whitesTurn)
{
    // check, if the location is on the board
    if (!onBoard(&fromX,&fromY, &toX, &toY))
        return 1;
        // check, if the pice exists on the given location
    else if (getPice(&fromX,&fromY) == piceEmpty)
        return 3;
        // check, if the destination is the same as the location
    else if (checkSameLocation(&fromX, &fromY, &toX, &toY))
        return 4;
        // checks, if the pice has the given color
    else if ((getColor(&fromX, &fromY) == piceWhiteColor && !whitesTurn) || (getColor(&fromX, &fromY) == piceBlackColor && whitesTurn))
        return 5;
        // check, if the figure can reach the destination
    else if (!canMove(&fromX, &fromY, &toX, &toY))
        return 6;
    // checks, if the destination includes a pice of the same color
    if (getPice(&toX,&toY) != piceEmpty && ((getColor(&toX,&toY) == piceWhiteColor && whitesTurn) || (getColor(&toX,&toY) == piceBlackColor && !whitesTurn)))
        return 7;
    // TODO check, if king is in check
    // TODO check, if it's checkmate
    // TODO check for patt

    // add the new figure
    // addPice(toX,toY, getPice(fromX,fromY));

    // remove the figure
    // removePice(fromX,fromY);
    // TODO remove old pice

    // (add the new danger zones)


    return 0;
}

/* pice movement checks */
bool chess::chess::canMove(unsigned int *fromX, unsigned int *fromY, unsigned int *toX, unsigned int *toY)
{
    switch (getPice(fromX,fromY))
    {
        case picePawn:
            return canPawnMove(fromX, fromY, toX, toY, createVector(fromX,toX), createVector(fromY,toY));
        case piceRook:
            return canRookMove(fromX, fromY, toX, toY, createVector(fromX,toX), createVector(fromY,toY));
        case piceBishop:
            return canBishopMove(fromX, fromY, toX, createVector(fromX,toX), createVector(fromY,toY));
        case piceKnight:
            return canKnightMove(createVector(fromX,toX), createVector(fromY,toY));
        case piceKing:
            return canKingMove(fromX,fromY,toX,toY,createVector(fromX,toX), createVector(fromY,toY));
        case piceQueen:
            return canQueenMove(fromX, fromY, toX, toY, createVector(fromX,toX), createVector(fromY,toY));
    }
    // TODO: throw runtime_error
    return 0;
}
bool chess::chess::canPawnMove(unsigned int *fromX, unsigned int *fromY, unsigned int *toX, unsigned int *toY, const signed int xVector, const signed int yVector)
{
    unsigned int toYup = *toY + 1;
    unsigned int toYdown = *toY - 1;
    return (// white pawn moving one forward
            getColor(fromX, fromY) == piceWhiteColor && yVector == 1 && xVector == 0 && getPice(toX, toY) == piceEmpty) ||
           // white Pawn moving two forward
           (getColor(fromX, fromY) == piceWhiteColor && yVector == 2 && xVector == 0 && *fromY == 1 && getPice(toX, toY) == piceEmpty &&
            getPice(toX, &toYdown) == piceEmpty) ||
           // white Pawn capturing a pice
           (getColor(fromX, fromY) == piceWhiteColor && yVector == 1 && (xVector == 1 || xVector == -1) && getPice(toX, toY) != piceEmpty && getColor(toX, toY) == piceBlackColor) ||
           // black Pawn moving one Forward
           (getColor(fromX, fromY) == piceBlackColor && yVector == -1 && xVector == 0 && getPice(toX, toY) == piceEmpty) ||
           // black Pawn moving two forward
           (getColor(fromX, fromY) == piceBlackColor && yVector == -2 && xVector == 0 && *fromY == 6 && getPice(toX, toY) == piceEmpty &&
            getPice(toX, &toYup) == piceEmpty) ||
           // black Pawn capturing a pice
           (getColor(fromX, fromY) == piceBlackColor && yVector == 1 && (xVector == 1 || xVector - 1) && getPice(toX, toY) != piceEmpty && getColor(toX, toY) == piceWhiteColor);
}
bool chess::chess::canRookMove(unsigned int *fromX, unsigned int *fromY, const unsigned int *toX, const unsigned int *toY, const signed int xVector, const signed int yVector)
{
    // right
    if (xVector > 0 && yVector == 0)
    {
        for (unsigned int i = *fromX + 1; i < *toX; ++i)
        {
            if (getPice(&i,fromY) != piceEmpty)
                return false;
        }
    }
        // left
    else if (xVector < 0 && yVector == 0)
    {
        for (unsigned int i = *toX + 1; i < *fromX; ++i)
        {
            if (getPice(&i,fromY) != piceEmpty)
                return false;
        }
    }
        // up
    else if (yVector > 0 && xVector == 0)
    {
        for (unsigned int i = *fromY +1; i < *toY; ++i)
        {
            if (getPice(fromX,&i) != piceEmpty)
                return false;
        }
    }
        // down
    else if (yVector < 0 && xVector == 0)
    {
        for (unsigned int i = *toY + 1; i < *fromY; ++i)
        {
            if (getPice(fromX,&i) != piceEmpty)
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
            if (getPice(&i,&j) != piceEmpty)
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
            if (getPice(&i,&j) != piceEmpty)
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
            if (getPice(&i,&j) != piceEmpty)
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
            if (getPice(&i,&j) != 0)
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
bool chess::chess::kingInDanger(unsigned int locationX, unsigned int locationY, unsigned int piceColor)
{
    for (unsigned int i = 0; i <= 7; ++i)
    {
        for (unsigned int j = 0; j <= 7; ++j)
        {
            if (getPice(&i,&j) != piceEmpty)
                if ((getColor(&i,&j) == piceWhiteColor && piceColor == piceBlackColor) || (getColor(&i,&j) == piceBlackColor && piceColor == piceWhiteColor))
                    if (canMove(&i, &j, &locationX, &locationY))
                        return true;
        }
    }
    return false;
}

/* pre move checks */
bool chess::chess::checkSameLocation(const unsigned int *fromX, const unsigned int *fromY, const unsigned int *toX, const unsigned int *toY)
{
    return fromX == toX && fromY == toY;
}
bool chess::chess::onBoard(const unsigned int* coordination1, const unsigned int *coordination2, const unsigned int *coordination3, const unsigned int *coordination4)
{
    return *coordination1 < 8 && *coordination2 < 8 && *coordination3 < 8 && *coordination4 < 8;
}
bool chess::chess::checkPiceExists(unsigned int pice)
{
    return pice != piceEmpty;
}
// TODO move into FOLF
signed int chess::createVector(const unsigned int *from, const unsigned int *to)
{
    return *to - *from;
}
