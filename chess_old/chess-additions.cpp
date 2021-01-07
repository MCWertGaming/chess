// includes chess additional source
// Created by MCWertGaming on 26.07.2020.
//

#include "chess.hpp"

unsigned int chess::pice::blackPawn()
{
    return 1;
}
unsigned int chess::pice::blackRook()
{
    return 2;
}
unsigned int chess::pice::blackBishop()
{
    return 3;
}
unsigned int chess::pice::blackKnight()
{
    return 4;
}
unsigned int chess::pice::blackKing()
{
    return 5;
}
unsigned int chess::pice::blackQueen()
{
    return 6;
}
unsigned int chess::pice::whitePawn()
{
    return chess::pice::blackPawn() + 10;
}
unsigned int chess::pice::whiteRook()
{
    return chess::pice::blackRook() + 10;
}
unsigned int chess::pice::whiteBishop()
{
    return chess::pice::blackBishop() + 10;
}
unsigned int chess::pice::whiteKnight()
{
    return chess::pice::blackKnight() + 10;
}
unsigned int chess::pice::whiteKing()
{
    return chess::pice::blackKing() + 10;
}
unsigned int chess::pice::whiteQueen()
{
    return chess::pice::blackQueen() + 10;
}
signed int chess::createVector(const unsigned int *from, const unsigned int *to)
{
    return *to - *from;
}
