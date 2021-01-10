//
// Created by MCWertGaming on 21.07.2020.
//
#pragma once
#include <iostream>

class chessField
{
private:
    // provides the field - field[Y][X]
    unsigned int field[8][8]{};
public:
    chessField();
    ~chessField() = default;

    // create the blank field
    void clearField();
    // initializes the field for a new game
    void initializeField();
    // creates a new piece
    void createPiece(unsigned int, unsigned int, unsigned int pieceID);
    // returns the field
    unsigned int getField(unsigned int, unsigned int);

    // move piece
    unsigned int movePiece(unsigned int, unsigned int, unsigned int, unsigned int, bool);
    // removes piece
    void removePiece(unsigned int, unsigned int);
    // adds piece
    void addPiece(unsigned int, unsigned int, unsigned int);


    // return's how dangerous the field is
    unsigned int isDangerous(unsigned int, unsigned int);
    // returns the overload of the piece
    unsigned int getOverload(unsigned int, unsigned int);
    // returns true, if the piece is white
    unsigned int getColor(unsigned int, unsigned int);
    // returns the piece number
    unsigned int getPiece(unsigned int, unsigned int);

    // returns true, if the piece can move to the destination
    bool canMove(unsigned int, unsigned int, unsigned int, unsigned int);

};
chessField::chessField()
{
    // clears the field array
    for (int i = 0; i <= 7; ++i)
    {
        for (int j = 0; j <= 7; ++j)
        {
            field[i][j] = 0;
        }
    }
}

void chessField::clearField()
{
    for (int i = 0; i <= 7; ++i)
    {
        for (int j = 0; j <= 7; ++j)
        {
            field[i][j] = 0;
        }
    }
}
void chessField::initializeField()
{
    // white
    field[0][0] = 12;
    field[0][1] = 14;
    field[0][2] = 13;
    field[0][3] = 16;
    field[0][4] = 15;
    field[0][5] = 13;
    field[0][6] = 14;
    field[0][7] = 12;
    for (int i = 0; i <= 7; ++i)
    {
        field[1][i] = 11;
    }
    // black
    field[7][0] = 2;
    field[7][1] = 4;
    field[7][2] = 3;
    field[7][3] = 6;
    field[7][4] = 5;
    field[7][5] = 3;
    field[7][6] = 4;
    field[7][7] = 2;
    for (int i = 0; i <= 7; ++i)
    {
        field[6][i] = 1;
    }
}

void chessField::createPiece(unsigned int locationX, unsigned int locationY, unsigned int pieceID)
{
    field[locationY][locationX] = pieceID;
}

unsigned int chessField::getField(unsigned int locationX, unsigned int locationY)
{
    return field[locationX][locationY];
}

unsigned int chessField::isDangerous(unsigned int x, unsigned int y)
{
    if (field[y][x] > 4000)
        return 4000;
    else if (field[y][x] > 3000)
        return 3000;
    else if (field[y][x] > 2000)
        return 2000;
    else if (field[y][x] > 1000)
        return 1000;
    else
        return 0;
}
unsigned int chessField::getOverload(unsigned int x, unsigned int y)
{
    unsigned int fieldValue = field[y][x] - isDangerous(x,y);
    if (fieldValue > 300)
        return 300;
    else if (fieldValue > 200)
        return 200;
    else if (fieldValue > 100)
        return 100;
    else
        return 0;
}
unsigned int chessField::getColor(unsigned int x, unsigned int y)
{
    unsigned int fieldValue = field[y][x] - isDangerous(x,y) - getOverload(x,y);
    if (fieldValue > 10)
        return 10;
    else
        return 0;
}
unsigned int chessField::getPiece(unsigned int x, unsigned int y)
{
    return field[y][x] - isDangerous(x,y) - getOverload(x,y) - getColor(x,y);
}

bool chessField::canMove(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY)
{
    // calculate vectors
    signed int xVector = toX - fromX;
    signed int yVector = toY - fromY;

    // saves the piece ID
    unsigned int piece = getPiece(fromX,fromY);

    switch (piece)
    {
        case 1:
            // white Pawn moving one Forward
            if (getColor(fromX,fromY) == 10 && yVector == 1 && xVector == 0 && getPiece(toX,toY) == 0)
                return true;
                // std::cout << "test5\n";
            // white Pawn moving two forward
            else if (getColor(fromX,fromY) == 10 && yVector == 2 && xVector == 0 && fromY == 1 && getPiece(toX,toY) == 0)
                return true;
                // std::cout << "test4\n";
            // white Pawn capturing a piece
            else if (getColor(fromX,fromY) == 10 && yVector == 1 && (xVector == 1 || xVector == -1) && getPiece(toX,toY) != 0)
                return true;
                // std::cout << "test1\n";
            // black Pawn moving one Forward
            else if (getColor(fromX,fromY) == 0 && yVector == -1 && xVector == 0 && getPiece(toX,toY) == 0)
                return true;
                // std::cout << "test2\n";
            // black Pawn moving two forward
            else if (getColor(fromX,fromY) == 0 && yVector == -2 && xVector == 0 && fromY == 6 && getPiece(toX,toY) == 0)
                return true;
                // std::cout << "test3\n";
                // black Pawn capturing a piece
            else if (getColor(fromX,fromY) == 0 && yVector == 1 && (xVector == 1 || xVector -1) && getPiece(toX,toY) != 0)
                return true;
                // std::cout << "test6\n";
            else
                return false;
            break;
        case 2:
            // move Rook on X axis
            if (xVector != 0 && yVector == 0)
                return true;
            // move Rook on Y axis
            else if (yVector != 0 && xVector == 0)
                return true;
            else
                return false;
            break;
        case 3:
            // move Bishop diagonal
            if (xVector == yVector)
                return true;
            else if (-xVector == yVector)
                return true;
            else if (xVector == -yVector)
                return true;
            else if (-xVector == -yVector)
                return true;
            else
                return false;
            break;
        case 4:
            // move Knight 2 forward and one to the side
            if ((xVector == 2 || xVector == -2) && (yVector == 1 || yVector == -1))
                return true;
            else if ((yVector == 2 || yVector == -2) && (xVector == 1 || xVector == -1))
                return true;
            else
                return false;
            break;
        case 5:
            // move king one forward into every direction
            if ((yVector == 0 || yVector == 1 || yVector == -1) && (xVector == 0 || xVector == 1 || xVector == -1))
                return true;
            // TODO king shouldn't be able to go into danger
            else
                return false;
            break;
        case 6:
            // move Queen diagonal (like Bishop)
            if (xVector == yVector)
                return true;
            else if (-xVector == yVector)
                return true;
            else if (xVector == -yVector)
                return true;
            else if (-xVector == -yVector)
                return true;
            // move Queen vertical (like Rook)
            else if (xVector != 0 && yVector == 0)
                return true;
            else if (yVector != 0 && xVector == 0)
                return true;
            else
                return false;
            break;
    }
}

unsigned int chessField::movePiece(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY, bool whitesTurn)
{
    // check, if the destination is on the board (avoids a exception)
    if (toX > 7 || toY > 7)
        return 1;
    // check, if the piece exists on the given location
    else if (getPiece(fromX,fromY) == 0)
        return 2;
    // check, if the destination is the same as the location
    else if (fromX == toX && fromY == toY)
        return 3;
    // checks, if the piece has the given color
    else if (getColor(fromX, fromY) == 10 && !whitesTurn || getColor(fromX, fromY) == 0 && whitesTurn)
        return 4;
    // check, if the figure can reach the destination
    else if (!canMove(fromX, fromY, toX, toY))
        return 5;
    // checks, if the destination includes a piece of the same color
    if (getPiece(toX,toY) != 0 && (getColor(toX,toY) == 10 && whitesTurn || getColor(toX,toY) == 0 && !whitesTurn))
        return 6;
    // add the new figure
    // addPiece(toX,toY, getPiece(fromX,fromY));

    // remove the figure
    // removePiece(fromX,fromY);
    // TODO remove old piece

    // (add the new danger zones)


    return 0;
}
void chessField::removePiece(unsigned int pieceX, unsigned int pieceY)
{
    // changes the piece location to 0
    field[pieceY][pieceX] = 0;
}
void chessField::addPiece(unsigned int pieceX, unsigned int pieceY, unsigned int pieceID)
{
    // calculates the full ID
    unsigned int pieceMeta = pieceID;
    // places the new
    field[pieceY][pieceX] = pieceMeta;
}
