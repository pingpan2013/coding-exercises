/*
 * =====================================================================================
 *
 *       Filename:  ChessGame.h
 *
 *    Description:  Design a Chess game using OOD from Cracking the code
 *
 * =====================================================================================
 */

class ChessPieceTurn{}


class GameManager{
    private: 
        void processTurn(PlayerBase *p){};
        Position curPosition;
        static GameManager *gInstance;
    
    public:
        static GameManager* getInstance(){
        }
};



class ChessPieceBase(){

}；
class King: public ChessPieceBase{};
class Queue: public ChessPieceBase{};
class Rook: public ChessPieceBase{};
class Bishop: public ChessPieceBase{};
class Pawn: public ChessPieceBase{};
class Knight: public ChessPieceBase{};



class PlayerBase{
    public:
        virtual ChessPieceTurn getTurn(Position *p); 
        virtual ~PlayerBase(){}
};
class ComputerPlayer: public PlayerBase{
    public:
        virtual ChessPieceTurn getTurn(Position *p); 
        // additional functions
        void setDifficulty();
}
class HumanPlayer: public PlayerBase{}



class Position{
    public;
        vector<vector<ChessPieceBase*> > black;
        vector<vector<ChessPieceBase*> > white;
}





