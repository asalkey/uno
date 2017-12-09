#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

#include "cards.h"
#include "cardpiles.h"
#include "game.h"

const int PLAYER_CARDS_AMT = 7;

class Test{
private:
    Cards *testCards = new Cards;
    CardPiles *testPiles = new CardPiles;
    Game *testGame = new Game;
public:
    Test();
    ~Test();
    void testUno();
};

Test::Test(){}

Test::~Test(){
    cout << "destroying";
    delete testCards;
    delete testPiles;
    delete testGame;
}

void Test::testUno(){
    cout << "Get cards" << endl;
    testCards->getCards();
    
    cout << "How many cards? expected 92" << endl;
    testCards->cardsColour.size();
    testCards->cardsValue.size();
    
    cout << "Cards colour and value same size?" << endl;
    if(testCards->cardsColour.size() == testCards->cardsValue.size()){
        cout << "same size" << endl;
    }else{
        cout << "not the same" << endl;
    }
    
    cout << "Delete a card" << endl;
    //function to pick random card from pile
    void deleteCards(int &index);
    
    cout << "How many cards? expected 91" << endl;
    testCards->cardsColour.size();
    testCards->cardsValue.size();
    
    cout << "Cards colour and value same size?" << endl;
    if(testCards->cardsColour.size() == testCards->cardsValue.size()){
        cout << "same size" << endl;
    }else{
        cout << "not the same" << endl;
    }
    
    cout << "Divy up cards into piles" << endl;
    newGame->createPiles();
    
    cout << "How many player cards? expected 7" << endl;
    long CardPiles::playerPileAmt(){
        //check if same as colour if not throw
        return playerPileValue.size();
    }
    
    cout << "How many cards? expected 91" << endl;
    testCards->cardsColour.size();
    testCards->cardsValue.size();
    
    cout << "Cards colour and value same size?" << endl;
    if(testCards->cardsColour.size() == testCards->cardsValue.size()){
        cout << "same size" << endl;
    }else{
        cout << "not the same" << endl;
    }
    
    //how many computer cards? expected 7
    long CardPiles::computerPileAmt(){
    //are those cards removed from cards deck?
        vector<string> cardsColour;
        vector<string> cardsValue;
    //how many in discard pile? expected 1
        discardPileAmt()
    //are those cards removed from cards deck?
        vector<string> cardsColour;
        vector<string> cardsValue;
        
    // how many in draw pile? expected 82
        drawPileAmt();
        
    cout << "How many cards? expected 0" << endl;
    testCards->cardsColour.size();
    testCards->cardsValue.size();
    //random func to pick whose turn
    //random func to pick a card from players deck
    //player turn
    //computer turn
}


int main()
{
    //make dynamic
    Game uno;
    uno.playGame();
    return 0;
}
