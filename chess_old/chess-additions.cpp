// includes chess additional source
// Created by MCWertGaming on 26.07.2020.
//

#include "chess.hpp"

unsigned int chess::piece::blackPawn()
{
    return 1;
}
unsigned int chess::piece::blackRook()
{
    return 2;
}
unsigned int chess::piece::blackBishop()
{
    return 3;
}
unsigned int chess::piece::blackKnight()
{
    return 4;
}
unsigned int chess::piece::blackKing()
{
    return 5;
}
unsigned int chess::piece::blackQueen()
{
    return 6;
}
unsigned int chess::piece::whitePawn()
{
    return chess::piece::blackPawn() + 10;
}
unsigned int chess::piece::whiteRook()
{
    return chess::piece::blackRook() + 10;
}
unsigned int chess::piece::whiteBishop()
{
    return chess::piece::blackBishop() + 10;
}
unsigned int chess::piece::whiteKnight()
{
    return chess::piece::blackKnight() + 10;
}
unsigned int chess::piece::whiteKing()
{
    return chess::piece::blackKing() + 10;
}
unsigned int chess::piece::whiteQueen()
{
    return chess::piece::blackQueen() + 10;
}
signed int chess::createVector(const unsigned int *from, const unsigned int *to)
{
    return *to - *from;
}
