/*
 * =====================================================================================
 *
 *       Filename:  battleship_game.h
 *
 *    Description:  OOD for the battleship game
 *
 *        Created:  03/08/2015 17:52:27
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#define BOARD_SIZE 10

class Ship
{
public:
    Ship(int _size) : size(_len) {}

    virtual int size();
    
private:
    int size;
};

class Submarine : class Ship {};
class AircraftCarrier : class Ship {};


class Cell
{   
public:
    Cell(int _row, int _col) : 
        rowIdx(_row), 
        colIdx(_col), 
        occupied(false),
        hitted(false)
    {  }
    
    void occupyCell();
    void hitCell();
    bool isOccupied();
    bool isHitted();

    int getRowIdx();
    int getColIdx();

private:
    int rowIdx, colIdx;
    bool occupied, hitted;
};

class Board
{
public:
    Board(){}
    
private:
    vector<BOARD_SIZE, vector<BOARD_SIZE, Cell*> > board;
};

class Player
{
public:
    Player(){}
    
    // place ship:
    // we should first detect if the given location is valid
    // then detect if there are enough free cells there
    // once placed the ship, set the status of the occupied cells
    virtual placeShip(Ship &ship, int rowIdx, int colIdx);  // place ship at a given point
    
    virtual bool guess(int rowIdx, int colIdx);             // guess the positions of the ships, handle the message to the opponent, return true if
                                                            // it hits a ship successfully
                                
    virtual bool checkBoard();                              // check board, return true if the opponent already won

private:
    Board board;
};

class ComputerPlayer : class Player {};
class HumanPlayer : class Player {};

// also need to design algorithms for the computer to guess the position intelligently
