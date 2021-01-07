//
// Created by MCWertGaming on 23.07.2020.
//

#include "chess.hpp"
#include <iostream>

int main()
{
    chess::chessField chf;

    chf.clearField();
    // try to move white pawn from the middle
    chf.createPice(3,4,11);
    if (chf.movePice(3,4,3,5, true) != 0)
        std::cout << "ERROR 1\n";
    if (chf.movePice(3,4,3,6, true) == 0)
        std::cout << "ERROR 2\n";
    if (chf.movePice(3,4,3,7, true) == 0)
        std::cout << "ERROR 3\n";
    if (chf.movePice(3,4,4,5, true) == 0)
        std::cout << "ERROR 4\n";
    if (chf.movePice(3,4,4,4, true) == 0)
        std::cout << "ERROR 5\n";
    if (chf.movePice(3,4,1,3, true) == 0)
        std::cout << "ERROR 6\n";
    if (chf.movePice(3,4,1,6, true) == 0)
        std::cout << "ERROR 7\n";
    if (chf.movePice(3,4,3,3, true) == 0)
        std::cout << "ERROR 8\n";
    // try to move white pawn from the seconds row
    chf.clearField();
    chf.createPice(3,1,11);
    if (chf.movePice(3,1,3,2, true) != 0)
        std::cout << "ERROR 9\n";
    if (chf.movePice(3,1,3,3, true) != 0)
        std::cout << "ERROR 10\n";
    if (chf.movePice(3,1,3,4, true) == 0)
        std::cout << "ERROR 11\n";
    if (chf.movePice(3,1,3,0, true) == 0)
        std::cout << "ERROR 12\n";
    if (chf.movePice(3,1,1,4, true) == 0)
        std::cout << "ERROR 13\n";
    if (chf.movePice(3,1,4,0, true) == 0)
        std::cout << "ERROR 14\n";
    if (chf.movePice(3,1,4,1, true) == 0)
        std::cout << "ERROR 15\n";
    if (chf.movePice(3,1,4,2, true) == 0)
        std::cout << "ERROR 16\n";
    if (chf.movePice(3,1,4,3, true) == 0)
        std::cout << "ERROR 17\n";
    if (chf.movePice(3,1,6,6, true) == 0)
        std::cout << "ERROR 18\n";
    if (chf.movePice(3,1,7,1, true) == 0)
        std::cout << "ERROR 19\n";

    // try to move black pawn from the middle
    chf.clearField();
    chf.createPice(3,4,1);
    if (chf.movePice(3,4,3,5, false) == 0)
        std::cout << "ERROR 20\n";
    if (chf.movePice(3,4,3,6, false) == 0)
        std::cout << "ERROR 21\n";
    if (chf.movePice(3,4,3,7, false) == 0)
        std::cout << "ERROR 22\n";
    if (chf.movePice(3,4,4,5, false) == 0)
        std::cout << "ERROR 23\n";
    if (chf.movePice(3,4,4,4, false) == 0)
        std::cout << "ERROR 24\n";
    if (chf.movePice(3,4,1,3, false) == 0)
        std::cout << "ERROR 25\n";
    if (chf.movePice(3,4,1,6, false) == 0)
        std::cout << "ERROR 26\n";
    if (chf.movePice(3,4,3,3, false) != 0)
        std::cout << "ERROR 27\n";
    // try to move black pawn from the seconds row
    chf.clearField();
    chf.createPice(3,6,1);
    if (chf.movePice(3,6,3,2, false) == 0)
        std::cout << "ERROR 28\n";
    if (chf.movePice(3,6,3,3, false) == 0)
        std::cout << "ERROR 29\n";
    if (chf.movePice(3,6,3,4, false) != 0)
        std::cout << "ERROR 30\n";
    if (chf.movePice(3,6,3,5, false) != 0)
        std::cout << "ERROR 31\n";
    if (chf.movePice(3,6,1,4, false) == 0)
        std::cout << "ERROR 32\n";
    if (chf.movePice(3,6,4,0, false) == 0)
        std::cout << "ERROR 33\n";
    if (chf.movePice(3,6,4,1, false) == 0)
        std::cout << "ERROR 34\n";
    if (chf.movePice(3,6,4,2, false) == 0)
        std::cout << "ERROR 35\n";
    if (chf.movePice(3,6,4,3, false) == 0)
        std::cout << "ERROR 36\n";
    if (chf.movePice(3,6,6,6, false) == 0)
        std::cout << "ERROR 37\n";
    if (chf.movePice(3,6,7,1, false) == 0)
        std::cout << "ERROR 38\n";


    // check, if white pawn can acess white pice
    chf.clearField();
    chf.createPice(4,1, 11);
    chf.createPice(4,2,14);
    chf.createPice(4,3,15);
    chf.createPice(3,2,4);
    chf.createPice(5,2,4);
    chf.createPice(5,3,4);
    chf.createPice(3,4,11);
    chf.createPice(3,5,14);
    chf.createPice(3,6,14);
    chf.createPice(2,5,3);
    chf.createPice(4,5,3);
    chf.createPice(6,5,11);
    chf.createPice(6,6,3);
    chf.createPice(6,7,3);
    chf.createPice(5,6,13);
    chf.createPice(7,6,13);

    if (chf.movePice(4,1,4,2, true) == 0)
        std::cout << "ERROR 39\n";
    if (chf.movePice(4,1,4,3, true) == 0)
        std::cout << "ERROR 40\n";
    if (chf.movePice(4,1,3,2, true) != 0)
        std::cout << "ERROR 41\n";
    if (chf.movePice(4,1,5,2, true) != 0)
        std::cout << "ERROR 42\n";
    if (chf.movePice(4,1,5,3, true) == 0)
        std::cout << "ERROR 43\n";
    if (chf.movePice(3,4,3,5, true) == 0)
        std::cout << "ERROR 44\n";
    if (chf.movePice(3,4,3,6, true) == 0)
        std::cout << "ERROR 45\n";
    if (chf.movePice(3,4,2,5, true) != 0)
        std::cout << "ERROR 46\n";
    if (chf.movePice(3,4,4,5, true) != 0)
        std::cout << "ERROR 47\n";
    if (chf.movePice(6,5,6,6, true) == 0)
        std::cout << "ERROR 48\n";
    if (chf.movePice(6,5,6,7, true) == 0)
        std::cout << "ERROR 49\n";
    if (chf.movePice(6,5,5,6, true) == 0)
        std::cout << "ERROR 50\n";
    if (chf.movePice(6,5,7,6, true) == 0)
        std::cout << "ERROR 51\n";

    // move non-existent pice
    chf.clearField();
    if (chf.movePice(2,2,2,3, true) == 0)
        std::cout << "ERROR 52\n";
    if (chf.movePice(3,4,5,6, false) == 0)
        std::cout << "ERROR 53\n";
    // move pice to its own location
    chf.clearField();
    chf.createPice(2,2,1);
    chf.createPice(4,4,11);
    if (chf.movePice(2,2,2,2, true) == 0)
        std::cout << "ERROR 54\n";
    if (chf.movePice(4,4,4,4,true) == 0)
        std::cout << "ERROR 55\n";
    // giving the move function literally garbage
    chf.clearField();
    if (chf.movePice(99,424,4324,42342,24) == 0)
        std::cout << "ERROR 56\n";
    if (chf.movePice(-99,432434.423434,434004555357853584,'s',"sdasdds") == 0)
        std::cout << "ERROR 56\n";
    if (chf.movePice('g',458350845909834895,4545545,'s',"sdasdds") == 0)
        std::cout << "ERROR 56\n";

    // check, if the function notices wrong color
    chf.clearField();
    chf.createPice(3,3,11);
    chf.createPice(5,5,1);
    if (chf.movePice(3,3,3,4, false) == 0)
        std::cout << "ERROR 57\n";
    if (chf.movePice(5,5,5,4, true) == 0)
        std::cout << "ERROR 58\n";

    // rook movement
    chf.clearField();
    chf.createPice(3,2,12);
    chf.createPice(5,5,2);
    chf.createPice(3,5,11);
    chf.createPice(5,2,1);

    if (chf.movePice(3,2,3,2, true) == 0)
        std::cout << "ERROR 59\n";
    if (chf.movePice(3,2,1,0, true) == 0)
        std::cout << "ERROR 60\n";
    if (chf.movePice(3,2,1,2, true) != 0)
        std::cout << "ERROR 61\n";
    if (chf.movePice(3,2,1,5, true) == 0)
        std::cout << "ERROR 62\n";
    if (chf.movePice(3,2,1,7, true) == 0)
        std::cout << "ERROR 63\n";
    if (chf.movePice(3,2,3,0, true) != 0)
        std::cout << "ERROR 64\n";
    if (chf.movePice(3,2,3,5, true) == 0)
        std::cout << "ERROR 65\n";
    if (chf.movePice(3,2,3,7, true) != 0)
        std::cout << "ERROR 66\n";
    if (chf.movePice(3,2,6,0, true) == 0)
        std::cout << "ERROR 67\n";
    if (chf.movePice(3,2,6,6, true) == 0)
        std::cout << "ERROR 68\n";
    if (chf.movePice(3,2,5,2, true) != 0)
        std::cout << "ERROR 69\n";
    if (chf.movePice(3,2,5,2, true) != 0)
        std::cout << "ERROR 70\n";

    if (chf.movePice(5,5,3,2, false) == 0)
        std::cout << "ERROR 71\n";
    if (chf.movePice(5,5,1,0, false) == 0)
        std::cout << "ERROR 72\n";
    if (chf.movePice(5,5,1,2, false) == 0)
        std::cout << "ERROR 73\n";
    if (chf.movePice(5,5,1,5, false) == 0)
        std::cout << "ERROR 74\n";
    if (chf.movePice(5,5,1,7, false) == 0)
        std::cout << "ERROR 75\n";
    if (chf.movePice(5,5,3,0, false) == 0)
        std::cout << "ERROR 76\n";
    if (chf.movePice(5,5,3,5, false) != 0)
        std::cout << "ERROR 77\n";
    if (chf.movePice(5,5,3,7, false) == 0)
        std::cout << "ERROR 78\n";
    if (chf.movePice(5,5,6,0, false) == 0)
        std::cout << "ERROR 79\n";
    if (chf.movePice(5,5,6,6, false) == 0)
        std::cout << "ERROR 80\n";
    if (chf.movePice(5,5,6,2, false) == 0)
        std::cout << "ERROR 81\n";
    if (chf.movePice(5,5,5,2, false) == 0)
        std::cout << "ERROR 82\n";
    if (chf.movePice(5,5,5,6, false) != 0)
        std::cout << "ERROR 83\n";
    if (chf.movePice(5,5,5,1, false) == 0)
        std::cout << "ERROR 84\n";
    if (chf.movePice(5,5,6,5, false) != 0)
        std::cout << "ERROR 85\n";

    // test Bishop
    chf.clearField();
    chf.createPice(3,3,13);

    if (chf.movePice(3,3,1,1, true) != 0)
        std::cout << "ERROR 86\n";
    if (chf.movePice(3,3,1,5, true) != 0)
        std::cout << "ERROR 87\n";
    if (chf.movePice(3,3,5,5, true) != 0)
        std::cout << "ERROR 88\n";
    if (chf.movePice(3,3,6,0, true) != 0)
        std::cout << "ERROR 89\n";
    if (chf.movePice(3,3,3,1, true) == 0)
        std::cout << "ERROR 90\n";
    if (chf.movePice(3,3,3,5, true) == 0)
        std::cout << "ERROR 91\n";
    if (chf.movePice(3,3,6,2, true) == 0)
        std::cout << "ERROR 92\n";
    if (chf.movePice(3,3,6,5, true) == 0)
        std::cout << "ERROR 93\n";

    // test Knight
    chf.clearField();
    chf.createPice(3,3,14);

    if (chf.movePice(3,3,1,2,true) != 0)
        std::cout << "ERROR 94\n";
    if (chf.movePice(3,3,1,4, true) != 0)
        std::cout << "ERROR 95\n";
    if (chf.movePice(3,3,2,1, true) != 0)
        std::cout << "ERROR 96\n";
    if (chf.movePice(3,3,2,5, true) != 0)
        std::cout << "ERROR 97\n";
    if (chf.movePice(3,3,4,1, true) != 0)
        std::cout << "ERROR 98\n";
    if (chf.movePice(3,3,4,5, true) != 0)
        std::cout << "ERROR 99\n";
    if (chf.movePice(3,3,5,4, true) != 0)
        std::cout << "ERROR 100\n";
    if (chf.movePice(3,3,5,2, true) != 0)
        std::cout << "ERROR 101\n";

    if (chf.movePice(3,3,0,0, true) == 0)
        std::cout << "ERROR 102\n";
    if (chf.movePice(3,3,0,5, true) == 0)
        std::cout << "ERROR 103\n";
    if (chf.movePice(3,3,1,6, true) == 0)
        std::cout << "ERROR 104\n";
    if (chf.movePice(3,3,2,4, true) == 0)
        std::cout << "ERROR 105\n";
    if (chf.movePice(3,3,3,5, true) == 0)
        std::cout << "ERROR 106\n";
    if (chf.movePice(3,3,4,3, true) == 0)
        std::cout << "ERROR 107\n";
    if (chf.movePice(3,3,5,6, true) == 0)
        std::cout << "ERROR 108\n";

    // test king
    chf.clearField();
    chf.createPice(3,3,15);

    if (chf.movePice(3,3,2,2, true) != 0)
        std::cout << "ERROR 109\n";
    if (chf.movePice(3,3,2,3, true) != 0)
        std::cout << "ERROR 110\n";
    if (chf.movePice(3,3,2,4, true) != 0)
        std::cout << "ERROR 111\n";
    if (chf.movePice(3,3,3,4, true) != 0)
        std::cout << "ERROR 112\n";
    if (chf.movePice(3,3,3,2, true) != 0)
        std::cout << "ERROR 113\n";
    if (chf.movePice(3,3,4,2, true) != 0)
        std::cout << "ERROR 114\n";
    if (chf.movePice(3,3,4,3, true) != 0)
        std::cout << "ERROR 115\n";
    if (chf.movePice(3,3,4,4, true) != 0)
        std::cout << "ERROR 116\n";

    if (chf.movePice(3,3,0,0, true) == 0)
        std::cout << "ERROR 117\n";
    if (chf.movePice(3,3,0,3, true) == 0)
        std::cout << "ERROR 118\n";
    if (chf.movePice(3,3,2,0, true) == 0)
        std::cout << "ERROR 119\n";
    if (chf.movePice(3,3,2,5, true) == 0)
        std::cout << "ERROR 120\n";
    if (chf.movePice(3,3,3,5, true) == 0)
        std::cout << "ERROR 121\n";
    if (chf.movePice(3,3,5,7, true) == 0)
        std::cout << "ERROR 122\n";
    if (chf.movePice(3,3,6,1, true) == 0)
        std::cout << "ERROR 123\n";
    if (chf.movePice(3,3,7,6, true) == 0)
        std::cout << "ERROR 124\n";

    // test Queen
    chf.clearField();
    chf.createPice(3,3,16);

    if (chf.movePice(3,3,1,1, true) != 0)
        std::cout << "ERROR 125\n";
    if (chf.movePice(3,3,1,5, true) != 0)
        std::cout << "ERROR 126\n";
    if (chf.movePice(3,3,2,3, true) != 0)
        std::cout << "ERROR 127\n";
    if (chf.movePice(3,3,3,5, true) != 0)
        std::cout << "ERROR 128\n";
    if (chf.movePice(3,3,6,0, true) != 0)
        std::cout << "ERROR 129\n";

    if (chf.movePice(3,3,0,2, true) == 0)
        std::cout << "ERROR 130\n";
    if (chf.movePice(3,3,1,6, true) == 0)
        std::cout << "ERROR 131\n";
    if (chf.movePice(3,3,1,7, true) == 0)
        std::cout << "ERROR 132\n";
    if (chf.movePice(3,3,4,5, true) == 0)
        std::cout << "ERROR 133\n";
    if (chf.movePice(3,3,7,0, true) == 0)
        std::cout << "ERROR 134\n";
    if (chf.movePice(3,3,7,3, true) != 0)
        std::cout << "ERROR 135\n";

    // check, if the king can go into danger
    chf.clearField();
    chf.createPice(3,3,15);
    chf.createPice(2,6,2);

    if (chf.movePice(3,3,2,2, true) == 0)
        std::cout << "ERROR 136\n";
    if (chf.movePice(3,3,2,3, true) == 0)
        std::cout << "ERROR 137\n";
    if (chf.movePice(3,3,2,4, true) == 0)
        std::cout << "ERROR 138\n";
    if (chf.movePice(3,3,3,4, true) != 0)
        std::cout << "ERROR 139\n";
    if (chf.movePice(3,3,3,2, true) != 0)
        std::cout << "ERROR 140\n";

    // check, if a Pawn can go through another pice on a double step
    chf.clearField();
    chf.createPice(3,6,1);
    chf.createPice(3,1,11);
    chf.createPice(3,5,1);
    chf.createPice(3,2,1);

    if (chf.movePice(3,6,3,4, false) == 0)
        std::cout << "ERROR 141\n";
    if (chf.movePice(3,1,3,3, false) == 0)
        std::cout << "ERROR 142\n";

    // check, if Bishop can go through other pices
    chf.clearField();
    chf.createPice(3,4,13);
    chf.createPice(1,2,11);
    chf.createPice(2,5,1);
    chf.createPice(5,6,1);
    chf.createPice(5,2,1);

    if (chf.movePice(3,4,1,6, true) == 0)
        std::cout << "ERROR 143\n";
    if (chf.movePice(3,4,0,7, true) == 0)
        std::cout << "ERROR 144\n";
     if (chf.movePice(3,4,0,1, true) == 0)
        std::cout << "ERROR 145\n";
    if (chf.movePice(3,4,4,5, true) != 0)
        std::cout << "ERROR 146\n";
    if (chf.movePice(3,4,6,7, true) == 0)
        std::cout << "ERROR 147\n";
    if (chf.movePice(3,4,6,1, true) == 0)
        std::cout << "ERROR 148\n";
    if (chf.movePice(3,4,7,0, true) == 0)
        std::cout << "ERROR 149\n";




    return 0;
}