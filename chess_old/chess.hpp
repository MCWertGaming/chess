// chess header
// contains chess back-end
// by MCWertGaming

namespace chess
{
    class chessField
    {
    private:
        // stuff
        // provides the field -> field[Y][X]
        unsigned int field[8][8]{};

        /* parsing functions */

        // returns the piece identification
        unsigned int getPiece(unsigned int*, unsigned int*);
        // returns true on white pieces
        unsigned int getColor(unsigned int*, unsigned int*);
        // returns overload of a piece
        unsigned int getOverload(const unsigned int*, const unsigned int*);

        /* manipulate pieces */

        // removes piece
        void removePiece(const unsigned int*, const unsigned int*);
        // adds piece
        void addPiece(const unsigned int*, const unsigned int*, const unsigned int*);
        // returns true, if the piece can move to the destination

        /* game status checks */

        bool checkMate(unsigned int*, unsigned int*);

    public:
        chessField();
        ~chessField() = default;

        /* game manipulation */

        // creates a blank field
        void clearField();
        // places the pieces for starting the game
        void initializeField();
        // manually places a piece
        void createPiece(unsigned int, unsigned int, unsigned int pieceId);
        // move a piece
        unsigned int movePiece(unsigned int, unsigned int, unsigned int, unsigned int, bool);

        // returns the piece ID
        // TODO is this needed?
        unsigned int getField(const unsigned int*, const unsigned int*);

    private:
        /* check, if a piece can move the gives way */
        // TODO move outside the class

        // returns true, if the piece can move to the destination
        bool canMove(unsigned int*, unsigned int*, unsigned int*, unsigned int*);

        bool canPawnMove(unsigned int*, unsigned int*, unsigned int*, unsigned int*, signed int, signed int);
        bool canRookMove(unsigned int*, unsigned int*, const unsigned int*, const unsigned int*, signed int, signed int);
        bool canBishopMove(const unsigned int*, const unsigned int*, const unsigned int*, signed int, signed int);
        static bool canKnightMove(signed int, signed int);
        bool canKingMove(unsigned int*, unsigned int*, const unsigned int*, const unsigned int*, signed int, signed int);
        bool canQueenMove(unsigned int*, unsigned int*, unsigned int*, unsigned int*, signed int, signed int);

        bool kingInDanger(unsigned int, unsigned int, unsigned int);

        /* pre move checks */
        // TODO move outside the class

        // returns true, if the destination is the same as the location
        static bool checkSameLocation(const unsigned int*, const unsigned int*, const unsigned int*, const unsigned int*);
        // returns true, if the piece exists
        static bool checkPieceExists(unsigned int);
        // returns true, if the destination is on the board
        static bool onBoard(const unsigned int*, const unsigned int*, const unsigned int*, const unsigned int*);
        // returns true, if the given piece has the same color as the given
        bool checkRightColor(unsigned int);
        // returns true, if the given movement captures a piece of the same color as the capturing piece
        bool checkCaptureTeam(unsigned int*, unsigned int*, unsigned int*, unsigned int*);

    };
    // calculates Vector of two locations
    signed int createVector(const unsigned int*, const unsigned int*);

    namespace piece
    {
        unsigned int blackPawn();
        unsigned int blackRook();
        unsigned int blackBishop();
        unsigned int blackKnight();
        unsigned int blackKing();
        unsigned int blackQueen();
        unsigned int whitePawn();
        unsigned int whiteRook();
        unsigned int whiteBishop();
        unsigned int whiteKnight();
        unsigned int whiteKing();
        unsigned int whiteQueen();
    }
    namespace preMoveChecks
    {
        // TODO move checks
    }


}