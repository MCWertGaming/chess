// chess source file
// provides the source for the chess back-end
// by MCWertGaming
#include "chess.hpp"

/* private members */

/* parsing functions */
unsigned int chess::chessField::getPice(unsigned int *x, unsigned int *y)
{
    return field[*y][*x] - getOverload(x,y) - getColor(x,y);
}
unsigned int chess::chessField::getColor(unsigned int *x, unsigned int *y)
{
    // indicates a white character
    if (field[*y][*x] - getOverload(x,y) > 10)
        return 10;
    else
        return 0;
}
unsigned int chess::chessField::getOverload(const unsigned int *x, const unsigned int *y)
{
    // TODO En passong
    if (field[*y][*x] > 100)
        return 100;
    else
        return 0;
}

/* manipulate pices */
void chess::chessField::removePice(const unsigned int *piceX, const unsigned int *piceY)
{
    // changes the pice location to 0
    field[*piceY][*piceX] = 0;
}
void chess::chessField::addPice(const unsigned int *piceX, const unsigned int *piceY, const unsigned int *piceID)
{
    // places the new
    field[*piceY][*piceX] = *piceID;
}

/* game status checks */
//TODO FINISH
/*
bool chess::chessField::checkMate(unsigned int *kingX, unsigned int *kingY)
{
    // TODO dont check king movement, if it's not on the board
    // check, if the king is in check
    if (kingInDanger(*kingX,*kingY,getColor(kingX,kingY)))
        // check, if the king can move
        if (kingInDanger(*kingX-1,*kingY-1,getColor(kingX,kingY)))
            if (kingInDanger(*kingX-1,*kingY,getColor(kingX,kingY)))
                if (kingInDanger(*kingX-1,*kingY+1,getColor(kingX,kingY)))
                    if (kingInDanger(*kingX,*kingY-1,getColor(kingX,kingY)))
                        if (kingInDanger(*kingX,*kingY+1,getColor(kingX,kingY)))
                            if (kingInDanger(*kingX+1,*kingY-1,getColor(kingX,kingY)))
                                if (kingInDanger(*kingX+1,*kingY,getColor(kingX,kingY)))
                                    if (kingInDanger(*kingX+1,*kingY+1,getColor(kingX,kingY)))
                                    {
                                        for (unsigned int enemyY = 0; enemyY <= 7; ++enemyY)
                                        {
                                            for (unsigned int enemyX = 0; enemyX <= 7; ++enemyX)
                                            {
                                                if (getColor(&enemyX, &enemyY) != getColor(kingX, kingY) &&
                                                    canMove(&enemyX, &enemyY, kingX, kingY))
                                                {
                                                    int xVector = createVector(&enemyX,kingX);
                                                    int yVector = createVector(&enemyY,kingY);
                                                    // check if it's a pawn or a Knight
                                                    if (getPice(&enemyX,&enemyY) == 1 || getPice(&enemyX,&enemyY) == 4)
                                                    {
                                                        // check, if a figure can capture it
                                                        for (unsigned int liveSaverY = 0; liveSaverY <= 7; ++liveSaverY)
                                                        {
                                                            for (unsigned int liveSaverX = 0; liveSaverX <= 7; ++liveSaverX)
                                                            {
                                                                if (getPice(&liveSaverY, &liveSaverX) != 0 &&
                                                                    getColor(&liveSaverY, &liveSaverX) == getColor(kingX, kingY) &&
                                                                    canMove(&liveSaverY, &liveSaverX, kingX, kingY))
                                                                    // pice can be captured, so it's not checkmate yet
                                                                    return false;
                                                            }
                                                        }
                                                        return true;
                                                    }
                                                    else if (enemyY < *kingY && xVector == 0)
                                                    {
                                                        // moving straigt up
                                                        for (unsigned int liveSaverY = 0; liveSaverY <= 7; ++liveSaverY)
                                                        {
                                                            for (unsigned int liveSaverX = 0; liveSaverX <= 7; ++liveSaverX)
                                                            {
                                                                if (getPice(&liveSaverX,&liveSaverY) != 0 &&
                                                                    getColor(&liveSaverX,&liveSaverY) == getColor(kingX,kingY))
                                                                    for (unsigned int i = enemyY + 1; i < *kingY; ++i)
                                                                    {
                                                                        if (canMove(&liveSaverX,&liveSaverY,kingX,&i))
                                                                            return false;
                                                                    }
                                                            }
                                                        }
                                                        return true;
                                                    }
                                                    else if (enemyY > *kingY && xVector == 0)
                                                    {
                                                        // down
                                                        for (unsigned int liveSaverY = 0;
                                                             liveSaverY <= 7; ++liveSaverY)
                                                        {
                                                            for (unsigned int liveSaverX = 0;
                                                                 liveSaverX <= 7; ++liveSaverX)
                                                            {
                                                                if (getPice(&liveSaverX, &liveSaverY) != 0 &&
                                                                    getColor(&liveSaverX, &liveSaverY) == getColor(kingX, kingY))
                                                                    for (unsigned int i = *kingY + 1; i < enemyY; ++i)
                                                                    {
                                                                        if (canMove(&liveSaverX, &liveSaverY, kingX,&i))
                                                                            return false;
                                                                    }
                                                            }
                                                        }
                                                        return true;
                                                    }
                                                    else if (enemyX < *kingX && yVector == 0)
                                                    {
                                                        // right
                                                        for (unsigned int liveSaverY = 0;
                                                             liveSaverY <= 7; ++liveSaverY)
                                                        {
                                                            for (unsigned int liveSaverX = 0;
                                                                 liveSaverX <= 7; ++liveSaverX)
                                                            {
                                                                if (getPice(&liveSaverX, &liveSaverY) != 0 &&
                                                                    getColor(&liveSaverX, &liveSaverY) == getColor(kingX,kingY))
                                                                    for (unsigned int i = enemyX + 1; i < *kingX; ++i)
                                                                    {
                                                                        if (canMove(&liveSaverX, &liveSaverY, kingX,&i))
                                                                            return false;
                                                                    }
                                                            }
                                                        }
                                                        return true;
                                                    }
                                                    else if (yVector == 0 && xVector < 0)
                                                    {
                                                        // left
                                                        for (unsigned int liveSaverY = 0;
                                                             liveSaverY <= 7; ++liveSaverY)
                                                        {
                                                            for (unsigned int liveSaverX = 0;
                                                                 liveSaverX <= 7; ++liveSaverX)
                                                            {
                                                                if (getPice(&liveSaverX, &liveSaverY) != 0 &&
                                                                    getColor(&liveSaverX, &liveSaverY) == getColor(kingX,kingY))
                                                                    for (unsigned int i = enemyX + 1; i < *kingX; ++i)
                                                                    {
                                                                        if (canMove(&liveSaverX, &liveSaverY, kingX,&i))
                                                                            return false;
                                                                    }
                                                            }
                                                        }
                                                        return true;
                                                    }
                                                    else if ()
                                                        // diagonal ++
                                                        return true;
                                                    else if ()
                                                        // diagonal +-
                                                        return true;
                                                    else if ()
                                                        // diagonal -+
                                                        return true;
                                                    else if ()
                                                        // diagonal --
                                                        return true;
                                                    else
                                                        // error ======
                                                        return true;
                                                }
                                            }
                                        }
                                    }
    return false;
}
*/

/* public members */

chess::chessField::chessField()
{
    clearField();
}

/* game manipulation */
void chess::chessField::clearField()
{
    for (int i = 0; i <= 7; ++i)
    {
        for (int j = 0; j <= 7; ++j)
        {
            field[i][j] = 0;
        }
    }
}
void chess::chessField::initializeField()
{
    // white
    field[0][0] = pice::whiteRook();
    field[0][1] = pice::whiteKnight();
    field[0][2] = pice::whiteBishop();
    field[0][3] = pice::whiteQueen();
    field[0][4] = pice::whiteKing();
    field[0][5] = pice::whiteBishop();
    field[0][6] = pice::whiteKnight();
    field[0][7] = pice::whiteRook();
    for (int i = 0; i <= 7; ++i)
    {
        field[1][i] = pice::whitePawn();
    }
    // black
    field[7][0] = pice::blackRook();
    field[7][1] = pice::blackKnight();
    field[7][2] = pice::blackBishop();
    field[7][3] = pice::blackQueen();
    field[7][4] = pice::blackKing();
    field[7][5] = pice::blackBishop();
    field[7][6] = pice::blackKnight();
    field[7][7] = pice::blackRook();
    for (int i = 0; i <= 7; ++i)
    {
        field[6][i] = pice::blackPawn();
    }
}
void chess::chessField::createPice(unsigned int locationX, unsigned int locationY, unsigned int piceId)
{
    field[locationY][locationX] = piceId;
}
unsigned int chess::chessField::movePice(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY, bool whitesTurn)
{
    // check, if the location is on the board
    if (!onBoard(&fromX,&fromY, &toX, &toY))
        return 1;
        // check, if the pice exists on the given location
    else if (getPice(&fromX,&fromY) == 0)
        return 3;
        // check, if the destination is the same as the location
    else if (checkSameLocation(&fromX, &fromY, &toX, &toY))
        return 4;
        // checks, if the pice has the given color
    else if (getColor(&fromX, &fromY) == 10 && !whitesTurn || getColor(&fromX, &fromY) == 0 && whitesTurn)
        return 5;
        // check, if the figure can reach the destination
    else if (!canMove(&fromX, &fromY, &toX, &toY))
        return 6;
    // checks, if the destination includes a pice of the same color
    if (getPice(&toX,&toY) != 0 && (getColor(&toX,&toY) == 10 && whitesTurn || getColor(&toX,&toY) == 0 && !whitesTurn))
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

// TODO is this needed?
unsigned int chess::chessField::getField(const unsigned int *locationX, const unsigned int *locationY)
{
    return field[*locationX][*locationY];
}

/* pice movement checks */
bool chess::chessField::canMove(unsigned int *fromX, unsigned int *fromY, unsigned int *toX, unsigned int *toY)
{
    switch (getPice(fromX,fromY))
    {
        case 1:
            return canPawnMove(fromX, fromY, toX, toY, createVector(fromX,toX), createVector(fromY,toY));
        case 2:
            return canRookMove(fromX, fromY, toX, toY, createVector(fromX,toX), createVector(fromY,toY));
        case 3:
            return canBishopMove(fromX, fromY, toX, createVector(fromX,toX), createVector(fromY,toY));
        case 4:
            return canKnightMove(createVector(fromX,toX), createVector(fromY,toY));
        case 5:
            return canKingMove(fromX,fromY,toX,toY,createVector(fromX,toX), createVector(fromY,toY));
        case 6:
            return canQueenMove(fromX, fromY, toX, toY, createVector(fromX,toX), createVector(fromY,toY));
    }
}
bool chess::chessField::canPawnMove(unsigned int *fromX, unsigned int *fromY, unsigned int *toX, unsigned int *toY, const signed int xVector, const signed int yVector)
{
    unsigned int toYup = *toY + 1;
    unsigned int toYdown = *toY - 1;
    return (// white pawn moving one forward
                   getColor(fromX, fromY) == 10 && yVector == 1 && xVector == 0 && getPice(toX, toY) == 0) ||
           // white Pawn moving two forward
           (getColor(fromX, fromY) == 10 && yVector == 2 && xVector == 0 && *fromY == 1 && getPice(toX, toY) == 0 &&
            getPice(toX, &toYdown) == 0) ||
           // white Pawn capturing a pice
           (getColor(fromX, fromY) == 10 && yVector == 1 && (xVector == 1 || xVector == -1) && getPice(toX, toY)) ||
           // black Pawn moving one Forward
           (getColor(fromX, fromY) == 0 && yVector == -1 && xVector == 0 && getPice(toX, toY) == 0) ||
           // black Pawn moving two forward
           (getColor(fromX, fromY) == 0 && yVector == -2 && xVector == 0 && *fromY == 6 && getPice(toX, toY) == 0 &&
            getPice(toX, &toYup) == 0) ||
           // black Pawn capturing a pice
           (getColor(fromX, fromY) == 0 && yVector == 1 && (xVector == 1 || xVector - 1) && getPice(toX, toY) != 0);
}
bool chess::chessField::canRookMove(unsigned int *fromX, unsigned int *fromY, const unsigned int *toX, const unsigned int *toY, const signed int xVector, const signed int yVector)
{
    // right
    if (xVector > 0 && yVector == 0)
    {
        for (unsigned int i = *fromX + 1; i < *toX; ++i)
        {
            if (getPice(&i,fromY) != 0)
                return false;
        }
    }
        // left
    else if (xVector < 0 && yVector == 0)
    {
        for (unsigned int i = *toX + 1; i < *fromX; ++i)
        {
            if (getPice(&i,fromY) != 0)
                return false;
        }
    }
        // up
    else if (yVector > 0 && xVector == 0)
    {
        for (unsigned int i = *fromY +1; i < *toY; ++i)
        {
            if (getPice(&i,fromX) != 0)
                return false;
        }
    }
        // down
    else if (yVector < 0 && xVector == 0)
    {
        for (unsigned int i = *toY + 1; i < *fromY; ++i)
        {
            if (getPice(&i,fromX) != 0)
                return false;
        }
    }
    else
        return false;
    return true;
}
bool chess::chessField::canBishopMove(const unsigned int *fromX, const unsigned int *fromY, const unsigned int *toX, const signed int xVector, const signed int yVector)
{
    // vector of +/+
    if (xVector == yVector && xVector > 0)
    {
        unsigned int j = *fromY +1;
        for (unsigned int i = *fromX +1; i < *toX; ++i)
        {
            if (getPice(&i,&j) != 0)
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
            if (getPice(&i,&j) != 0)
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
            if (getPice(&i,&j) != 0)
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
bool chess::chessField::canKnightMove(const signed int xVector, const signed int yVector)
{
    return (// move knight two forward and one to the side
                   (xVector == 2 || xVector == -2) && (yVector == 1 || yVector == -1)) ||
           ((yVector == 2 || yVector == -2) && (xVector == 1 || xVector == -1));
}
bool chess::chessField::canKingMove(unsigned int *fromX, unsigned int *fromY, const unsigned int *toX, const unsigned int *toY, signed int xVector, signed int yVector)
{
    // move king
    return (yVector == 0 || yVector == 1 || yVector == -1) && (xVector == 0 || xVector == 1 || xVector == -1) &&
           !kingInDanger(*toX, *toY, getColor(fromX, fromY));
}
bool chess::chessField::canQueenMove(unsigned int* fromX, unsigned int *fromY, unsigned int *toX, unsigned int *toY, signed int xVector, signed int yVector)
{
    // simply moves like Bishop (diagonal) or Rook (vertical)
    return canBishopMove(fromX, fromY, toX, xVector, yVector) || canRookMove(fromX, fromY, toX, toY, xVector, yVector);
}
bool chess::chessField::kingInDanger(unsigned int locationX, unsigned int locationY, unsigned int piceColor)
{
    for (unsigned int i = 0; i <= 7; ++i)
    {
        for (unsigned int j = 0; j <= 7; ++j)
        {
            if (getPice(&i,&j) != 0)
                if (getColor(&i,&j) == 10 && piceColor == 0 || getColor(&i,&j) == 0 && piceColor == 10)
                    if (canMove(&i, &j, &locationX, &locationY))
                        return true;
        }
    }
    return false;
}

/* pre move checks */
bool chess::chessField::checkSameLocation(const unsigned int *fromX, const unsigned int *fromY, const unsigned int *toX, const unsigned int *toY)
{
    return fromX == toX && fromY == toY;
}
bool chess::chessField::onBoard(const unsigned int* coordination1, const unsigned int *coordination2, const unsigned int *coordination3, const unsigned int *coordination4)
{
    return *coordination1 < 8 && *coordination2 < 8 && *coordination3 < 8 && *coordination4 < 8;
}
bool chess::chessField::checkPiceExists(unsigned int pice)
{
    return pice != 0;
}
