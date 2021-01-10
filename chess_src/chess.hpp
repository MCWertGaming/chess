// chess header

namespace chess
{
    class chess
    {
        private:
            // stores the field, chessField[X][Y]
            unsigned short int chessField[8][8]{};

            /* parsing functions */

            // returns the pice identification
            unsigned int getPice(unsigned int*, unsigned int*);
            // returns true on white pices
            unsigned int getColor(unsigned int*, unsigned int*);
            
            /* manipulate pices */

            // removes pice
            void removePice(const unsigned int*, const unsigned int*);
            // adds pice
            void addPice(const unsigned int*, const unsigned int*, const unsigned int*);
            // returns true, if the pice can move to the destination

            /* pice move checks */

            // move checks
            bool canMove(unsigned int*, unsigned int*, unsigned int*, unsigned int*);

            bool canPawnMove(unsigned int*, unsigned int*, unsigned int*, unsigned int*, signed int, signed int);
            bool canRookMove(unsigned int*, unsigned int*, const unsigned int*, const unsigned int*, signed int, signed int);
            bool canBishopMove(const unsigned int*, const unsigned int*, const unsigned int*, signed int, signed int);
            static bool canKnightMove(signed int, signed int);
            bool canKingMove(unsigned int*, unsigned int*, const unsigned int*, const unsigned int*, signed int, signed int);
            bool canQueenMove(unsigned int*, unsigned int*, unsigned int*, unsigned int*, signed int, signed int);

            bool kingInDanger(unsigned int, unsigned int, unsigned int);

            // after move checks
            // TODO checkmate
            // TODO stalemate
            // TODO check field integrity (make optional)

        public:
            chess();
            virtual ~chess() = default;

            /* game manipulation */

            // creates a blank field
            void clearField();
            // places the pices for starting the game
            void initializeField();
            // manually places a pice
            void createPice(unsigned int, unsigned int, unsigned int piceId);
            // move a pice
            unsigned int movePice(unsigned int, unsigned int, unsigned int, unsigned int, bool);
            // returns true, if the input is valid, for unit testing only
            bool canMovePice(unsigned int, unsigned int, unsigned int, unsigned int, bool);
    };

    // pre move checks
    bool preMoveChecks(const unsigned int*, const unsigned int*, const unsigned int*, const unsigned int*, const unsigned int, const unsigned int, const bool*);

    // returns true, if the destination is the same as the location
    bool checkSameLocation(const unsigned int*, const unsigned int*, const unsigned int*, const unsigned int*);
    // returns true, if the pice exists
    bool checkPiceExists(const unsigned int*);
    // returns true, if the destination is on the board
    bool onBoard(const unsigned int*, const unsigned int*, const unsigned int*, const unsigned int*);
    // returns true, if the given pice has the same color as the given
    bool checkRightColor(const unsigned int*, const bool*);
    // returns true, if the given movement captures a pice of the same color as the capturing pice
    bool checkCaptureTeam(const unsigned int*, const bool*);

    // TODO move into FOLF
    signed int createVector(const unsigned int*, const unsigned int*);
}