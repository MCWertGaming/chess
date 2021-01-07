// #include "chess.hpp"
#include "chessField.h"
#include <iostream>

class consoleFront: private chessField
{
private:
    // stuff
    chessField chf{};
public:
    consoleFront();
    ~consoleFront() = default;

    // translates the field store
    unsigned int fieldTranslate(unsigned int, unsigned int);

    void startNewGame();

    void drawField();

    void test(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY, bool white);
};

consoleFront::consoleFront() : chessField()
{
    chf.clearField();
}

unsigned int consoleFront::fieldTranslate(unsigned int fieldX, unsigned int fieldY)
{
    return 10000 + chf.getField(fieldX,fieldY);
}

void consoleFront::drawField()
{
    for (int i = 7; i >= 0; --i)
    {
        unsigned int fieldNum = i + 1;
        std::cout << fieldNum;
        for (unsigned int j = 0; j <= 7; ++j)
        {
            std::cout << " {" << fieldTranslate(i,j) << "}";
        }
        std::cout << "\n";
    }
    std::cout << "     A       B       C       D       E       F       G       H\n";
}


void consoleFront::startNewGame()
{
    chf.initializeField();
}

void consoleFront::test(unsigned int fromX, unsigned int fromY, unsigned int toX, unsigned int toY, bool white)
{
    int test = chf.movePice(fromX,fromY,toX,toY,white);
    std::cout << "return was: " << test << std::endl;
}



int main()
{
    consoleFront cf{};

    cf.drawField();
    cf.startNewGame();
    cf.drawField();
    cf.test(3,1,3,3, true); // should be true
    cf.drawField();


    // cf.test(7,1,7,2, true); // should be true
    // cf.test(7,1,7,4, true); // should be false
    // cf.test(0,0,0,1, true); // should be false
    // cf.test(0,0,3,3, true); // should be false


    return 0;
}