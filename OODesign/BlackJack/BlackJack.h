/*
 * =====================================================================================
 *
 *       Filename:  BlackJack.h
 *
 *    Description:  skeleton of the BlackJack game
 *
 *        Created:  03/07/2015 22:31:43
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

enum Suit{
    Club, Diamond, Spade, Heart;
};

class Card{
public:
    Card(int val, Suit s) : faceValue(val), Suit(suit){ }
    
    // set or get the value of the card
    int getValue();
    void setValue(const int val);

    // set or get the suit of the card
    Suit getSuit();
    void setSuit(const Suit &suit);
        
private:
    int faceValue;
    Suit suit;
};

class Deck{
public:  
    // constructor
    Deck(){  }
    
    // set a deck of cards
    void setDeckOfCards(vector<Card> &deck_of_cards){
        deck_cards = deck_of_cards;
    }

    // shuffle the cards randomly
    void shuffle(){
        random_shuffle(deck_cards.begin(), deck_cards.end()); 
    }

    // Issue a card to a specific player
    // Need first check if there is enough card
    void issueCard(Player &p);
        
private:
    vector<Card> deck_cards;
};

class Player{
public:
    Player(){}

    // get the current score
    int getScore(){
        return score_of_cards;
    }

    virtual void clear();    // clear all the cards at hand and replay
    
    virtual bool hit() = 0;  // return if the player wants to give another hit or not
    
    bool isBusted(){         // return if the player has been busted or not
        return score_of_cards > 21;
    }

private:
    int score_of_cards;
    vector<Card> hand;
};


class Dealer : class Player{
public:
    Dealer() : Player(){  }
    
    virtual void clear();
    virtual bool hit();

private:
};

class Guest : class Player{
public:
    Guest() : Player() {}
    Guest(const string &name);
    
    virtual void clear();
    virtual bool hit();

private:
    string name;
};


// The controller of the Game
class Game{
public:
    Game(){}
    void play():

private:
    Deck deck;
    Dealer dealer;
    vector<Guest> guests;
};

